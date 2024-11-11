// 연속합
// n개의 정수로 이루어진 임의의 수열이 있다. 이 중 연속된 몇 개의 수의 합의 최댓값을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 100'001

using namespace std;

inline int max(const int a, const int b)
{
	return (a > b ? a : b);
}

int N = 0;
int answer = 0;
int nums[MAX_N];
int dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for(int i=0; i<N; i++)
	{ 
		cin >> nums[i];
	}

	answer = dp[0] = nums[0];
	
	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		answer = max(answer, dp[i]);
	}
	cout << answer << '\n';
}