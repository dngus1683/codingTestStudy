// 헌내기는 친구가 필요해
// NxM 크기의 맵에 도연이의 위치 I, 친구들의 위치 P, 벽 X, 빈 공간 O이 주어진다. 도연이가 벽을 제외한 상하좌우로 움직일 수 있다고 할 때, 도연이가 만날 수 있는 사람의 수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 601

using namespace std;

int ans = 0;
int N = 0;
int M = 0;
int di[4] = {-1, 1, 0, 0};
int dj[4] = { 0, 0, -1, 1 };
char graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void dfs(int NowI, int NowJ)
{
	if (graph[NowI][NowJ] == 'P')
		ans++;
	visited[NowI][NowJ] = true;

	for (int i = 0; i < 4; i++)
	{
		if (NowI + di[i] < 0 || NowI + di[i] >= N || NowJ + dj[i] < 0 || NowJ + dj[i] >= M || graph[NowI + di[i]][NowJ + dj[i]] == 'X') continue;
		if(!visited[NowI + di[i]][NowJ + dj[i]])
			dfs(NowI + di[i], NowJ + dj[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int StartI = 0;
	int StartJ = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			
			if (graph[i][j] == 'I')
			{
				StartI = i;
				StartJ = j;
			}
		}
	}

	dfs(StartI, StartJ);

	if (ans)
		cout << ans << '\n';
	else
		cout << "TT" << '\n';
}