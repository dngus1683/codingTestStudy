// 최소비용 구하기 2
// n개의 도시와 m개의 버스가 있다. A에서 출발하여 B까지 가는데 드는 버스 비용을 최소화 할 때, 최소비용과 경로를 출력하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321
#define MAX_N 1'001
#define MAX_M 100'000

using namespace std;

vector<pair<int, int>> graph[MAX_N];
pair<int, int> path[MAX_N];
int PathArr[MAX_N];
int d[MAX_N];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (const auto next : graph[now])
		{
			int cost = d[now] + next.second;
			if (d[next.first] > cost)
			{
				path[next.first].first = path[now].first + 1;
				path[next.first].second = now;
				d[next.first] = cost;
				pq.push({ -cost, next.first });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int S = 0;
	int E = 0;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;
		int c = 0;

		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	cin >> S >> E;

	fill(d, d + MAX_N, INF);

	dijkstra(S);

	int idx = E;
	PathArr[path[E].first] = E;
	for (int i = path[E].first-1; i >= 0; i--)
	{
		PathArr[i] = path[idx].second;
		idx = path[idx].second;
	}

	cout << d[E] << '\n';
	cout << path[E].first + 1<< '\n';
	for (int i = 0; i < path[E].first + 1; i++)
	{
		cout << PathArr[i] << ' ';
	}
	cout << '\n';
}