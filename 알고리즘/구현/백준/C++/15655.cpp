// N과 M (6)
// N개의 자연수와 자연수 M이 주어졌을 때, N개의 자연수 중에서 M개를 고른 오름차순 수열을 모두 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NM 8

using namespace std;

int N = 0;
int M = 0;
vector<int> arr;

void backtracking(int start, int cnt, vector<int>& picked)
{
	if (cnt == M)
	{
		for (auto num : picked)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < N; i++)
	{
		picked.push_back(arr[i]);
		backtracking(i + 1, cnt + 1, picked);
		picked.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	vector<int> picked;

	backtracking(0, 0, picked);
}