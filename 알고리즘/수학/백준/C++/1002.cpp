// 터렛
// 두 터렛의 위치 (x, y)가 주어지고, 각 터렛에서 목표물까지의 거리가 주어질 때, 목표물이 위치할 수 있는 좌표 수를 구하라.


// 내 답안1
#include <iostream>
#include <cmath>

using namespace std;

int x1 = 0;
int y11 = 0;
int x2 = 0;
int y2 = 0;
int r1 = 0;
int r2 = 0;
int TestCase = 0;

double distance(int InX1, int InY1, int InX2, int InY2)
{
	return sqrt(pow((InX1 - InX2), 2) + pow((InY1 - InY2), 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> TestCase;
	while (TestCase--)
	{
		cin >> x1 >> y11 >> r1 >> x2 >> y2 >> r2;

		if ((x1 == x2) && (y11 == y2))
		{
			if (r1 == r2) cout << -1 << '\n';
			else cout << 0 << '\n';
		}
		else
		{
			if (distance(x1, y11, x2, y2) == (double)(r1 + r2))
			{
				cout << 1 << '\n';
			}
			else if (distance(x1, y11, x2, y2) > (double)(r1 + r2))
			{
				cout << 0 << '\n';
			}
			else
			{
				if (distance(x1, y11, x2, y2) == (double)abs(r1 - r2))
				{
					cout << 1 << '\n';
				}
				else if(distance(x1, y11, x2, y2) > (double)abs(r1 - r2))
				{
					cout << 2 << '\n';
				}
				else
				{
					cout << 0 << '\n';
				}
			}
		}
	}
}