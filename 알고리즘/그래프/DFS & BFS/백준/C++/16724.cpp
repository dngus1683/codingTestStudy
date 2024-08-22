// 피리 부는 사나이
// N x M 크기의 맵이 주어지며, 각 맵에 상하좌우 중 한 방향이 주어진다. 해당 위치에서는 해당하는 방향으로만 이동할 수 있다. 맵에 safe zone을 배치하여 맵의 어디에서 출발해도 safe zone에 들어가도록 하려한다. safe zone의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <unordered_map>

#define MAX 1000

using namespace std;

unordered_map<char, int> Direction = { {'L', 0}, {'R', 1}, {'U',2}, {'D', 3} };
char map[MAX][MAX];
bool visited[MAX][MAX];
bool compelte[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N = 0;
int M = 0;
int answer = 0;


void dfs(int x, int y)
{
	visited[y][x] = true;
	
	int NextX = x + dx[Direction[map[y][x]]];
	int NextY = y + dy[Direction[map[y][x]]];

	if (NextX >= 0 && NextY >= 0 && NextX < M && NextY < N )
	{
		if (!visited[NextY][NextX])
			dfs(NextX, NextY);
		else if (!compelte[NextY][NextX])
		{
			answer++;
		}

	}
	else
	{
		answer ++;
	}
	compelte[y][x] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (!visited[y][x])
				dfs(x, y);
		}
	}

	cout << answer << '\n';
}