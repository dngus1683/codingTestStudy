// 01타일
// 1타일과 00타일로 만들 수 있는 길이가 N인 이진수의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 1'000'001
#define MOD 15746

using namespace std;

int N = 0;
int dp[MAX_N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD)%MOD;
	}

	cout << dp[N] << '\n';
}
