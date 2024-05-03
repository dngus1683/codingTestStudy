// 바이러스
// 1번 컴퓨터가 바이러스에 걸렸다. 네트워크 상 연결되어 있는 모든 컴퓨터는 바이러스에 감염된다고 할 때, 1변에 의해 감염된 컴퓨터 수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_V 101

using namespace std;

vector<int> graph[MAX_V];
bool visited[MAX_V] = {false,};

void dfs(int x)
{
	if (visited[x]) return ;
	visited[x] = true;
	for (auto next : graph[x])
	{
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V, E, ans = 0;

	cin >> V;
	cin >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= V; i++)
	{
		if (visited[i]) ans++;
	}

	cout << ans << '\n';
}