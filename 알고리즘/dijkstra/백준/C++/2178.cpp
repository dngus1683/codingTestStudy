// 미로 탐색
// N x M 크기의 미로가 주어지고, 이동할 수 있는 칸은 1, 없는 칸은 0으로 주어질 때, (1,1)에서 (N,M)까지 이동할 때 지나야 하는 최소 칸 수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 101
#define INF 987654321

using namespace std;

typedef struct Point
{
	int n = 0;
	int m = 0;
	int dist = 0;

	bool operator < (const Point& a) const
	{
		return dist > a.dist;
	}
}Point;

char graph[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int dn[4] = { -1, 1, 0, 0 };
int dm[4] = { 0, 0, -1, 1 };
int N = 0;
int M = 0;

void dijkstra(int StartN, int StartM)
{
	priority_queue<Point> pq;
	pq.push({StartN, StartM, 0 });

	d[StartN][StartM] = 1;

	while (!pq.empty())
	{
		int NowN = pq.top().n;
		int NowM = pq.top().m;
		int dist = pq.top().dist;
		pq.pop();

		if (d[NowN][NowM] < dist) continue;
		for (int i = 0; i < 4; i++)
		{
			bool IsOutOfBoundary = NowN + dn[i] < 0 || NowN + dn[i] >= N || NowM + dm[i] < 0 || NowM + dm[i] >= M;
			bool IsZeroAboutNextState = graph[NowN + dn[i]][NowM + dm[i]] == '0';
			if (IsOutOfBoundary || IsZeroAboutNextState)
				continue;

			int cost = d[NowN][NowM] + 1;
			if (d[NowN + dn[i]][NowM + dm[i]] > cost)
			{
				d[NowN + dn[i]][NowM + dm[i]] = cost;
				pq.push({ NowN + dn[i], NowM + dm[i], cost });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> graph[i];
	}

	fill(&d[0][0], &d[N - 1][M], INF);

	dijkstra(0, 0);

	cout << d[N - 1][M - 1] << '\n';
}