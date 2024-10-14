// 안녕
// N명에게 최대 1번 감사인사를 할 때, i번 사람에게 인사할 때 L[i]만큼 체력을 잃고 J[i]만큼 기쁨을 얻는다. 
// 주어진 체력 내에서 얻을 수 있는 최대 기쁨을 구하라.


// 내 답안1
// 배낭 문제
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 21

using namespace std;

vector<pair<int, int>> VINFO(MAX_N);
int dp[MAX_N][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int L = 0;

		cin >> L;
		VINFO[i].first = L;
	}
	for (int i = 0; i < N; i++)
	{
		int J = 0;

		cin >> J;
		VINFO[i].second = J;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i == 0)
			{
				if (VINFO[i].first <= j)
				{
					dp[i][j] = VINFO[i].second;
				}
				else
				{
					continue;
				}
			}
			else
			{
				if (VINFO[i].first > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], VINFO[i].second + dp[i - 1][j - VINFO[i].first]);
				}
			}
		}
	}
	cout << dp[N - 1][99] << endl;
}





// 답안 예시1 - https://www.acmicpc.net/source/34395933
// 보다 더 간단하게 구현
/*
#include <stdio.h>
#include <algorithm>

int n, l[21], j[21];
int dt[101];

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &l[i]);
	for(int i=0; i<n; i++) scanf("%d", &j[i]);
	for(int i=0; i<n; i++) {
		for(int k=100; k>l[i]; k--) dt[k]=std::max(dt[k], dt[k-l[i]]+j[i]);
	}
	printf("%d", dt[100]);
}
*/