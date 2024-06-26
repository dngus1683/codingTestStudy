// 스도쿠
// 풀다 만 스도쿠 퍼즐이 주어질 때, 그 퍼즐을 완성하라.


// 내 답안1
#include <iostream>

using namespace std;

int row[9][10];
int column[9][10];
int square[3][3][10];
int graph[9][9];

bool Brute(int pick[9][9], int IdxI, int IdxJ)
{
	// cout << IdxI << ' ' << IdxJ << endl;
	if (IdxJ == 9 && IdxI < 9)
	{
		IdxJ = 0;
		IdxI++;
	}
	if (IdxI == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << pick[i][j];
			}
			cout << '\n';
		}
		return true;
	}
	if (pick[IdxI][IdxJ] > 0)
	{
		if (Brute(pick, IdxI, IdxJ + 1)) return true;
	}
	else 
	{
		for (int num = 1; num < 10; num++)
		{
			if (!row[IdxJ][num] && !column[IdxI][num] && !square[IdxI / 3][IdxJ / 3][num])
			{
				pick[IdxI][IdxJ] = num;
				row[IdxJ][num] = 1;
				column[IdxI][num] = 1;
				square[IdxI/3][IdxJ/3][num] = 1;
				if (Brute(pick, IdxI, IdxJ + 1)) return true;
				pick[IdxI][IdxJ] = 0;
				row[IdxJ][num] = 0;
				column[IdxI][num] = 0;
				square[IdxI/3][IdxJ/3][num] = 0;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char num = ' ';
			
			cin >> num;
			if (num == '0') continue;

			row[j][num - '0'] = 1;
			column[i][num - '0'] = 1;
			square[i / 3][j / 3][num - '0'] = 1;
			graph[i][j] = num - '0';
		}
	}

	Brute(graph, 0, 0);

}