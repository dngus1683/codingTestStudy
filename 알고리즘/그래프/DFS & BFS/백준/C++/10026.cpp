// 적록색약
// n x n 크기의 RGB값이 주어진다. 상하좌우 같은 색상이면 그 두 곳은 같은 구역이라고 본다. 적록색약은 빨간색과 초록색을 구별하기 힘들어해서 같은 구역으로 본다.
// 한 그림을 적록색약이 아닌 사람이 봤을 때와 적록색약이 봤을 때의 구역 수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 101

using namespace std;

int N = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1 ,1 };
char graph[MAX_N][MAX_N];
bool VisitedNormal[MAX_N][MAX_N] = { false, };
bool VisitedRG[MAX_N][MAX_N] = { false, };

void dfs(int NowI, int NowJ, bool visited[][MAX_N], bool IsNormal)
{
	visited[NowI][NowJ] = true;
	for (int i = 0; i < 4; i++)
	{
		if (NowI + di[i] < 0 || NowI + di[i] >= N || NowJ + dj[i] < 0 || NowJ + dj[i] >= N)
			continue;

		if (!visited[NowI + di[i]][NowJ + dj[i]])
		{
			bool IsOne = graph[NowI][NowJ] == graph[NowI + di[i]][NowJ + dj[i]];
			bool IsRG = (graph[NowI][NowJ] == 'R' && graph[NowI + di[i]][NowJ + dj[i]] == 'G')
				|| (graph[NowI][NowJ] == 'G' && graph[NowI + di[i]][NowJ + dj[i]] == 'R');
			if (IsOne && IsNormal)
				dfs(NowI + di[i], NowJ + dj[i], visited, IsNormal);
			else if ((IsOne || IsRG) && !IsNormal)
				dfs(NowI + di[i], NowJ + dj[i], visited, IsNormal);

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int AnsNormal = 0;
	int AnsRG = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> graph[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!VisitedNormal[i][j])
			{
				dfs(i, j, VisitedNormal, true);
				AnsNormal++;
			}
			if (!VisitedRG[i][j])
			{
				dfs(i, j, VisitedRG, false);
				AnsRG++;
			}
		}
	}

	cout << AnsNormal << ' ' << AnsRG << '\n';

}