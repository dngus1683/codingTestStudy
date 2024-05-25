// N과 M (5)
// N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.N개의 자연수는 모두 다른 수이다.
// + N개의 자연수 중에서 M개를 고른 수열


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 9

using namespace std;

int N = 0;
int M = 0;
vector<int> arr;

void combination(int start, vector<int>& pick, int count)
{
	if (count == 0)
	{
		for (int i = 0; i < M - 1; ++i)
		{
			cout << pick[i] << ' ';
		}
		cout << pick[M - 1] << '\n';
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			int flag = 0;
			for (int j = 0; j < M-count; ++j)
			{
				if (arr[i] == pick[j])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				pick.push_back(arr[i]);
				combination(i, pick, count - 1);
				pick.pop_back();
				flag = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> pick;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int num = 0;

		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	combination(-1, pick, M);
}








// 답안 예시1 - https://www.acmicpc.net/source/59894267
// 해당 원소가 그 조합에 이미 포함되어 있는지에 대한 확인을, push -> 재귀함수 -> pop 하는 것 처럼, 포함 여부에 대한 bool값을 true -> 재귀함수 -> false로 하여 내 답안1과 같이 반복문을 사용하지 않았다.
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
#include <fstream>
#define MAX_NUM 10000
#define INF 99999999
using namespace std;

int n, m;
vector<int> arr;
bool Select[8];
int num[8];
string result;
void comb() {
	if (arr.size() == m) {
		for (int i = 0; i < m; i++) result += to_string(arr[i]) + " ";
		result += "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (Select[i])continue;
		Select[i] = true;
		arr.push_back(num[i]);
		comb();
		arr.pop_back();
		Select[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> num[i];
	sort(num, num + n);
	comb();
	cout << result;

}
*/