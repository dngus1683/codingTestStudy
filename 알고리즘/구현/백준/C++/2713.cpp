// 규현이의 사랑을 담은 문자메세지
// 문자열을 하나의 암호로 바꾸려고 한다.
// 문자열은 공백과 대문자로 이루어져 있다.
// 문자를 10진수 숫자로 변환 후, 그것을 5자리 2진수로 변환. 마지막으로 R x C 크기의 행렬에 소용돌이 패턴으로 배치한 후 행 우선방식으로 행렬을 읽는다.



// 내 답안1
#include <iostream>
#include <string>
#include <stack>

#define MAX_T 1001
#define MAX_RC 22

using namespace std;

int T = 0;
int R = 0;
int C = 0;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
string S = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> R >> C;
		cin.ignore();
		getline(cin, S);

		int nowR = 0;
		int nowC = 0;
		int dir = 0;
		char mat[MAX_RC][MAX_RC] = { 0, };

		for (char c : S)
		{
			int num = c - 'A' + 1;
			stack<char> st;

			if (c == ' ')
			{
				num = 0;
			}

			while (num > 1)
			{
				st.push('0' + num % 2);
				num /= 2;
			}
			st.push('0' + num % 2);

			int size = st.size();
			for (int i = 0; i < 5 - size; i++)
			{
				st.push('0');
			}
			while (!st.empty())
			{
				mat[nowR][nowC] = st.top();
				st.pop();

				if (nowR + dr[dir] >= R || nowR + dr[dir] < 0 || nowC + dc[dir] >= C || nowC + dc[dir] < 0 || mat[nowR + dr[dir]][nowC + dc[dir]] == '0' || mat[nowR + dr[dir]][nowC + dc[dir]] == '1')
				{
					dir = (dir + 1) % 4;
				}
				nowR = nowR + dr[dir];
				nowC = nowC + dc[dir];
			}
		}

		while (mat[nowR][nowC] != '0' && mat[nowR][nowC] != '1')
		{
			mat[nowR][nowC] = '0';

			if (nowR + dr[dir] >= R || nowR + dr[dir] < 0 || nowC + dc[dir] >= C || nowC + dc[dir] < 0 || mat[nowR + dr[dir]][nowC + dc[dir]] == '0' || mat[nowR + dr[dir]][nowC + dc[dir]] == '1')
			{
				dir = (dir + 1) % 4;
			}

			nowR = nowR + dr[dir];
			nowC = nowC + dc[dir];
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << mat[i][j];
			}
		}
		cout << '\n';
	}
}




// 답안 예시1 - https://www.acmicpc.net/source/67308556
// bitset<>() 함수를 활용해서 간단하게 2진법으로 구현.
/*
#include <bits/stdc++.h>
using namespace std;

string toBin(char c) {
	int n = (c == ' ') ? 0 : (c - 'A' + 1);
	return bitset<5>(n).to_string();
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	vector<int> di = {0, 1, 0, -1};
	vector<int> dj = {1, 0, -1, 0};

	int t;
	cin >> t;

	while (t--) {
		int h, w;
		cin >> h >> w;

		string st, res = "";
		cin.ignore();
		getline(cin, st);

		for (char &c : st) res += toBin(c);
		while (res.size() < h * w) res += '0';

		int i = 0, j = 0, dir = 0;
		vector<int> lens = {w - 1};
		int th = h, tw = w;
		while (true) {
			if (--th == 0) break;
			lens.push_back(th);
			if (--tw == 0) break;
			lens.push_back(tw);
		}

		vector<vector<char> > ans(h, vector<char>(w));
		int idx = 0;

		ans[i][j] = res[idx++];
		for (int &len : lens) {
			for (int k = 0; k < len; k++) {
				i += di[dir];
				j += dj[dir];
				ans[i][j] = res[idx++];
			}
			dir = (dir + 1) % 4;
		}

		for (auto &r : ans) {
			for (auto &e : r) cout << e;
		}
		cout << "\n";
	}

	return 0;
}
*/