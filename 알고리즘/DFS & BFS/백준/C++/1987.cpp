// 알파벳
// R x C 크기의 보드 각 칸에는 대문자 알파벳이 하나씩 있다. (1,1)에서 시작하여 상하좌우로 이동이 가능하며, 한 번 밟은 알파벳은 두 번 지날 수 없다고 할 때, 말이 지나는 칸의 최대 수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_R 21

using namespace std;

int R = 0;
int C = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
bool visited[26];
char graph[MAX_R][MAX_R];

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int dfs(int NowI, int NowJ)
{
	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		if (NowI + di[i] < 0 || NowI + di[i] >= R || NowJ + dj[i] < 0 || NowJ + dj[i] >= C)
			continue;

		if (!visited[graph[NowI + di[i]][NowJ + dj[i]] - 'A'])
		{
			visited[graph[NowI + di[i]][NowJ + dj[i]] - 'A'] = true;
			ans = max(dfs(NowI + di[i], NowJ + dj[i]), ans);
			visited[graph[NowI + di[i]][NowJ + dj[i]] - 'A'] = false;
		}
	}
	return ans + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cin >> graph[i][j];
	}

	visited[graph[0][0]-'A'] = true;

	cout << dfs(0, 0) << '\n';
}