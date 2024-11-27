// 그림
// n x m 크기의 0과 1로 이루어진 도화지가 주어진다. 1이 상하좌우로 연결되어 있는 1의 덩어리를 그림이라고 할 때,
// 도화지 내의 그림 개수와 가장 넓은 그림의 넓이를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 501
#define MAX_M 501

using namespace std;

int n = 0;
int m = 0;
int mx = 0;
int cnt = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
int graph[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int dfs(int nowI, int nowJ)
{
	int returnValue = 1;

	visited[nowI][nowJ] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextI = nowI + di[i];
		int nextJ = nowJ + dj[i];

		if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m)
			continue;
		if (graph[nextI][nextJ] == 1 && visited[nextI][nextJ] == false)
		{
			returnValue += dfs(nextI, nextJ);
		}
	}

	return returnValue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == false && graph[i][j] == 1)
			{
				cnt++;
				mx = max(mx, dfs(i, j));
			}
		}
	}

	cout << cnt << '\n' << mx << '\n';

}