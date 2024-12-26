// 빙고
// 5 x 5 크기의 빙고판의 번호가 주어지고, 사회자가 부를 번호가 순서대로 주어진다.
// 몇 번째 수를 부를 때 빙고가 완성되는지를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

short bingo = 0;
int answer = 0;
int ver[5];
int hor[5];
int cro[2];
int graph[5][5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int c = 1; c <= 25; c++)
	{
		int num = 0;

		cin >> num;

		bool flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (flag)
				break;
			for (int j = 0; j < 5; j++)
			{
				if (num == graph[i][j])
				{
					ver[j]++;
					hor[i]++;
					if (i == j)
					{
						cro[0]++;
					}
					if ((i + j) == 4)
					{
						cro[1]++;
					}

					if (ver[j] == 5)
					{
						bingo++;
						ver[j] = 6;
					}
					if (hor[i] == 5)
					{
						bingo++;
						hor[i] = 6;
					}
					if (cro[0] == 5)
					{
						bingo++;
						cro[0] = 6;
					}
					if (cro[1] == 5)
					{
						bingo++;
						cro[1] = 6;
					}

					flag = true;
					break;
				}
			}
		}

		if (bingo >= 3 && answer == 0)
		{
			answer = c;
		}
	}

	cout << answer << '\n';
}


// 내 답안2
// list 활용
/*
#include <iostream>
#include <list>

using namespace std;

list<int> ver[5];
list<int> hor[5];
list<int> cro[5];
short bingo = 0;
int answer = 0;

void func(list<int> li[5], int num, int cnt)
{
	for (int j = 0; j < cnt; j++)
	{
		if (li[j].empty())
		{
			continue;
		}
		for (auto it = li[j].begin(); it != li[j].end(); it++)
		{
			if (*it == num)
			{
				li[j].erase(it);
				break;
			}
		}
		if (li[j].empty())
		{
			bingo++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int num = 0;

			cin >> num;
			hor[i].push_back(num);
			ver[j].push_back(num);

			if (i == j)
			{
				cro[0].push_back(num);
			}
			if (i + j == 4)
			{
				cro[1].push_back(num);
			}
		}
	}

	for (int i = 0; i < 25; i++)
	{
		int num = 0;

		cin >> num;

		func(ver, num, 5);
		func(hor, num, 5);
		func(cro, num, 2);

		if (bingo >= 3 && answer == 0)
		{
			answer = i + 1;
		}
	}

	cout << answer << '\n';
}
*/