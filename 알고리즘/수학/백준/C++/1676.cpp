// 팩토리얼 0의 개수
// N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하라.


// 내 답안1
// 팩토리얼은 숫자들의 순차적 곱이며, 뒷 자리 수가 0이 되기 위해서는 2와 5의 곱 밖에 없다.
// 때문에, 팩토리얼 계산 시 2와 5가 곱해지는 수를 세면 된다.
#include <iostream>

using namespace std;

int log(int num, int std)
{
	int cnt = 0;
	while ((num >= std) && (num % std == 0))
	{
		num /= std;
		cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, ev = 0, ten = 0, five = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			ev += log(i, 2);
		}
		if (i % 5 == 0)
		{
			five += log(i, 5);
		}
	}

	cout << (ev > five ? five : ev) << '\n';
}







// 답안 예시1 - https://www.acmicpc.net/source/50525183
// 내 답안1과 같은 방식이지만, 한 가지 더 고려한 것은, 1~10 의 인수 중 2는 항상 5보다 개수가 많다.
// 때문에 2와 5가 곱해져 10이 되는 개수는 5의 개수가 결정하기 때문에 5의 거듭제곱 수에 대해서만 구하면 된다.
// #include<stdio.h>
// int main()
// {
//		int n; scanf("%d", &n); n /= 5; printf("%d", n + n / 5 + n / 25);
// }

