// 피보나치 수 6
// n이 주어졌을 때, n번째 피보나치 수를 구하라.


// 내 답안1
/*
C(i) =	[fib(i-1)]
		[fib(i)  ]
C(i+1) =	[fib(i)  ]	=	[fib(i)			  ]	  [0 1]C(i)
			[fib(i+1)]		[fib(i) + fib(i-1)] = [1 1]
C(i+1) = W^i * C(1)
*/
#include <iostream>

#define MAX_N 1'000'000'000'000'000'000
#define MOD_NUM 1'000'000'007
#define ULLint unsigned long long int

using namespace std;

typedef struct Matrix2x1
{
	ULLint x = 0;
	ULLint y = 0;
};

typedef struct Matrix2x2
{
	ULLint x1 = 1;
	ULLint x2 = 0;
	ULLint y1 = 0;
	ULLint y2 = 1;

	Matrix2x1 operator* (const Matrix2x1& a)
	{
		Matrix2x1 ans;
		ans.x = ((x1 * a.x) % MOD_NUM + (x2 * a.y) % MOD_NUM) % MOD_NUM;
		ans.y = ((y1 * a.x) % MOD_NUM + (y2 * a.y) % MOD_NUM) % MOD_NUM;
		return ans;
	}
	Matrix2x2 operator* (const Matrix2x2& a)
	{
		Matrix2x2 ans;
		ans.x1 = ((x1 * a.x1) % MOD_NUM + (x2 * a.y1) % MOD_NUM) % MOD_NUM;
		ans.x2 = ((x1 * a.x2) % MOD_NUM + (x2 * a.y2) % MOD_NUM) % MOD_NUM;
		ans.y1 = ((y1 * a.x1) % MOD_NUM + (y2 * a.y1) % MOD_NUM) % MOD_NUM;
		ans.y2 = ((y1 * a.x2) % MOD_NUM + (y2 * a.y2) % MOD_NUM) % MOD_NUM;
		return ans;
	}
};


Matrix2x2 MatPow(ULLint N, Matrix2x2& a)
{
	if (N == 1)
		return a;
	else if (N == 0)
		return Matrix2x2();
	else
	{
		Matrix2x2 mat = MatPow(N / 2, a);

		if (N % 2 == 1)
		{
			return mat * mat * a;
		}
		else
		{
			return mat * mat;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ULLint N = 0;
	Matrix2x1 c1 = {0, 1};
	Matrix2x1 ans;
	Matrix2x2 w = { 0, 1, 1, 1 };

	cin >> N;

	ans = MatPow(N - 2, w) * c1;

	if (N == 0)
		cout << c1.x << '\n';
	else if (N == 1)
		cout << c1.y << '\n';
	else
		cout << ((ans.x % MOD_NUM) + (ans.y % MOD_NUM)) % MOD_NUM << '\n';
}






// 답안 예시1 - https://www.acmicpc.net/source/56662850
// 내 답안1의 행렬 계산을, 굳이 행렬을 만들지 않고도 구현할 수 있다.
/*
#include <stdio.h>
#define Mod 1000000007
long long int n, a = 1, b = 1, c = 0, r1 = 1, r2 = 0, r3 = 1, t1, t2, t3;
int main()
{
	a = b = r1 = r3 = 1, c = r2 = 0;
	scanf("%lld", &n);
	while(n)
	{
		if(n % 2 == 1)
		{
			t1 = r1 * a + r2 * b;
			t2 = a * r2 + b * r3;
			t3 = b * r2 + c * r3;
			r1 = t1 % Mod, r2 = t2 % Mod, r3 = t3 % Mod;
		}
		t1 = a * a + b * b;
		t2 = a * b + b * c;
		t3 = b * b + c * c;
		a = t1 % Mod, b = t2 % Mod, c = t3 % Mod;
		n /= 2;
	}
	printf("%lld", r2);
	return 0;
}
*/