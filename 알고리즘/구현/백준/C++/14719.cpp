// 빗물
// 2차원 세계의 지형이 주어진다. 비가 충분히 많이 온다고 할 때, 고이는 빗물의 총량을 구하라.


// 내 답안1
#include <iostream>

#define MAX_L 501

using namespace std;

int H = 0;
int W = 0;
int answer = 0;
bool geo[MAX_L][MAX_L];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;

	for (int j = 0; j < W; j++)
	{
		int wall = 0;

		cin >> wall;

		for (int i = 0; i < wall; i++)
		{
			geo[i][j] = true;
		}
	}

	for (int i = 0; i < H; i++)
	{
		int left = -1;

		for (int j = 0; j < W; j++)
		{
			if (geo[i][j])
			{
				if (left != -1)
				{
					answer += (j - left - 1);
				}
				left = j;
			}		
		}
	}

	cout << answer << '\n';

}
