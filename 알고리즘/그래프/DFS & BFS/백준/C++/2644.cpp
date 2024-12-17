// 촌수계산
// 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하라.


// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
int a = 0;
int b = 0;
vector<int> graph[101];
bool visited[101];

void dfs(int now, int cnt)
{
	visited[now] = true;

	for (auto next : graph[now])
	{
		if (next == b)
		{
			visited[next] = true;
			cout << cnt + 1 << '\n';
			return;
		}
		if (!visited[next])
		{
			dfs(next, cnt + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> a >> b;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int p = 0;
		int c = 0;

		cin >> p >> c;

		graph[p].push_back(c);
		graph[c].push_back(p);
	}

	dfs(a, 0);
	if (!visited[b])
	{
		cout << -1 << '\n';
	}
}