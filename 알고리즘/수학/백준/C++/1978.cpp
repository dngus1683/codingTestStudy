// 소수 찾기
// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하라.


// 내 답안1
#include <iostream>

#define MAX_N 1001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, ans = 0, prime[MAX_N] = { 0, };

	prime[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		for (int j = i * 2; j < 1001; j += i)
		{
			prime[j] = 1;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;

		cin >> num;
		if (prime[num] == 0) ans++;
	}

	cout << ans << '\n';
}









// 답안 예시1 - https://www.acmicpc.net/source/49405005
// 매 입력되는 숫자마다 소수 판단
/*
#include<stdio.h>
int main()
{
	int n,h=0,a,i;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		for (i = 2; i < a; i++)
			if ((a % i) == 0) break;
		if (i == a) h++;
	}
	printf("%d", h);
}
*/