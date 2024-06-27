// 트리의 부모 찾기
// 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <map>

#define MAX_N 100'001

using namespace std;

int N = 0;
map<int, vector<int>> graph;

void dfs(int x, int par, int parent[])
{	
	parent[x] = par;
	for (const auto next : graph[x])
	{
		if (parent[next] == next && next != 1)
			dfs(next, x, parent);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int parent[MAX_N];

	cin >> N;

	for (int i = 0; i < N-1; ++i)
	{
		int a = 0; 
		int b = 0;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	dfs(1, 1, parent);
	for (int i = 2; i <= N; ++i)
	{
		cout << parent[i] << '\n';
	}

}