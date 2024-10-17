// N과 M (1)
// 자연수 N과 M이 주어졌을 때, 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> arr;
bool picked[9];

void backtracking(int now, vector<int>& vec, int cnt)
{
	if (cnt == M)
	{
		for (auto num : vec)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (picked[i]) continue;
		vec.push_back(arr[i]);
		picked[i] = true;
		backtracking(i, vec, cnt + 1);
		vec.pop_back();
		picked[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		arr.push_back(i);
	}

	vector<int> vec;

	backtracking(0, vec, 0);
}