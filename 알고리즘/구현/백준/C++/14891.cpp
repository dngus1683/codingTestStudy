// 톱니바퀴
// 4개의 톱니바퀴가 가로로 나란히 놓여 있다. 각 톱니바퀴의 톱니에는 N과 S극 중 하나를 가지게 된다. 톱니를 하나 회전시키면, 바로 옆에 맞닿아 있는 톱니의 극이 정반대라면 반대방향으로 회전하게 된다.
// 톱니바퀴의 초기 상태와 톱니바퀴를 회전시킨 방법이 주어질 때, 최종 톱니바퀴의 상태를 구하라.


// 내 답안1
#include <iostream>
#include <deque>

#define Nmag 0
#define Smag 1
#define MAX_K 101
#define ClockWise 1
#define CounterClockWise -1
#define leftIdx 6
#define rightIdx 2
#define upIdx 0

using namespace std;

deque<int> wheel[4];

int K = 0;
int score = 1;
int answer = 0;

void leftWheel(int wheelNum, int left, int direction)
{
	for (int i = wheelNum - 1; i >= 0; i--)
	{
		if (wheel[i][rightIdx] != left)
		{
			left = wheel[i][leftIdx];
			if (direction == ClockWise)
			{
				wheel[i].push_front(wheel[i].back());
				wheel[i].pop_back();
				direction = CounterClockWise;
			}
			else if (direction == CounterClockWise)
			{
				wheel[i].push_back(wheel[i].front());
				wheel[i].pop_front();
				direction = ClockWise;
			}
		}
		else
		{
			break;
		}
	}
}

void rightWheel(int wheelNum, int right, int direction)
{
	for (int i = wheelNum + 1; i < 4; i++)
	{
		if (wheel[i][leftIdx] != right)
		{
			right = wheel[i][rightIdx];
			if (direction == ClockWise)
			{
				wheel[i].push_front(wheel[i].back());
				wheel[i].pop_back();
				direction = CounterClockWise;
			}
			else if (direction == CounterClockWise)
			{
				wheel[i].push_back(wheel[i].front());
				wheel[i].pop_front();
				direction = ClockWise;
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char a = ' ';

			cin >> a;
			wheel[i].push_back(a-'0');
		}
	}
	cin >> K;

	while (K--)
	{
		int wheelNum = 0;
		int direction = 0;

		cin >> wheelNum >> direction;

		wheelNum -= 1;
		int left = wheel[wheelNum][leftIdx];
		int right = wheel[wheelNum][rightIdx];

		if (direction == ClockWise)
		{
			wheel[wheelNum].push_front(wheel[wheelNum].back());
			wheel[wheelNum].pop_back();
			direction = CounterClockWise;
		}
		else if (direction == CounterClockWise)
		{
			wheel[wheelNum].push_back(wheel[wheelNum].front());
			wheel[wheelNum].pop_front();
			direction = ClockWise;
		}

		leftWheel(wheelNum, left, direction);
		rightWheel(wheelNum, right, direction);
	}

	for (int i = 0; i < 4; i++)
	{
		if (wheel[i][upIdx] == Smag)
		{
			answer += score;
		}
		score *= 2;
	}

	cout << answer << '\n';
}