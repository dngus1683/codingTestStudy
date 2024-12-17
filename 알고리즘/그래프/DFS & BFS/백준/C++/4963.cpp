// 섬의 개수
// 정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬은 가로 세로 대각선으로 연결되어 있으면 걸어다닐 수 있으며, 걸어다닐 수 있다면 하나의 섬이다.
// 섬의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_L 51
#define SEA 0
#define LAND 1

using namespace std;

int w = 0;
int h = 0;
int di[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dj[8] = {0, 0, -1, 1,-1, 1, -1, 1};
int graph[MAX_L][MAX_L];

void dfs(int nowI, int nowJ, bool visited[MAX_L][MAX_L])
{
	visited[nowI][nowJ] = true;

	for (int i = 0; i < 8; i++)
	{
		int nextI = nowI + di[i];
		int nextJ = nowJ + dj[i];

		if (nextJ < 0 || nextJ >= w || nextI < 0 || nextI >= h)
			continue;

		if (!visited[nextI][nextJ] && graph[nextI][nextJ] == LAND)
		{
			dfs(nextI, nextJ, visited);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		int answer = 0;
		bool visited[MAX_L][MAX_L] = { 0, };

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> graph[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && graph[i][j] == LAND)
				{
					answer++;
					dfs(i, j, visited);
				}
			}
		}

		cout << answer << '\n';

	}
}