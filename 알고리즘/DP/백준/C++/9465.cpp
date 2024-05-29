// 스티커
// 2xn 으로 배치된 스티커는 각각 점수를 가진다. 한 스티커를 떼내면 그 스티커와 변이 맞닿아 있는 스티커들은 사용할 수 없게 된다.
// 임의의 개수의 스티커를 떼냈을 때, 가장 높은 점수를 구하라.



// 내 답안1
#include <iostream>
#include <memory.h>

#define MAX_N 100'001

using namespace std;

int graph[MAX_N][2];
int dp[MAX_N][2];

inline int max(const int a, const int b)
{
	return (a > b ? a : b);
}
inline int max(const int a, const int b, const int c)
{
	return max(a,max(b,c));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int TC = 0;
	
	cin >> TC;
	while (TC--)
	{
		int N = 0;

		cin >> N;
		for(int j=0; j<2; j++)
			for (int i = 0; i < N; i++)
			{
				cin >> graph[i][j];
			}

		dp[0][0] = graph[0][0];
		dp[0][1] = graph[0][1];
		dp[1][0] = dp[0][1] + graph[1][0];
		dp[1][1] = dp[0][0] + graph[1][1];

		for (int i = 2; i < N; i++)
		{
			dp[i][0] = max(dp[i-1][1], dp[i-2][0], dp[i - 2][1]) + graph[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0], dp[i - 2][1]) + graph[i][1];
		}
		cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
	}

}