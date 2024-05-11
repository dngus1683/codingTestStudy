// 파도반 수열
// 한 변의 길이가 1인 정삼각형을 시작으로, 나선에서 가장 긴 변의 길이를 k라 할 때, 그것을 한 변으로 가지는 정삼각형을 추가한다.
// 이때, 생성되는 정삼각형의 변의 길이의 수열을 파도반 수열 P(N)이라 한다. N이 주어졌을 때, P(N)을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 101

using namespace std;

unsigned long long int PArr[MAX_N] = { 0, };

void func ()
{
	PArr[1] = 1;
	PArr[2] = 1;
	PArr[3] = 1;
	PArr[4] = 2;

	for (int i = 5; i < MAX_N; i++)
	{
		PArr[i] = PArr[i - 1] + PArr[i - 5];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;

	func();
	while (TestCase--)
	{
		int N = 0;

		cin >> N;

		cout << PArr[N] << '\n';
	}

	
}











// 답안 예시 - https://www.acmicpc.net/source/36102712
/*
#include <stdio.h>


int main()
{
	int t, n, i;
	long long d[101] = { 0,1,1,1 };

	for (i = 4; i < 101; i++)
		d[i] = d[i - 2] + d[i - 3];
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
}
*/