// 마인크래프트
// 집을 짓기 위해서는 땅을 평평하게 하는 땅 고르기 작업을 해야 한다. (i,j) 좌표에서 두가지 행동을 할 수 있는데
// 1. (i, j) 의 가장 위에 있는 블록을 제거하여 인벤토리에 저장 : 2초
// 2. 인벤토리에서 블록을 꺼내어 (i, j)의 맨 위에 놓음: 1초
// 땅 고르기를 할 때 걸리는 최소 시간과 땅 높이를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_NM 501
#define MAX_B 257

using namespace std;

int block[MAX_B] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, b, time = 987654321, height;

	cin >> n >> m >> b;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			int a;

			cin >> a;
			block[a]++;
		}
	for (int i = 0; i < MAX_B; i++)
	{
		int j = 256;
		int t = 0;
		int inven = b;

		for (; j >= 0; j--)
		{
			if (j > i)
			{
				t += block[j] * (j-i) * 2;
				inven += block[j] * (j-i);
			}
			else if (j < i)
			{
				if (inven >= block[j] * (i - j))
				{
					t += block[j] * (i - j);
					inven -= block[j] * (i - j);
				}
				else break;
			}
		}		
		if (t <= time && j == -1)
		{
			time = t;
			height = i;
		}
	}

	cout << time << ' ' << height << '\n';

}