// 보물섬
// 바다는 W, 육지는 L로 표시된 보물섬 지도가 주어진다.
// 이동은 상하좌우로 육지로만 이동이 가능하다.
// 최단 거리로 이동했을 때 가장 긴 시간이 걸리는 두 지점에 보물을 놓았다.
// 보물이 묻혀 있는 두 곳간의 최단 거리로 이동하는 시간을 구하라.


// 내 답안1 - 오답
// 트리의 지름 활용 -> 사이클이 존재하면 트리가 아니기 때문에 접목시킬 수 없는 경우가 있음.
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX_L 51

using namespace std;

int sizeI = 0;
int sizeJ = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
char graph[MAX_L][MAX_L];
bool visited[MAX_L][MAX_L];
vector<pair<int, int>> island;
int answer = 0;

int bfs(int nowI, int nowJ, int& destI, int& destJ, int dist)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({{ nowI, nowJ }, 0});
	visited[nowI][nowJ] = true;

	while (!q.empty())
	{
		int nowI = q.front().first.first;
		int nowJ = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (dist < cnt)
		{
			destI = nowI;
			destJ = nowJ;
			dist = cnt;
		}

		for (int d = 0; d < 4; d++)
		{
			int nextI = nowI + di[d];
			int nextJ = nowJ + dj[d];

			if (nextI < 0 || nextI >= sizeI || nextJ < 0 || nextJ >= sizeJ)
				continue;

			if (!visited[nextI][nextJ] && graph[nextI][nextJ] == 'L')
			{
				visited[nextI][nextJ] = true;
				q.push({ { nextI, nextJ }, cnt + 1 });
			}
		}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> sizeI >> sizeJ;
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			if (!visited[i][j] && graph[i][j] == 'L')
			{
				int startI = 0;
				int startJ = 0;
				bfs(i, j, startI, startJ, 0);

				island.push_back({ startI, startJ });
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (auto point : island)
	{
		answer = max(answer, bfs(point.first, point.second, point.first, point.second, 0));
	}

	cout << answer << '\n';


}
*/


// 내 답안2
// 단순히 bfs를 모든 좌표에서 실행해도(브루트포스) 시간적 여유가 있음. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX_L 51

using namespace std;

int sizeI = 0;
int sizeJ = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
char graph[MAX_L][MAX_L];
bool visited[MAX_L][MAX_L];
int answer = 0;

int bfs(int nowI, int nowJ, int dist)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { nowI, nowJ }, 0 });
	visited[nowI][nowJ] = true;

	while (!q.empty())
	{
		int nowI = q.front().first.first;
		int nowJ = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (dist < cnt)
		{
			dist = cnt;
		}

		for (int d = 0; d < 4; d++)
		{
			int nextI = nowI + di[d];
			int nextJ = nowJ + dj[d];

			if (nextI < 0 || nextI >= sizeI || nextJ < 0 || nextJ >= sizeJ)
				continue;

			if (!visited[nextI][nextJ] && graph[nextI][nextJ] == 'L')
			{
				visited[nextI][nextJ] = true;
				q.push({ { nextI, nextJ }, cnt + 1 });
			}
		}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> sizeI >> sizeJ;
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			if (graph[i][j] == 'L')
			{
				memset(visited, 0, sizeof(visited));
				answer = max(answer, bfs(i, j, 0));
			}
		}
	}

	cout << answer << '\n';
}