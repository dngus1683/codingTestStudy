// 플로이드
// N개의 도시와, 한 도시에서 다른 도시로 이동하는 M개의 버스, 각 버스의 비용이 주어진다. 모든 도시 쌍에 대해서 버스로 이동하는데 드는 비용의 최솟값들을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 101
#define MAX_M 100'000
#define INF 987654321

using namespace std;

int d[MAX_N][MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a = 0; 
		int b = 0;
		int c = 0;

		cin >> a >> b >> c;
		d[a][b] = (d[a][b] == 0 ? c : min(d[a][b], c));
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) d[i][j] = 0;
			else if (d[i][j] == 0) d[i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (d[i][j] == INF)
				d[i][j] = 0;
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}