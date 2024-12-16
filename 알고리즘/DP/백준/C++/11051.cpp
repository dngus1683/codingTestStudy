// 이항 계수2
// 자연수 N과 K가 주어졌을 때 이항계수 (N K)를 10,007로 나눈 나머지를 구하라.


// 내 답안1
#include <iostream>

#define MOD_NUM 10'007
#define MAX_N 1'001
#define ull unsigned long long

using namespace std;

ull N = 0;
ull K = 0;
int dp[MAX_N][MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD_NUM;
		}
	}
	cout << dp[N][K] << '\n';

}
