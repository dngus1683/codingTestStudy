// 합분해
// 0~N까지의 정수 K개를 중복포함, 순서고려하여 더해서 N이 되는 경우의 수를 구하라.


// 내 답안1
#include <iostream>

#define MOD_NUM 1'000'000'000
#define MAX_N 201
#define MAX_K 201

using namespace std;

int N = 0;
int K = 0;
unsigned long long dp[MAX_N][MAX_K];

int backtracking(int targetNum, int cnt)
{

	if (cnt == 1)
	{
		dp[targetNum][cnt] = 1;
	}
	else
	{
		for (int i = 0; i <= N; i++)
		{
			if (targetNum < i) continue;
			if (dp[targetNum - i][cnt - 1] != 0)
			{
				dp[targetNum][cnt] += dp[targetNum - i][cnt - 1];
				dp[targetNum][cnt] = dp[targetNum][cnt] % MOD_NUM;
			}
			else
			{
				dp[targetNum][cnt] += backtracking(targetNum - i, cnt - 1);
				dp[targetNum][cnt] = dp[targetNum][cnt] % MOD_NUM;
			}
		}
	}
	
	return dp[targetNum][cnt];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	cout << backtracking(N, K) << '\n';

}




// 답안 예시 - https://www.acmicpc.net/source/67941271
// bottom up 방식
/*
#include <cstdio>
int main(void){
	int n,k,dp[201]= {1,};scanf("%d %d",&n,&k);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			dp[j] = (dp[j]+dp[j-1])%1000000000;
	printf("%d",dp[n]);
}
*/