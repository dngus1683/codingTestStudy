// 최소 스패닝 트리
// 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
// 최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.


// 내 답안1
// 크루스칼 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_V 10001
#define MAX_E 100001

using namespace std;

typedef struct node
{
	int a;
	int b;
	int cost;
};

bool compare(node a, node b)
{
	return a.cost < b.cost;
}

vector<node> graph;
int parent[MAX_V];
int ans = 0;



int find_parent(int x)
{
	if (parent[x] != x)
		parent[x] = find_parent(parent[x]);
	return parent[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int v, e;

	cin >> v >> e;

	for (int i = 0; i <= v; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < e; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		graph.push_back({ a, b, c });
	}

	sort(graph.begin(), graph.end(), compare);

	for (node nd : graph)
	{
		if (find_parent(nd.a) != find_parent(nd.b))
		{
			union_parent(nd.a, nd.b);
			ans += nd.cost;
		}
	}


	cout << ans << '\n';
}



// 내 답안2
// 프림 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_V 10001
#define MAX_E 100001
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[MAX_V];
bool visited[MAX_V];
int d[MAX_V];
int ans = 0;

void prim(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (visited[now]) continue;
		visited[now] = true;
		ans += dist;
		
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int cost = graph[now][i].second;
			if (!visited[next] && cost < d[next])
			{
				d[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int v, e;

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	fill(d, d + MAX_V, INF);

	prim(1);

	cout << ans << '\n';
}
