// 피보나치 수 2
// n이 주어졌을 때 n번째 피보나치 수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int n = 0;
unsigned long long dp[91];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n - 1] << '\n';
}