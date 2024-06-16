// 미세먼지 안녕!
// R x C 맵에 미세먼지와 공기청정기가 주어진다. 공기청정기는 1열에 연속된 2칸에 위치한다. 매초마다 미세먼지는 인접한 4 방향으로 (현재 미세먼지 / 5) 만큼 확산되며, 공기청정기 윗 칸은 반시계, 아랫 칸은 시계방향으로 바람이 불어, 미세먼지를 이동시킨다.
// 미세먼지가 공기청정기로 들어오면 해당 미세먼지는 사라진다. T초의 시간이 지났을 때, 남아있는 공기청정기의 양을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_R 51
#define MAX_C 51

using namespace std;

int R = 0;
int C = 0;
int T = 0;
int state = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
int graph[MAX_R][MAX_C][2];
vector<pair<int, int>> Air;

void dfs(int NowI, int NowJ, int AirI, int AirJ, int AirState, int direct)
{
	if (NowI == AirI && NowJ == AirJ)
	{
		graph[AirI][AirJ][!state] = -1;
		return;
	}
	else
	{
		if (NowJ + dj[direct] >= C && direct == 3)
		{
			if (AirState == 1) direct = 1;
			else direct = 0;
		}
		else if ((NowI + di[direct] < 0 && direct == 0) || (NowI + di[direct] >= R && direct == 1)) direct = 2;
		else if (NowJ + dj[direct] < 0 && direct == 2)
		{
			if (AirState == 1) direct = 0;
			else direct = 1;
		}
		int NextI = NowI + di[direct];
		int NextJ = NowJ + dj[direct];

		if (NextI == AirI && NextJ == AirJ)
		{
			return;
		}
		dfs(NextI, NextJ, AirI, AirJ, AirState, direct);
		graph[NextI][NextJ][state] = graph[NowI][NowJ][state];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> graph[i][j][0];
			if (graph[i][j][0] == -1) Air.push_back({ i, j });
		}
	}

	
	while (T--)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (graph[i][j][state] > 4)
				{
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int NextI = i + di[k];
						int NextJ = j + dj[k];
						if (NextI < 0 || NextI >= R || NextJ < 0 || NextJ >= C || graph[NextI][NextJ][state] == -1) continue;
						graph[NextI][NextJ][!state] += (graph[i][j][state] / 5);
						cnt++;
					}
					graph[i][j][!state] += (graph[i][j][state] - (graph[i][j][state] / 5) * cnt);
				}
				else if (graph[i][j][state] == -1)
					graph[i][j][!state] = -1;
				else
					graph[i][j][!state] += graph[i][j][state];
			}
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				graph[i][j][state] = 0;
			}
		}

		state = !state;


		dfs(Air[0].first, Air[0].second + 1, Air[0].first, Air[0].second, 0, 3);
		dfs(Air[1].first, Air[1].second + 1, Air[1].first, Air[1].second, 1, 3);
		graph[Air[0].first][1][state] = graph[Air[1].first][1][state] = 0;

	}

	int ans = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ans += graph[i][j][state];
		}
	}

	cout << ans + 2 << '\n';

}