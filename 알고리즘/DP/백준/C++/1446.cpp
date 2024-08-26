// 지름길
// D 킬로미터의 고속도로를 지나는데, 중간에 일방통행 지름길이 여러 존재한다. 해당 고속도로를 지나는 거리의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_D 10'001

using namespace std;

vector<pair<int, int>> graph[MAX_D];
int dp[MAX_D];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int D = 0;

	cin >> N >> D;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		graph[b].push_back({ a, c });
	}
	for (int i = 1; i <= D; i++)
	{
		dp[i] = dp[i-1]+1;
		if (!graph[i].empty())
		{
			for (auto pre : graph[i])
			{
				dp[i] = min(dp[i], dp[pre.first] + pre.second);
			}
		}
	}
	cout << dp[D] << '\n';
}