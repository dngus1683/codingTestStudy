// 정수 a를 k로 만들기
// 양의 정수 A를 K로 변경하려고 한다.
// 연산 1: 정수 A에 1을 더함.
// 연산 2: 정수 A에 2를 곱함.
// A를 K로 변경하는데 필요한 최소 연산 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 1'000'001

using namespace std;

int A = 0;
int K = 0;
int dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> K;
	
	dp[A] = 0;
	for (int i = A+1; i <= K; i++)
	{
		if (i % 2)
		{
			dp[i] = dp[i-1] + 1;
		}
		else
		{
			if (i / 2 >= A)
				dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
			else
				dp[i] = dp[i - 1] + 1;

		}
	}

	cout << dp[K] << '\n';
}