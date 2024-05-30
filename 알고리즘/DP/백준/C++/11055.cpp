// 가장 큰 증가하는 부분 수열
// 수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
// 예를 들어, 수열 A = { 1, 100, 2, 50, 60, 3, 5, 6, 7, 8 } 인 경우에 합이 가장 큰 증가하는 부분 수열은 A = { 1, 100, 2, 50, 60, 3, 5, 6, 7, 8 } 이고, 합은 113이다.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'000

using namespace std;

int dp[MAX_N];

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int ans = 0;
	vector<int> NumArr;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		NumArr.push_back(num);
	}

	dp[0] = NumArr[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = NumArr[i];
		for (int j = i-1; j >= 0; j--)
		{
			if (NumArr[i] > NumArr[j])
			{
				dp[i] = max(dp[i], dp[j] + NumArr[i]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}