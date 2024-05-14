// 뱀과 사다리 게임
// 10 x 10 크기의 보드판에서, (1, 1) 에서 (10, 10)까지 주사위를 굴려 간다.
// 사다리가 있는 곳에 도착하면 지름길을 이용하고, 뱀이 있는 곳에 도착하면 뒤로 내려가게 된다.
// 주사위 값을 원하는 수가 나올 수 있게 만들었을 때, 100번 칸에 도착하기 위한 주사위 굴리기 최소 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321
#define MAX_N 16
#define MAX_M 16

using namespace std;

pair<int, int> graph[101] = { {0,0}, };
int d[101];
int dv[6] = { 1,2,3,4,5,6 };

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
		for (int i = 0; i < 6; i++)
		{
			if (now + dv[i] > 100) continue;

			int cost = d[now] + 1;
			int next = now+dv[i];
			if (graph[now + dv[i]].second == 1)
			{
				next = graph[now + dv[i]].first;
			}

			if (d[next] > cost)
			{
				d[next] = cost;
				pq.push({-cost, next});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;

	cin >> N >> M;
	for (int i = 0; i < N+M; i++)
	{
		int x = 0;
		int y = 0;

		cin >> x >> y;
		graph[x] = { y, 1 };
	}

	fill(d, d + 101, INF);

	dijkstra(1);

	cout << d[100] << '\n';
}