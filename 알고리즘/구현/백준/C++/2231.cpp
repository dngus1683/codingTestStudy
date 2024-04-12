// 분해합
// 분해합: 본인과 각 자릿수의 총 합. ex) 245: 245+2+4+5=256
// 생성자: 자연수 M의 분해합이 N인 경우, M은 N의 생성자. ex) 245는 256의 생성자.
// 자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구하라.


// 내 답안1
// 브루트포스 알고리즘
#include <iostream>

#define MAX_N 1000001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans = 0;

	cin >> N;

	for (int i = 1; i <= MAX_N; i++)
	{
		int num = i;
		int s = num;

		while (num > 0)
		{
			s += num % 10;
			num /= 10;
		}

		if (s == N)
		{
			ans = i;
			break;
		}

	}
	cout << ans << '\n';
}