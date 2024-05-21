// RGB거리
// 1번부터 N번까지 집이 순서대로 있다. 연속되는 집들은 서로 색이 달라야 한다. 집은 RGB 세 색상 중 하나로만 칠할 수 있다.
// 각 집을 색칠하는데 드는 비용이 RGB값 별로 주어질 때, 모든 집을 칠하는데 드는 최소 비용을 구하라.


// 내 답안1
#include<iostream>

#define MAX_N 1001

using namespace std;

int RGB[MAX_N][3];
int dp[MAX_N][3];

static inline int min(const int& a, const int& b)
{
	return (a < b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
		if (i == 0)
		{
			dp[i][0] = RGB[i][0];
			dp[i][1] = RGB[i][1];
			dp[i][2] = RGB[i][2];
		}
		else
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][0];
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + RGB[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][2];
		}
	}

	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])) << '\n';

}







// 답안 예시1 - https://www.acmicpc.net/source/55728561
// 같은 방식이지만 굳이 dp 배열을 사용하지 않고 바로 계산함으로써 메모리 사용을 줄였다.
/*
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n, R, G, B, r, g, b;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &R, &G, &B);
		R += min(g, b);
		G += min(r, b);
		B += min(r, g);
		r = R;
		g = G;
		b = B;
	}
	printf("%d\n", min(min(r, g), b));
	return 0;
}
*/