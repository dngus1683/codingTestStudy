// 퇴사
// N일 동안의 상담 일정표가 주어진다. 각 날에는 상담 시 걸리는 일 수 Ti와 금액 Pi가 주어진다. 만약, 1일 차 때 예약된 상담이 걸리는 일 수가 3일이라면, 2, 3일 차에 예약된 상담은 진행할 수 없다.
// 최대 수익을 구하라.


// 내 답안1
// 완전 탐색
#include <iostream>
#include <vector>

#define MAX_N 16

using namespace std;

vector<pair<int, int>> table;

int N = 0;
int dp[MAX_N];

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int brute(int day, int pay, int pi)
{
	int ans = 0;
	if (day > N)
	{

		return pay - pi;
	}
	else if (day == N)
	{
		return pay;
	}
	else
	{
		for (int i = day; i < N; i++)
		{
			ans = max(ans, brute(i + table[i].first, pay + table[i].second, table[i].second));
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int T = 0;
		int P = 0;

		cin >> T >> P;
		table.push_back({ T, P });
	}
	cout << brute(0, 0, 0) << '\n';
}











// 답안 예시1 - https://www.acmicpc.net/source/51289271
// DP
/*
#include <stdio.h>

int main(void)
{
	int dp[16]={0};
	int day, cost;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&day,&cost);
		if(dp[i+day-1]<cost+dp[i-1])
			dp[i+day-1]=cost+dp[i-1];
		if(dp[i-1]>dp[i])
			dp[i]=dp[i-1];
	}
	printf("%d\n", dp[n]);
}
*/