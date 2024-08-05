// 행렬 곱셈 순서
// 행렬 곱셈 시, 같은 곱셈이라도 계산 순서에 따라 원소 곱셈 연산의 수가 달라진다.
// N개의 행렬이 주어질 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 501
#define INF 0b1111111111111111111111111111111-1

using namespace std;

int dp[MAX_N][MAX_N];
vector<int> mats;

inline int min(const int& a, const int& b)
{
	return (a < b ? a : b);
}

int backtracking(int start, int end)
{
	int answer = INF;
	if (dp[start][end] != INF) return dp[start][end];
	if (end - start == 2)
	{
		dp[start][end] = mats[start] * mats[start + 1] * mats[end];
		return dp[start][end];
	}
	else if (end - start == 1)
	{
		return 0;
	}
	for (int i = start+1; i < end; i++)
	{
		answer = min(answer, mats[start] * mats[i] * mats[end] + backtracking(start, i) + backtracking(i, end));
	}

	dp[start][end] = answer;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int r = 0;
	int c = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> c;
		mats.push_back(r);
	}
	mats.push_back(c);

	fill(&dp[0][0], &dp[MAX_N - 1][MAX_N], INF);
	
	cout << backtracking(0, N) << endl;

}