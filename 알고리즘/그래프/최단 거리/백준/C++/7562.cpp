// 나이트의 이동
// 나이트의 현 위치와 목표 위치가 주어진다. 이때 목표 위치에 도달하는 최소 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX_N 301
#define INF 987654321

using namespace std;

int answer = INF;
int length = 0;
int startI = 0, startJ = 0;
int endI = 0, endJ = 0;
int dp[MAX_N][MAX_N] = { 0, };
int di[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct pqType
{
	int dist;
	int i;
	int j;

	bool operator < (const pqType& a) const
	{
		return dist > a.dist;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;
	while (T--)
	{
		cin >> length;
		cin >> startI >> startJ;
		cin >> endI >> endJ;

		fill(&dp[0][0], &dp[length - 1][length], INF);

		priority_queue<pqType> pq;
		pq.push({ 0, startI, startJ });
		dp[startI][startJ] = 0;

		while (!pq.empty())
		{
			int nowI = pq.top().i;
			int nowJ = pq.top().j;
			int dist = pq.top().dist;
			pq.pop();

			if (dp[nowI][nowJ] < dist) continue;

			for (int d = 0; d < 8; d++)
			{
				int nextI = nowI + di[d];
				int nextJ = nowJ + dj[d];
				int cost = dp[nowI][nowJ] + 1;
				if (nextI >= 0 && nextI < length && nextJ >= 0 && nextJ < length)
				{
					if (dp[nextI][nextJ] > cost)
					{
						dp[nextI][nextJ] = cost;
						pq.push({ cost, nextI, nextJ });
					}
				}
			}
		}
		cout << dp[endI][endJ] << endl;
	}
}