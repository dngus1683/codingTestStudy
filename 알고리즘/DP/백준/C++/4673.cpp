// 셀프 넘버
// 양의 정수 n에 대하여 d(n)은 n과 n의 각 자리수를 더한 값이다. 이때 n은 d(n)의 생성자라고 하며, 생성자를 여러 개 가질 수도 있고, 생성자가 없는 경우도 있다.
// 생성자가 없는 경우, 예를 들어 1, 3과 같은 경우를 셀프 넘버라고 한다.
// 10000보다 작거나 같은 셀프 넘버를 모두 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 10'001

using namespace std;

bool dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < MAX_N; i++)
	{
		int dn = i;
		int num = i;

		while (num)
		{
			dn += (num % 10);
			num /= 10;
		}
		if(dn < MAX_N)
			dp[dn] = true;
	}

	for (int i = 1; i < MAX_N; i++)
	{
		if (!dp[i])
		{
			cout << i << '\n';
		}
	}
}