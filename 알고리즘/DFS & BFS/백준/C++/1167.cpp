// 트리의 지름
// 트리의 지름은 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리가 주어질 때, 트리의 지름을 구하라.


// 내 답안1
// dfs
// 트리의 지름을 구하는 방법: 일단 아무 정점으로 dfs 계산. 이때, 가장 끝에 있는 정점을 시작점으로 하고 다시 dfs. 이때 가장 긴 경우가 지름이다.
#include <iostream>
#include <vector>
#include <string.h>

#define MAX_V 100'001

using namespace std;

vector<pair<int, int>> graph[MAX_V];
int visited[MAX_V];
int d[MAX_V];

static inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

pair<int, int> dfs(int x)
{
	int ans = 0;
	int tmp = 0;
	int idx = x;

	visited[x] = 1;

	for (auto const next : graph[x])
	{
		if (!visited[next.first])
		{
			pair<int, int> tmp = dfs(next.first);
			
			if (ans < tmp.second + next.second)
			{
				ans = tmp.second + next.second;
				idx = tmp.first;
			}
		}
	}

	return { idx, ans };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V = 0;
	int start = 0;
	int StartW = 0;
	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int a = 0;
		int b = 0;
		int c = 0;

		cin >> a;
		while (true)
		{
			cin >> b;

			if (b == -1) break;
			cin >> c;

			if (StartW < c)
			{
				StartW = c;
				start = a;
			}
			graph[a].push_back({ b, c });
		}
	}
	int idx = dfs(1).first;

	memset(visited, 0, sizeof(int) * V + 1);
	cout << dfs(idx).second << '\n';
}