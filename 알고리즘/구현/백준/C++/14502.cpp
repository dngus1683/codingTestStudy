// 연구소
// N x M 크기의 맵에 벽 1, 빈 칸 0, 바이러스 2가 있다. 바이러스는 맞닿아 있는 빈 칸으로 퍼진다. 벽을 추가로 3개 세워 바이러스가 퍼지는 것을 막을 수 있다. 이때, 벽은 꼭 3개를 세워야 한다. 
// 연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역의 최댓값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define MAX_N 8

using namespace std;

int N = 0;
int M = 0;
int CntWall = 3;
int graph[MAX_N][MAX_N];
int StartPoint[MAX_N][MAX_N];
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> vir;

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int bfs(int NowI, int NowJ, bool visited[][MAX_N])
{
	int CntVir = 0;
	queue<pair<int, int>> q;
	q.push({ NowI, NowJ });

	visited[NowI][NowJ] = true;

	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		CntVir++;

		for (int d = 0; d < 4; d++)
		{
			int NextI = i + di[d];
			int NextJ = j + dj[d];
			if (NextI < 0 || NextI >= N || NextJ < 0 || NextJ >= M) continue;

			if (visited[NextI][NextJ] != true && graph[NextI][NextJ] != 1)
			{ 
				visited[NextI][NextJ] = true;
				q.push({ NextI, NextJ });
			}
		}
	}
	return CntVir;
}

int combination(int count)
{
	int ans = 0;
	if (count == 0)
	{
		int CntVir = 0;
		bool visited[MAX_N][MAX_N] = { 0, };
		for (auto coor : vir)
		{
			if (visited[coor.first][coor.second] != true)
			{
				CntVir += bfs(coor.first, coor.second, visited);
			}
		}
		return ((N * M) - CntWall - CntVir);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (graph[i][j] == 0 && StartPoint[i][j] == 0)
				{
					graph[i][j] = 1;
					ans = max(ans, combination(count - 1));
					graph[i][j] = 0;
					if (count == 3)
					{
						StartPoint[i][j] = 1;
					}
				}
			}
		}
		return ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				vir.push_back({ i, j });
			}
			else if (graph[i][j] == 1)
				CntWall++;
		}

	cout << combination(3) << '\n';
}