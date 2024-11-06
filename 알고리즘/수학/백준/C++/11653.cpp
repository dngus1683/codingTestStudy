// 소인수분해
// 정수 N이 주어졌을 때, 소인수분해하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 10'000'000

using namespace std;

int N = 0;
vector<bool> IsPrime(MAX_N, true);
vector<int> PrimeNumbers;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	IsPrime[0] = IsPrime[1] = false;
	for (int i = 2; i <= N; i++)
	{
		PrimeNumbers.push_back(i);
		for (int j = i + i; j <= N; j += i)
		{
			IsPrime[j] = false;
		}
	}

	int idx = 0;
	while (N > 1)
	{
		if (N % PrimeNumbers[idx] == 0)
		{
			cout << PrimeNumbers[idx] << '\n';
			N = N / PrimeNumbers[idx];
		}
		else
		{
			idx++;
		}
	}
}