// 사다리 조작
// 각각 N개의 세로선에 H개의 가로선을 추가할 수 있고 현재 M개의 가로선이 존재하는 사다리 게임이 주어진다. 가로선을 적절히 추가하여 i번 세로선의 결과가 i가 나오도록 하는 가로선 추가 개수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 11
#define MAX_H 31
#define MAX_M 300
#define INF 987654321

using namespace std;

struct Direction
{
	bool left;
	bool right;
};
struct Point
{
	int i;
	int j;
};

int N = 0;
int M = 0;
int H = 0;
vector<Point> possibles;
vector<vector<Direction>> graph(MAX_H, vector<Direction>(MAX_N, {false, false}));


// 사다리게임을 구현
int LadderGame(int start)
{
	int j = start;
	int i = 1;

	while (i <= H)
	{
		if (graph[i][j].left)
		{
			j--;
		}
		else if(graph[i][j].right)
		{
			j++;
		}
		i++;
	}
	return j;
}

int backtracking(int start, int cnt)
{
	// 사다리게임 실행.
	bool state = true;
	for (int i = 1; i <= N; i++)
	{
		state = state && (i == LadderGame(i));
	}
	if (state) return cnt;

	// 추가 개수가 3보다 커지면 멈춤.
	if (cnt >= 3)
	{
		return INF;
	}
	// 가로선이 없는 곳에 가로선을 하나씩 추가.

	int returnValue = INF;

	for (int i = start; i < possibles.size(); i++)
	{
		if (!graph[possibles[i].i][possibles[i].j].left && !graph[possibles[i].i][possibles[i].j].right && !graph[possibles[i].i][possibles[i].j + 1].left && !graph[possibles[i].i][possibles[i].j + 1].right)
		{
			graph[possibles[i].i][possibles[i].j].right = true;
			graph[possibles[i].i][possibles[i].j+1].left = true;
			returnValue = min(returnValue, backtracking(start + 1, cnt + 1));
			graph[possibles[i].i][possibles[i].j].right = false;
			graph[possibles[i].i][possibles[i].j + 1].left = false;
		}
	}
	return returnValue;
}

bool CheckAnswer()
{
	bool state = true;
	for (int i = 1; i <= N; i++)
	{
		state = state && (i == LadderGame(i));
	}
	return state;
}

void AddLadder(int k)
{
	if (!graph[possibles[k].i][possibles[k].j].left && !graph[possibles[k].i][possibles[k].j].right && !graph[possibles[k].i][possibles[k].j + 1].left && !graph[possibles[k].i][possibles[k].j + 1].right)
	{
		graph[possibles[k].i][possibles[k].j].right = true;
		graph[possibles[k].i][possibles[k].j + 1].left = true;
	}
}
void DeleteLadder(int k)
{
	graph[possibles[k].i][possibles[k].j].right = false;
	graph[possibles[k].i][possibles[k].j + 1].left = false;
}
int LoopFunc(int start, int cnt)
{
	// 사다리게임 실행.
	if (CheckAnswer()) return cnt;

	int returnValue = INF;
	for (int a = start; a < possibles.size(); a++)
	{
		AddLadder(a);
		if (CheckAnswer()) returnValue = min(returnValue, 1);

		for (int b = a + 1; b < possibles.size(); b++)
		{
			AddLadder(b);
			if (CheckAnswer()) returnValue = min(returnValue, 2);
			
			for (int c = b + 1; c < possibles.size(); c++)
			{
				AddLadder(c);
				if (CheckAnswer()) returnValue = min(returnValue, 3);
				DeleteLadder(c);
			}
			DeleteLadder(b);
		}
		DeleteLadder(a);
	}
	return returnValue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;
		
		cin >> a >> b;

		graph[a][b].right = true;
		graph[a][b + 1].left = true;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (!graph[i][j].left && !graph[i][j].right && !graph[i][j+1].left && !graph[i][j+1].right)
			{
				possibles.push_back({ i,j });
			}
		}
	}
	
	int answer = LoopFunc(0, 0);
	cout << (answer >= INF ? -1 : answer) << '\n';
}