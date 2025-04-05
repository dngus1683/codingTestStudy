// 주사위 굴리기
// N x M 크기의 지도가 주어지고, 지도 위에는 주사위가 하나 놓여있다. 주사위를 굴렸을 때, 해당 지도 위치에 숫자가 0이라면, 지도와 맞닿고 있는 주사위 면의 번호와 교환. 반대로 지도에 숫자가 있다면 주사위 바닥면에 복사되며 지도 숫자는 0이 된다.
// 주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위의 상단면 값을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 20
#define MAX_M 20

using namespace std;

enum class DiceDirection
{
	Top,
	Bottom,
	Front, 
	Back,
	Right,
	Left,
};
enum class RollDirection
{
	None,
	Right,
	Left,
	Up,
	Down,
};

int N = 0;
int M = 0;
int x = 0;
int y = 0;
int K = 0;
int di[5] = { 0, 0, 0, -1, 1 };
int dj[5] = { 0, 1, -1,0 ,0 };
int dice[6] = {};
int map[MAX_N][MAX_M] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	while (K--)
	{
		int dir = 0;

		cin >> dir;

		int nowI = x + di[dir];
		int nowJ = y + dj[dir];
		
		if (nowI < 0 || nowI >= N || nowJ < 0 || nowJ >= M) continue;

		if (dir == (int)RollDirection::Right)
		{
			int tmp = dice[(int)DiceDirection::Top];

			dice[(int)DiceDirection::Top] = dice[(int)DiceDirection::Left];
			dice[(int)DiceDirection::Left] = dice[(int)DiceDirection::Bottom];
			dice[(int)DiceDirection::Bottom] = dice[(int)DiceDirection::Right];
			dice[(int)DiceDirection::Right] = tmp;
		}
		if (dir == (int)RollDirection::Left)
		{
			int tmp = dice[(int)DiceDirection::Top];

			dice[(int)DiceDirection::Top] = dice[(int)DiceDirection::Right];
			dice[(int)DiceDirection::Right] = dice[(int)DiceDirection::Bottom];
			dice[(int)DiceDirection::Bottom] = dice[(int)DiceDirection::Left];
			dice[(int)DiceDirection::Left] = tmp;
		}
		if (dir == (int)RollDirection::Up)
		{
			int tmp = dice[(int)DiceDirection::Top];

			dice[(int)DiceDirection::Top] = dice[(int)DiceDirection::Front];
			dice[(int)DiceDirection::Front] = dice[(int)DiceDirection::Bottom];
			dice[(int)DiceDirection::Bottom] = dice[(int)DiceDirection::Back];
			dice[(int)DiceDirection::Back] = tmp;
		}
		if (dir == (int)RollDirection::Down)
		{
			int tmp = dice[(int)DiceDirection::Top];

			dice[(int)DiceDirection::Top] = dice[(int)DiceDirection::Back];
			dice[(int)DiceDirection::Back] = dice[(int)DiceDirection::Bottom];
			dice[(int)DiceDirection::Bottom] = dice[(int)DiceDirection::Front];
			dice[(int)DiceDirection::Front] = tmp;
		}

		if (map[nowI][nowJ] == 0)
		{
			map[nowI][nowJ] = dice[(int)DiceDirection::Bottom];
		}
		else
		{
			dice[(int)DiceDirection::Bottom] = map[nowI][nowJ];
			map[nowI][nowJ] = 0;
		}
		cout << dice[(int)DiceDirection::Top] << '\n';

		x = nowI;
		y = nowJ;
	}

}