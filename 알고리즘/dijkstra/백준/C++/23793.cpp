// 두 단계 최단 경로1
// 정점과 가중치가 주어질 때, 출발점 -> 경유점 -> 도착점 까지 최단 경로와 출발점 -> 도착점 까지 최단 경로를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 2e9+9
#define MAX_N 100001
#define MAX_M 200001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];

void dijkstra(int start, int y, int flag)
{
	fill(d, d + MAX_N, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = d[now] + graph[now][i].second;
			if (d[graph[now][i].first] > cost && !(graph[now][i].first == y && flag))
			{
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, y, z;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	cin >> x >> y >> z;

	int xy, yz, xz;
	dijkstra(x, 0, 0);
	xy = d[y];
	dijkstra(y, 0, 0);
	yz = d[z];
	dijkstra(x, y, 1);
	xz = d[z];

	cout << ((xy >= INF) || (yz >= INF) ? -1 : xy + yz) << ' ' << (xz >= INF ? -1 : xz) << '\n';
}