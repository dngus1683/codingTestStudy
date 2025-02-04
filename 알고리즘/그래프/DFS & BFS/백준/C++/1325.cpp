// 효율적인 해킹
// 어느 회사의 컴퓨터끼리는 A가 B를 신뢰하는 경우, B를 해킹하면 A도 같이 해킹된다.
// 이 회사의 컴퓨터 간 신뢰관계가 주어질 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10'001 
#define MAX_M 100'001

using namespace std;

int N = 0;
int M = 0;
int mx = 0;
vector<int> graph[MAX_N];
int dp[MAX_N];


int dfs(int start, bool visited[])
{
	visited[start] = true;

	int cnt = 0;
	for (int next : graph[start])
	{
		if (visited[next]) continue;
		else
		{
			cnt += (dfs(next, visited) + 1);
		}

	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;

		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		bool visited[MAX_N] = {false, };
		
		dp[i] = dfs(i, visited);
		mx = max(mx, dp[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (mx == dp[i])
		{
			cout << i << ' ';
		}
	}
	cout << '\n';
}
