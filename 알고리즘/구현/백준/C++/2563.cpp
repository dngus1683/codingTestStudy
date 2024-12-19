// 색종이
// 100 x 100 크기의 흰 도화지 위에 10 x 10 크기의 검은색 색종이를 여러 개 붙인다. 
// 흰 도화지 위의 검은색 영역의 넓이를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 101

using namespace std;

int N = 0;
int answer = 0;
bool board[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int startI = 0;
		int startJ = 0;

		cin >> startJ >> startI;
		for (int ii = startI; ii < startI+10; ii++)
		{
			for (int jj = startJ; jj < startJ+10; jj++)
			{
				board[ii][jj] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (board[i][j])
			{
				answer++;
			}
		}
	}

	cout << answer << '\n';
}