// 카잉 달력
// 종말의 해를 <M:N>이라 한다. 각 해는 <x:y>로 표기하며, 다음 해는 x < M 일 때, y < N 일 때 <x+1:y+1>로 표기하며 만약 해당 수를 넘겼을 경우 다시 1로 돌아간다.
// M, N, x, y가 주어질 때, 지금은 몇 번째 해인지 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 40001

using namespace std;

int M = 0;
int N = 0;
int x = 0;
int y = 0;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		cin >> M >> N >> x >> y;

		int lcmMN = (M > N ? lcm(M, N) : lcm(N, M));
		while(x!=y)
		{
			if (x > y)
			{
				y += N;
			}
			else if(x < y)
			{
				x += M;
			}
			else
			{
				break;
			}

			if (x > lcmMN || y > lcmMN) break;

		}
		cout << (x==y ? x : -1) << '\n';
	}
}