// 카드 구매하기
// i장이 들어있는 카드 팩의 각 가격 Pi가 주어진다. 정확히 N개 구매하기 위해 지불해야 하는 최댓값을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 1'001

using namespace std;

int N = 0;
int P[MAX_N];
int dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[j] + P[i-j]);
		}
	}

	cout << dp[N] << '\n';
}