// 연결 요소의 개수
// 무방향 그래프가 주어질 때, 연결 요소의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1001

using namespace std;

vector<int> graph[MAX_N];
bool visited[MAX_N];

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int e, v, ans = 0;

	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	for (int i = 1; i <= v; i++)
	{
		if (!visited[i])
		{
			ans++;
			bfs(i);
		}
	}

	cout << ans << '\n';

}