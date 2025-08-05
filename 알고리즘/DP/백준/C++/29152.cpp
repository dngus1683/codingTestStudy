// 디지털 트윈
// N x N 크기의 공장 지도가 주어진다. 해당 지도에는 생산 기계의 위치가 1로 표시된다.
// (좌, 우, 아래) 방향으로 컨베이어 벨트를 설치가능하다.
// 컨베이어 벨트는 (1,1)에서 (N, N)으로 연결되어야 한다.
// 모든 생산 기계를 지나도록 하는 컨베이어 벨트 개수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 5'001
#define INF 987654321

using namespace std;

int N = 0;
vector<vector<int>> edge(MAX_N, vector<int>(2, 0));
vector<vector<int>> dp(MAX_N, vector<int>(2, INF));

int distance(int ai, int aj, int bi, int bj)
{
	return (abs(ai - bi) + abs(aj - bj));
}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	edge[1][0] = 1;
	edge[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char c = ' ';

			cin >> c;
			if (c == '1')
			{
				if (edge[i][0] == 0)
				{
					edge[i][0] = j;
				}
				edge[i][1] = j;
			}
		}
	}

	int preI = 1;
	

	edge[N][1] = N;
	if (edge[N][0] == 0) edge[N][0] = N;

	dp[1][0] = 1;

	for (int i = 2; i <= N; i++)
	{
		int lStart = dp[preI][1] + abs(edge[preI][1] - edge[preI][0]);
		int rStart = dp[preI][0] + abs(edge[preI][1] - edge[preI][0]);

		if (edge[i][0] == 0 && edge[i][1] == 0) continue;

		if (preI == i-1 && edge[preI][1] > edge[i][0])
		{
			dp[i][0] = min(dp[i][0], lStart + distance(i, edge[i][0], preI, edge[preI][0]));
		}
		else
		{
			dp[i][0] = min(dp[i][0], min(lStart + distance(i, edge[i][0], preI, edge[preI][0]), rStart + distance(i, edge[i][0], preI, edge[preI][1])));
		}

		if (preI == i-1 && edge[preI][0] < edge[i][1])
		{
			dp[i][1] = min(dp[i][1], rStart + distance(i, edge[i][1], preI, edge[preI][1]));

		}
		else
		{
			dp[i][1] = min(dp[i][1], min(lStart + distance(i, edge[i][1], preI, edge[preI][0]), rStart + distance(i, edge[i][1], preI, edge[preI][1])));

		}

		preI = i;
	}

	if (edge[N][0] != 0)
	{
		dp[N][1] = dp[N][0] + abs(edge[N][0] - edge[N][1]);
	}

	if (dp[N][1] < INF)
	{
		cout << dp[N][1] << '\n';
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}