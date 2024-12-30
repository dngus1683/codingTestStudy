// 슈퍼 소수
// 소수 중에서 소수 번째로 작은 소수들을 슈퍼 소수라 하자. 정수 n이 주어질 때, n번째로 작은 슈퍼 소수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 500000

using namespace std;

int T = 0;
bool IsNotPrime[MAX_N];
vector<int> primes;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < MAX_N; i++)
	{
		if (!IsNotPrime[i])
		{
			primes.push_back(i);
			for (int j = i + i; j < MAX_N; j += i)
			{
				IsNotPrime[j] = true;
			}
		}
	}

	cin >> T;
	while (T--)
	{
		int num = 0;

		cin >> num;

		cout << primes[primes[num-1]-1] << '\n';
	}
}