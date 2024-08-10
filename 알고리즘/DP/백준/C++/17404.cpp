// 


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 1001
#define INF 987654321

using namespace std;

int N = 0;
int rgb[MAX_N][3];
int direction[3][2] = { {1, 2}, {2, 0}, {1, 0} };

inline int min(const int& a, const int& b)
{
	return (a > b ? b : a);
}

int dfs(int start, int now, int idx, int dp[][3])
{
	for (auto next : direction[now])
	{
		if (idx == N - 2 && next == start) continue;
		if (dp[idx + 1][next] == INF)
		{
			dp[idx][now] = min(dp[idx][now], dfs(start, next, idx + 1, dp) + rgb[idx][now]);
		}
		else
		{
			dp[idx][now] = min(dp[idx][now], dp[idx + 1][next] + rgb[idx][now]);
		}
	}
	return dp[idx][now];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	int answer = INF;
	for (int i = 0; i < 3; i++)
	{
		int dp[MAX_N][3];
		
		fill(&dp[0][0], &dp[N - 1][3], INF);
		dp[N - 1][0] = rgb[N - 1][0];
		dp[N - 1][1] = rgb[N - 1][1];
		dp[N - 1][2] = rgb[N - 1][2];

		answer = min(dfs(i, i, 0, dp), answer);
	}
	cout << answer << endl;

}