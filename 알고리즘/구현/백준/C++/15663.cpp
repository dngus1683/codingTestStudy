// 내 답안1
// N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
// + N개의 자연수 중에서 M개를 고른 수열


// 내 답안1
/*
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 9

using namespace std;

int N = 0;
int M = 0;
vector<int> NumArr;
bool picked[MAX_N];

void permutation(vector<int>& pick, int count)
{
	if (count == 0)
	{
		for (int i = 0; i < M; i++)
			cout << pick[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (picked[i]) continue;
			if (i > 0 && NumArr[i - 1] == NumArr[i] && picked[i-1] == false) continue;
			pick.push_back(NumArr[i]);
			picked[i] = true;
			permutation(pick, count - 1);
			pick.pop_back();
			picked[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> pick;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		NumArr.push_back(num);
	}

	sort(NumArr.begin(), NumArr.end());

	permutation(pick, M);
}
*/



// 내 답안2
// C++ <algorithm>에 포함된 next_permutation 함수 사용
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX_N 9

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	string tmp = "";
	vector<int> NumArr;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		NumArr.push_back(num);
	}
	sort(NumArr.begin(), NumArr.end());
	do
	{
		string s = "";
		for (int i = 0; i < M; i++)
		{
			s += to_string(NumArr[i]) + ' ';
		}
		if (tmp != s)
		{
			cout << s << '\n';
			tmp = s;
		}
	} while (next_permutation(NumArr.begin(), NumArr.end()));
}