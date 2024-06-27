// 케빈 베이컨의 6단계 법칙
// 케빈 베이컨 게임은 두 사람이 최소 몇 단계만에 이어질 수 있는지 계산하는 게임이다.
// N명의 사람이 주어질 때, 모든 사람들에 대한 단계의 수의 합을 케빈 베이컨의 수라 할 때, 케빈 베이컨 수가 가장 적은 사람을 구하라.


// 내 답안1
// 플로이드-워셜 알고리즘
#include <iostream>
#include <algorithm>

#define INF 987654321
#define MAX_N 101

using namespace std;

int graph[MAX_N][MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, ans = 1, kevin = INF;

	cin >> N >> M;

	for(int i=1; i<=N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}

	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int number = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			number += graph[i][j];
		}
		if (number < kevin)
		{
			kevin = number;
			ans = i;
		}
	}
	cout << ans  << '\n';
}