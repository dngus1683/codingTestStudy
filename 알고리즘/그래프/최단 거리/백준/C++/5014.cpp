// 스타트링크
// F층으로 이루어진 고층 건물에 현재 S층에 있다. G층을 가기 위해 엘리베이터를 타는데, 엘리베이터는 D층 아래로, U층 위로만 갈 수 있다.
// G층에 도찾하기 위한 최소한의 버튼 누름 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 1'000'001
#define INF 2'000'000'000

using namespace std;

int F = 0;
int S = 0;
int G = 0;
int U = 0;
int D = 0;
int direction[2] = {};
int dp[MAX_N];

void dijkstra(int start)
{
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,start });
	dp[start] = 0;

	while (!pq.empty())
	{
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (dp[now] < dist) continue;

		for (int i = 0; i < 2; i++)
		{
			int next = now + direction[i];

			if (next > F || next < 1) continue;

			if (dp[next] > dp[now] + 1)
			{
				dp[next] = dp[now] + 1;
				pq.push({ -dp[next],next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;
	direction[0] = U;
	direction[1] = -D;

	fill(dp, dp + MAX_N, INF);

	dijkstra(S);

	if (dp[G] >= INF)
	{
		cout << "use the stairs\n";
	}
	else
	{
		cout << dp[G] << '\n';
	}
}