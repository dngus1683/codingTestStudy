// 색종이 만들기
// N x N 크기의 색종이에는 각 위치에 파란색 or 하얀색으로 칠해져 있다. 해당 색종이가 정사각형 크기의 같은 색으로만 칠해져 있을 때까지 절반씩 잘라갈 때, 최종적으로 만들어지는 파란색, 하얀색 정사각형의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 128

using namespace std;

int white = 0, blue = 0;
int graph[MAX_N][MAX_N];

bool IsFilled(int x, int y, int s)
{
	for (int i = x; i < x+s; i++)
	{
		for (int j = y; j < y + s; j++)
		{
			if (i == x && j == y) continue;
			if (graph[i][j] != graph[x][y])
				return false;
		}
	}
	return true;
}

void Sol(int x, int y, int s)
{
	if (!IsFilled(x, y, s))
	{
		s /= 2;
		Sol(x, y, s);
		Sol(x + s, y, s);
		Sol(x, y + s, s);
		Sol(x + s, y + s, s);
	}
	else
	{
		if (graph[x][y] == 1)
			blue++;
		else
			white++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	Sol(0, 0, N);

	cout << white << '\n' << blue << '\n';

}