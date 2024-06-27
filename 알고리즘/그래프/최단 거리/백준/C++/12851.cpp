// 숨바꼭질
// 수빈이는 점 N, 동생은 점 K에 위치한다. 수빈이가 1초에 X-1, X+1, X*2 이 세 위치로 이동가능하다고 할 때, 동생의 위치로 가는 가장 빠른 시간과, 그 방법이 몇 가지가 있는지 구하라.


// 내 답안1
// dp로 구현 - 실패 (미래 값을 고려하지 못함.)
/*
#include <iostream>

#define MAX_N 100'001
#define MAX_K 100'001

using namespace std;

int dp[MAX_N];
int cnt[MAX_N];

inline int min(const int& a, const int& b)
{
	return (a < b ? a : b);
}

inline int CompEqu(const int& a, const int& b)
{
	return (a == b ? 2 : 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		dp[i] = N - i;
		cnt[i] = 1;
	}

	if (N >= K)
	{
		cout << dp[K] << '\n';
		if (N == K)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
	else
	{
		dp[N] = 0;
		for (int i = N + 1; i < MAX_N; i++)
		{
			int c = 0;
			int cost = 0;
			if (i % 2 == 1)
			{
				c = 1;
				cost = dp[i - 1] + 1;
			}
			else
			{
				c = CompEqu(dp[i - 1], dp[i / 2]);
				cost = min(dp[i - 1], dp[i / 2]) + 1;
			}
			dp[i] = cost;
			cnt[i] = c;
		}

		for (int i = N + 1; i < MAX_N; i++)
		{
			if (i == K) break;

			int cost = dp[i+1] + 1;

			if (dp[i] > cost)
			{
				dp[i] = cost;
				cnt[i] = 1;
			}
			else if (dp[i] == cost)
			{
				cnt[i] += 1;
			}
		}
		for (int i = 0; i < K+2; i++)
		{
			cout << dp[i] << ' ';
		}
		cout << endl << endl;
		for (int i = 0; i < K + 2; i++)
		{
			cout << cnt[i] << ' ';
		}
		cout << endl << endl;
		cout << dp[K] << '\n' << cnt[K] << '\n';
	}
}
*/



// 내 답안2
// dijkstra 
// 0초가 걸릴 때, 방법이 1가지라고 고려.
#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 100'001
#define MAX_K 100'001

using namespace std;

int d[MAX_N];
int cnt[MAX_N];
int nx[3] = { -1, 1, 0 };

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		
		nx[0] = now - 1;
		nx[1] = now + 1;
		nx[2] = now * 2;
		for (auto next : nx)
		{
			if (next >= MAX_N || next < 0) continue;

			int cost = d[now] + 1;
			if (d[next] > cost)
			{
				cnt[next] = cnt[now];
				d[next] = cost;
				pq.push({ -cost, next });
			}
			else if (d[next] == cost)
			{
				cnt[next] += cnt[now];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;

	cin >> N >> K;

	fill(cnt, cnt + MAX_N, 1);
	fill(d, d + MAX_N, INF);

	dijkstra(N);

	cout << d[K] << '\n' << cnt[K] << '\n';
}