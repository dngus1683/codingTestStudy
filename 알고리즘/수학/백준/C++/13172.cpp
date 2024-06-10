// 시그마
// M개의 주사위가 있고, i번 째 주사위는 Ni면체고 모든 면이 나올 확률이 동일하다고 가정하며, 모든 면의 합은 Si다. 때문에 해당 주사위의 기댓값은 Si/Ni 이며, 해당 기댓값은 선형성을 띄므로 총 M개의 기댓값은 Si/Ni의 총 합과 같다.
// 이때, Si/Ni을 소수로 표현하면 무한소수는 중간에서 값을 끊어야 하므로 실제 값과 약간의 오차가 발생하기에 분수로 계산을 하려 하느데 이 또한 모든 주사위의 분모값이 다르므로 통분을 할 시 분모와 분자를 적당한 범위 내에서 계산할 수 없다.
// 이를 해결하기 위해 각 분수를 어떤 모듈러 상에 표현하고, 그것을 활용하여 연산을 진행하기로 한다.
// a/b => a x b^-1 mod X (X는 소수)로 표현한다. 이때 b^-1는 b의 모듈러 곱셈에 대한 역원(b x b^-1 = 1(mod X) => 페르마의 소정리에 의해 b^(X-1) = 1 (mod X) => b^(X-2) = b^-1 (mod X))이다.
// 이러한 방식으로, 덧셈, 뺄셈, 곱셈은 mod X에서 두 정수를 가지고 계산하듯이 처리하고, 나눗셈은 나누는 분수의 곱셈에 대한 역원을 구한 후, 그 역원을 mod X에서 곱하는 것으로 처리한다.
// X는 충분히 겹치지 않도록 1,000,000,007이라 할 때, 모든 주사위를 한 번씩 던졌을 때 나온 숫자들의 합의 기댓값을 구하라.


// 내 답안1
#include <iostream>

#define MODNUM 1'000'000'007
#define MAX_M 10001
#define ull unsigned long long int

using namespace std;

static ull power(ull a, ull N)
{
	if (N == 1)
		return a;
	else if (N == 0)
		return 1;
	else
	{
		ull half = power(a, N / 2);
		if (N % 2 == 1)
			return (half % MODNUM * half % MODNUM * a % MODNUM) % MODNUM;
		else
			return (half % MODNUM * half % MODNUM) % MODNUM;
	}
}

static ull IntoTheMod(ull s, ull n)
{
	return (s * power(n, MODNUM - 2)) % MODNUM;
}

static ull gcd(ull a, ull b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M = 0;
	ull ans = 0;

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		ull Ni = 0;
		ull Si = 0;

		cin >> Ni >> Si;

		ull g = gcd(Ni, Si);
		ans += IntoTheMod(Si/g, Ni/g) % MODNUM;
		ans %= MODNUM;
	}

	cout << ans << '\n';

}