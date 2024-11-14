// 골드바흐의 추측
// 2보다 큰 모든 짝수들은 두 소수의 합으로 표현할 수 있고, 그렇게 나눈 것을 골드바흐 파티션이라 한다.
// 2보다 큰 짝수 n이 주어질 때, 두 소수의 차가 가장 작은 것을 출력하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 10'001

using namespace std;

int T = 0;
int N = 0;
bool IsNotPrime[MAX_N];
vector<int> primeNumber;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	IsNotPrime[0] = IsNotPrime[1] = true;

	for (int i = 2; i <= MAX_N; i++)
	{
		if (IsNotPrime[i] == true)
		{
			continue;
		}
		else
		{
			primeNumber.push_back(i);
		}
		for (int j = i + i; j <= MAX_N; j += i)
		{
			IsNotPrime[j] = true;
		}
	}

	cin >> T;
	while (T--)
	{
		int a = 0;
		int b = MAX_N;

		cin >> N;

		for (auto p : primeNumber)
		{
			if (p > N - p) continue;

			if (!IsNotPrime[N - p])
			{
				if (b - a > ((N - p) - p))
				{
					a = p;
					b = N - p;
				}
			}
		}

		cout << a << ' ' << b << '\n';

	}
}