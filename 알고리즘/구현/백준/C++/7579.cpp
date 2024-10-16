// 앱
// 스마트폰에 실행 중인 앱들의 메모리 정보와 다시 실행할 때 드는 비용, 그리고 새로 실행할 앱의 필요 메모리 정보가 주어진다.
// 새로운 앱을 실행하기 위해 기존의 앱을 비활성화 할 때, 최소 비용을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 101
#define MAX_M 10'000'001
#define MAX_C 1'000'000'001

using namespace std;

int dp[2][MAX_M];

vector<pair<int, int>> VINFO(MAX_N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int mem = 0;
		cin >> mem;

		VINFO[i].first = mem;
	}
	for (int i = 0; i < N; i++)
	{
		int cost = 0;
		cin >> cost;

		VINFO[i].second = cost;
	}

	fill(&dp[0][0], &dp[1][MAX_M], MAX_C);
	bool flag = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j <= M; j++)
		{
			if (i == 0)
			{
				if(j <= VINFO[i].first)
					dp[flag][j] = VINFO[i].second;
			}
			else
			{
				if (j <= VINFO[i].first)
				{
					dp[flag][j] = min(dp[!flag][j], VINFO[i].second);
				}
				else
				{
					dp[flag][j] = min(dp[!flag][j], dp[!flag][j - VINFO[i].first] + VINFO[i].second);
				}
			}
		}
		flag = !flag;
	}


	cout << dp[!flag][M] << endl;
}
