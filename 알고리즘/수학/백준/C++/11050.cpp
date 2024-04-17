// 이항 계수1
// 자연수 N과 정수 K가 주어졌을 때 이항계수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int fac(int a)
{
	int n=1;
	for (int i = 1; i <= a; i++)
		n *= i;
	return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, a, b, c;

	cin >> n >> k;

	cout << fac(n) / (fac(n - k) * fac(k)) << '\n';
}


