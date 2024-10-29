// 선수과목
// N개의 과목에 대한 M개의 선수 조건이 주어진다. 한 학기에는 제한없이 수강할 수 있을 때, 1~N 과목이 각각 최소 몇 학기에 이수할 수 있는지 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1001
#define MAX_M 500'001

using namespace std;

int N = 0;
int M = 0;
int dp[MAX_N];
vector<int> graph[MAX_N];

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int dfs(int now)
{
	if (graph[now].empty())
	{
		dp[now] = 1;
	}
	for (auto next : graph[now])
	{
		if (dp[next] > 0)
		{
			dp[now] = max(dp[now], dp[next] + 1);
		}
		else
		{
			dp[now] = max(dp[now], dfs(next) + 1);
		}
	}

	return dp[now];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A = 0;
		int B = 0;

		cin >> A >> B;
		graph[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		if (dp[i] == 0)
		{
			dfs(i);
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << ' ';
	}
	cout << endl;

}