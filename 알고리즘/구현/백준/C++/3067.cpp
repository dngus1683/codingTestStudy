// Coins
// 동전의 종류가 주어질 때, 주어진 금액을 만드는 모든 경우의 수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 21
#define MAX_M 10'001

using namespace std;

int T = 0;
int N = 0;
int M = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		vector<int> Coins;
		vector<int> dp(MAX_M);
		dp[0] = 1;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int coin = 0;

			cin >> coin;
			Coins.push_back(coin);
		}
		cin >> M;

		for (int i = 0; i < Coins.size(); i++)
		{
			for (int j = Coins[i]; j <= M; j++)
			{
				dp[j] += dp[j - Coins[i]];
			}
		}

		cout << dp[M] << endl;
	}
}