// 웜홀
// N개의 지점이 있고 M개의 도로와 W개의 웜홀이 주어진다. 도로를 지나가면 시간이 흐르고, 웜홀을 지나가면 시간이 역행한다.
// 시작점에서 출발하여 다시 시작점으로 왔을 때, 출발했을 때보다 시간이 되돌아가 있는 경우가 있는지를 구하라.


// 내 답안1
// 다익스트라 알고리즘
/* 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_N 501
#define MAX_M 2501
#define MAX_W 201

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];
int cnt[MAX_N];

bool dijkstra(int start, int N)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < 0 && now == start)
		{
			return true;
		}
		if (cnt[now] > N)
		{
			return true;
		}
		else
		{
			cnt[now] += 1;
		}
		for (auto const next : graph[now])
		{
			int cost = d[now] + next.second;
			if (d[next.first] > cost)
			{
				d[next.first] = cost;
				pq.push({ -cost, next.first });
			}
		}
	}

	if (d[start] < 0)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC = 0;

	cin >> TC;
	while (TC--)
	{
		int N = 0;
		int M = 0;
		int W = 0;
		for (int i = 0; i < MAX_N; i++)
			graph[i].clear();

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++)
		{
			int a = 0;
			int b = 0;
			int c = 0;

			cin >> a >> b >> c;
			graph[a].push_back({ b, c });
			graph[b].push_back({ a, c });
		}
		for (int i = 0; i < W; i++)
		{
			int a = 0;
			int b = 0;
			int c = 0;

			cin >> a >> b >> c;
			graph[a].push_back({ b, -c });
		}

		bool flag = false;
		for (int i = 1; i <= N; i++)
		{
			fill(d, d + N, INF);
			fill(cnt, cnt + N, 0);
			if (dijkstra(i,N))
			{
				flag = true;
			}
		}
		if(flag)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
*/


// 내 답안2
// 벨만 포드 알고리즘.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_N 501
#define MAX_M 2501
#define MAX_W 201

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];

bool BellmanFord(int start, int N)
{
	d[start] = 0;
	for (int i = 1; i < N; i++)
	{
		for (int now = 1; now <= N; now++)
		{
			for (auto next : graph[now])
			{
				int cost = d[now] + next.second;
				if (d[next.first] > cost)
				{
					d[next.first] = cost;
				}
			}
		}
	}

	for (int now = 1; now <= N; now++)
	{
		for (auto next : graph[now])
		{
			int cost = d[now] + next.second;
			if (d[next.first] > cost)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC = 0;

	cin >> TC;
	while (TC--)
	{
		int N = 0;
		int M = 0;
		int W = 0;
		for (int i = 0; i < MAX_N; i++)
			graph[i].clear();

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++)
		{
			int a = 0;
			int b = 0;
			int c = 0;

			cin >> a >> b >> c;
			graph[a].push_back({ b, c });
			graph[b].push_back({ a, c });
		}
		for (int i = 0; i < W; i++)
		{
			int a = 0;
			int b = 0;
			int c = 0;

			cin >> a >> b >> c;
			graph[a].push_back({ b, -c });
		}

		fill(d, d + N, INF);
		if (BellmanFord(1, N))
		{
			cout << "NO" << '\n';
		}
		else
			cout << "YES" << '\n';
	}

}