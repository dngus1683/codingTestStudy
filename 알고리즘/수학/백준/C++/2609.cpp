// 최대공약수와 최소공배수
// 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, mn,mx, gcd, lcm;

	cin >> a >> b;

	mn = (a < b ? a : b);
	mx = (a < b ? b : a);

	for (int i = mn; i > 0; i--)
	{
		if (mx % i == 0 && mn % i ==0)
		{
			gcd = i;
			break;
		}
	}

	lcm = a * b / gcd;
	cout << gcd << '\n';
	cout << lcm << '\n';
}






// 답안 예시1
// 같은 알고리즘인데, 이 답안은 for문을 굳이 거꾸로 구현하지 않아 min max 값을 구하지 않아도 된다.
/*
#include <stdio.h>

int main() {
	int a, b, i, g = 1;
	scanf("%d %d", &a, &b);
	for (i = 2; i <= a; i++) {
		if (a % i == 0 && b % i == 0) g = i;
	}
	printf("%d\n%d", g, a * b / g);
}
*/