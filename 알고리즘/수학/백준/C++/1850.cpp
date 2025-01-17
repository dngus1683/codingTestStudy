// 최대공약수
// 1로만 이루어져 있는 두 개의 수가 주어진다. 두 수의 최대 공약수를 구하라.


// 내 답안1
#include <iostream>

#define ull unsigned long long

using namespace std;

ull A;
ull B;
ull answer;

ull gcd(ull a, ull b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B;

	answer = gcd(A, B);

	for (ull i = 0; i < answer; i++)
	{
		cout << 1;
	}
	cout << '\n';
}



