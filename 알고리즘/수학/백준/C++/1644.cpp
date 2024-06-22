// 소수의 연속합
// 자연수 N이 주어질 때, 연속된 소수(prime number)의 합으로 나타낼 수 있는 경우의 수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 4'000'001

using namespace std;

int IsPrime[MAX_N];
vector<int> prime;

void CalPrime(const int N)
{
	for (int i = 2; i <= N; i++)
	{
		if (IsPrime[i] != 1)
		{
			prime.push_back(i);
			for (int j = i + i; j <= N; j = j + i)
			{
				IsPrime[j] = 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int ans = 0;

	cin >> N;

	CalPrime(N);

	for (int start = 0; start < prime.size(); start++)
	{
		int total = 0;
		for (int idx = start; idx < prime.size(); idx++)
		{
			total += prime[idx];
			if (total == N)
			{
				ans++;
				break;
			}
			else if (total > N)
			{
				break;
			}
		}
	}

	cout << ans << '\n';

}