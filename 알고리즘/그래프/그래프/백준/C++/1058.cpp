// 친구
// N명의 사람이 서로 친구인지가 주어진다. 이때, A와 B가 C와 친구라면 A와 B 역시 친구가 된다.
// 가장 친구가 많은 사람의 친구 수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 51

using namespace std;

int N = 0;
int answer = 0;
short graph[MAX_N][MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char f = ' ';

			cin >> f;
			if (f == 'Y')
			{
				graph[i][j] = 1;
			}
			else
			{
				graph[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] != 0 || i == j)
				continue;

			for (int k = 1; k <= N; k++)
			{
				if (graph[i][j] != 0) break;
				if (graph[i][k] == 1 && graph[k][j] == 1)
				{
					graph[i][j] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] != 0)
			{
				cnt++;
			}
		}
		answer = max(answer, cnt);
	}
	
	cout << answer << '\n';
}