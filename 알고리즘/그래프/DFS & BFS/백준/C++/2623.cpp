// 음악프로그램
// N명의 보조 PD가 임의의 가수들의 출연 순서를 정하였다. 이들의 순서를 모두 만족하는 전체 출연 순서를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'001
#define MAX_M 101

using namespace std;

int N = 0;
int M = 0;
bool IsCircle = false;
int dp[MAX_N];
vector<int> answer[MAX_N];
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
		if (dp[next] != 0)
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

bool CheckCircle(int now, int start, bool visited[])
{
	visited[now] = true;

	bool output = false;

	for (auto next : graph[now])
	{
		if (next == start)
		{
			output = true;
			break;
		}
		else if(!visited[next])
		{
			output = CheckCircle(next, start, visited);
			if (output) break;
		}
		else if (visited[next])
		{
			continue;
		}
	}
	return output;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int nums = 0;
		int pre = 0;
		int now = 0;

		cin >> nums;
		cin >> pre;
		for (int j = 1; j < nums; j++)
		{
			cin >> now;

			graph[now].push_back(pre);
			pre = now;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dp[i] == 0)
		{
			dfs(i);
		}
		answer[dp[i]].push_back(i);
	}

	for (int i = 1; i <= N; i++)
	{
		bool visited[MAX_N] = { 0, };

		if (CheckCircle(i, i, visited))
		{
			IsCircle = true;
			break;
		}
	}

	if (IsCircle) cout << 0 << '\n';
	else
	{
		for (int i = 1; i <= N; i++)
		{
			for (auto a : answer[i])
			{
				cout << a << '\n';
			}
		}
	}
}