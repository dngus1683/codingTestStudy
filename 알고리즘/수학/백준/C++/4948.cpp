// 베르트랑 공준
// 자연수 n에 대하여 n~2n에는 적어도 하나의 소수가 존재한다는 명제가 베르트랑 공준이다.
// n이 주어졌을 때, n보다 크고 2n보다 작거나 같은 소수의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 123457

using namespace std;

int T = 0;
int N = 0;
bool IsNotPrime[MAX_N*2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	IsNotPrime[0] = IsNotPrime[1] = true;

	for (int i = 2; i <= MAX_N*2; i++)
	{
		for (int j = i + i; j <= MAX_N*2; j += i)
		{
			IsNotPrime[j] = true;
		}
	}

	while (true)
	{
		int answer = 0;

		cin >> N;

		if (N == 0) break;
		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (!IsNotPrime[i]) answer++;
		}
		cout << answer << '\n';
	}
}