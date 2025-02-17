// 팩토리얼 0의 개수
// 가장 끝의 0 개수가 M인 N! 중에서 가장 작은 N을 구하라.


// 내 답안1
// 팩토리얼의 끝 0 개수는, 해당 수를 소인수 분해 했을 때 5의 개수를 의미한다.
// 0은 2*5를 통해서 만들어지는데, 곱해진 2의 개수는 5를 아득히 뛰어넘기 때문이다.
#include <iostream>

#define MAX_M 100'000'001

using namespace std;

int N = 5;
int M = 0;
int answer = -1;

int func(int n)
{
	int cnt = 0;
	int five = 5;
	while (five <= n)
	{
		cnt += n / five;

		five *= 5;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M;

	int left = 1;
	int right = 5 * M;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = func(mid);

		if (cnt < M)
		{
			left = mid + 1;
		}
		else if(cnt > M)
		{
			right = mid - 1;
		}
		else
		{
			answer = mid;
			right = mid - 1;
		}
	}

	cout << answer << '\n';
}