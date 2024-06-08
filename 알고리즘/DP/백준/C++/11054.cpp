// 가장 긴 바이토닉 부분 수열
// 어떤 수 Sk를 기준으로 S1<S2< .. <Sk>SK+1>Sk+2..>Sn 처럼 증가하다 감소하는 형태의 수열을 바이토닉 수열이라 한다.
// 수열 A가 주어질 때, 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 1'000

using namespace std;

int arr[MAX_N];
int dp[MAX_N][2];

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0][0] = 1;
	dp[N - 1][1] = 1;

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}
	for (int i = N-2; i >= 0; i--)
	{
		dp[i][1] = 1;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dp[i][0] + dp[i][1] - 1);
	}

	cout << ans << '\n';
}