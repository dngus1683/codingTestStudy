// ACM Craft
// RTS 게임에서, N개의 건물과, 각 건물의 생산트리, 각 건물이 지어지는 시간이 주어진다. 목표 건물이 주어질 때, 해당 건물이 완성되는 최소 시간을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'001
#define MAX_K 100'001

using namespace std;

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int dfs(int now, vector<int>* graph, int* delay, bool* visited, int* dp)
{
	int mx = 0;
	for (auto next : graph[now])
	{
		if (visited[next] == false)
		{
			visited[next] = true;
			mx = max(mx, dfs(next, graph, delay, visited, dp));
		}
		else
		{
			mx = max(mx, dp[next]);
		}
	}
	dp[now] = mx + delay[now];
	return dp[now];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int N = 0;
		int K = 0;
		int W = 0;
		int delay[MAX_N] = { 0, };
		int dp[MAX_N] = { 0, };
		bool visited[MAX_N] = { false, };
		vector<int> graph[MAX_N];

		cin >> N >> K;;
		for (int i = 1; i <= N; i++)
		{
			cin >> delay[i];
		}
		for (int i = 0; i < K; i++)
		{
			int a = 0;
			int b = 0;

			cin >> a >> b;
			graph[b].push_back(a);
		}
		cin >> W;

		cout << dfs(W, graph, delay, visited, dp) << '\n';
	}
}