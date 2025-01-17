// 공약수
// 두 수가 주어질 때, 두 수가 최소공배수, 최대 공약수가 되는 수의 쌍 중, 두 수의 합이 최소가 되는 쌍을 출력하라.


// 내 답안1
#include <iostream>

#define INF 200'000'010
#define ull unsigned long long 

using namespace std;

ull gcd = 0;
ull lcm = 0;
ull ansA = 0;
ull ansB = 0;
ull sumOfTwoAns = INF;

ull calGCD(ull A, ull B)
{
	if (B == 0)
	{
		return A;
	}

	return calGCD(B, A % B);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> gcd >> lcm;

	ull gcdXscm = gcd * lcm;
	ull A = gcd;

	while (true)
	{
		ull B = gcdXscm / A;
		bool flag = gcdXscm % A;

		if (A > B)
		{
			break;
		}

		if (((B % gcd) == 0) && !flag && calGCD(A, B) == gcd)
		{
			if ((A + B) < sumOfTwoAns)
			{
				ansA = A;
				ansB = B;
				sumOfTwoAns = A + B;
			}
		}

		A += gcd;
	}

	cout << ansA << ' ' << ansB << '\n';
}




// 답안 예시1 - https://www.acmicpc.net/source/55915578
/*
#include <stdio.h>
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	int A, B, a, b;
	scanf("%d %d", &A, &B);
	B /= A;
	for (int i = 1; i*i <= B; i++)
		if (B % i == 0 && gcd(i, B/i) == 1){
			a = i;
			b = B/i;
		}
	printf("%d %d", a*A, b*A);
}
*/