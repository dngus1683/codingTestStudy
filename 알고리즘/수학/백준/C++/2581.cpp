// 소수
// 자연수 M과 N이 주어질 때, M 이상 N 이하의 소수의 합과 가장 작은 소수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M = 0;
int N = 0;
int sum = 0;
int mn = 10001;
bool IsNotPrime[10001];
vector<int> Prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M;
	cin >> N;

	IsNotPrime[0] = IsNotPrime[1] = true;
	for (int i = 2; i <= N; i++)
	{
		if (!IsNotPrime[i])
		{
			for (int j = i + i; j <= N; j += i)
			{
				IsNotPrime[j] = true;
			}
			if (i >= M)
			{
				sum += i;
				Prime.push_back(i);
			}
		}
	}
	if (Prime.empty())
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << sum << '\n' << Prime[0] << '\n';
	}
}
