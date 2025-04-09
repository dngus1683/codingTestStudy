// 구슬 탈출2
// N x M 크기의 보드에 빨간 구슬과 파란 구슬, 구멍이 하나 있다. 보드를 상하좌우로 기울여서 두 구슬을 이동시킬 수 있다. 
// 빨간 구슬만 구멍에 들어간 경우만 성공이라고 할 때, 최소 몇 번만에 성공할 수 있는지 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 11 

using namespace std;

enum class Dir
{
	Up,
	Down,
	Left,
	Right,
};

struct point
{
	int i;
	int j;
	point operator + (const point & other)
	{
		return {i+other.i, j+other.j};
	}
	bool operator ==(const point& other)
	{
		return (i == other.i && j == other.j);
	}
};

struct ppair
{
	point red;
	point blue;
	int cnt;
};

int N = 0;
int M = 0;
int answer = 11;
point R;
point B;
point direction[4] = { {-1, 0}, {1, 0}, {0,-1}, {0,1} };
vector<vector<int>> board(MAX_N, vector<int>(MAX_N, 0));
bool visited[MAX_N][MAX_N][MAX_N][MAX_N] = {};

bool move(point& now, const point& other, const point& direction)
{	
	while (true)
	{
		if (now.i + direction.i < 0 || now.i + direction.i >= N || now.j + direction.j < 0 || now.j + direction.j >= M)
		{
			return false;
		}

		if (board[now.i + direction.i][now.j + direction.j] == -1)
		{
			return false;
		}
		else if (board[now.i + direction.i][now.j + direction.j] == 1)
		{
			now = { 0, 0 };
			return true;
		}
		else if (now+direction == other)
		{
			return false;
		}
		else
		{
			now = now+direction;
		}
	}
	return false;
}


void bfs(point r, point b)
{
	queue<ppair> q;
	q.push({ r, b , 1});
	visited[r.i][r.j][b.i][b.j] = true;

	while (!q.empty())
	{
		point nowR = q.front().red;
		point nowB = q.front().blue;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			bool RedState = false;
			bool BlueState = false;
			point tmpR = nowR;
			point tmpB = nowB;
			// 이동은 이동하는 방향에 선두에 선 구슬부터
			if (((tmpR.i >= tmpB.i) && (i == (int)Dir::Down)) || ((tmpR.j >= tmpB.j) && (i == (int)Dir::Right)) || ((tmpR.i <= tmpB.i) && (i == (int)Dir::Up)) || ((tmpR.j <= tmpB.j) && (i == (int)Dir::Left)))
			{
				RedState = move(tmpR, tmpB, direction[i]);
				BlueState = move(tmpB, tmpR, direction[i]);
			}
			else
			{
				BlueState = move(tmpB, tmpR, direction[i]);
				RedState = move(tmpR, tmpB, direction[i]);
			}

			if (RedState && !BlueState)
			{
				answer = min(answer, cnt);
				break;
			}
			else if (BlueState)
			{
				continue;
			}

			if (!visited[tmpR.i][tmpR.j][tmpB.i][tmpB.j] && cnt < 10)
			{
				visited[tmpR.i][tmpR.j][tmpB.i][tmpB.j] = true;
				q.push({ tmpR, tmpB, cnt + 1 });
			}
		}
	}
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
			char c = ' ';

			cin >> c;
			if (c == '#') board[i][j] = -1;
			else if (c == '.') board[i][j] = 0;
			else if (c == 'O') board[i][j] = 1;
			else if (c == 'R')
			{
				board[i][j] = 0;
				R = { i,j };
			}
			else if (c == 'B')
			{
				board[i][j] = 0;
				B = { i,j };
			}
		}
	}

	bfs(R, B);

	if(answer > 10)
		cout << -1 << '\n';
	else
		cout << answer << '\n';
}