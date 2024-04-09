// 소수 구하기
// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하라.


// 내 답안1
#include <iostream>

#define MAX_N 1000001

using namespace std;

int prime[MAX_N] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n;

	cin >> m >> n;

	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == 0)
		{
			prime[i] = 1;
			for (int j = i+i; j <= n; j += i)
			{
				prime[j] = -1;
			}
		}
	}

	for (int i = m; i <= n; i++)
	{
		if(prime[i] == 1)
			cout << i << '\n';
	}
}
