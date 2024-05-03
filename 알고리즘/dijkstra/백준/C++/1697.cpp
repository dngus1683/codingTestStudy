// 숨바꼭질
// 수빈이는 현재 N에 위치하고 동생은 K에 위치한다. 수빈이는 1초만에 앞뒤로 한칸 움직이거나 현재 위치의 2배되는 곳으로 순간이동이 가능하다.
// 수빈이가 동생의 위치에 도달하는데 걸리는 최소 시간을 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

#define MAX_N 100001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N*2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K, ans = 0;

	cin >> N >> K;

	for (int i = 0; i < MAX_N; i++)
	{
		graph[i].push_back({ i + 1, 1 });
		graph[i].push_back({ i - 1, 1 });
		graph[i].push_back({ i * 2, 1 });
	}

	fill(d, d + MAX_N, INF);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, N });

	d[N] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		for(int i=0; i<graph[now].size(); i++)
		{
			int cost = d[now] + graph[now][i].second;
			if (d[graph[now][i].first] > cost && graph[now][i].first >=0)
			{
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}

	cout << d[K] << '\n';


}











// 답안 예시1 - https://www.acmicpc.net/source/61779491
// Top-down 방식
/*
using namespace std;
#include <cstdio>
#include <algorithm>

int N, K;

int f(int k)
{
	if (k <= N)
		return N - k;
	int ret = 1 + ((k % 2 && k > 1) ? min(f(k - 1), f(k + 1)) : f(k / 2));
	return min(ret, k - N);
}

int main()
{
	scanf("%d %d", &N, &K);
	printf("%d", f(K));
}
*/
