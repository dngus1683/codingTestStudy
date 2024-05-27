// N과 M (8)
// N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.N개의 자연수는 모두 다른 수이다.
// + N개의 자연수 중에서 M개를 고른 수열
// + 같은 수를 여러 번 골라도 된다.
// + 고른 수열은 비내림차순이어야 한다.
// + + 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK - 1 ≤ AK를 만족하면, 비내림차순이라고 한다.


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
		for (int i = 0; i < M; ++i)
		{
			cout << pick[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = start; i < N; ++i)
		{
			pick.push_back(arr[i]);
			combination(i, pick, count - 1);
			pick.pop_back();
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
		int a = 0;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	combination(0, pick, M);
}