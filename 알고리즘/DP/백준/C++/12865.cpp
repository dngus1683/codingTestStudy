// 평범한 배낭
// 준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지며, 준서의 배낭은 K개만큼의 무게만을 넣을 수 있다. 준서가 가져갈 수 있는 물건들의 가치의 최댓값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <memory.h>

#define MAX_N 101
#define MAX_K 100'001
#define MAX_W 100'001

using namespace std;

int N = 0;
int K = 0;
int dp[MAX_N][MAX_K];
vector<pair<int, int>> items;

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int W = 0;
		int V = 0;

		cin >> W >> V;
		items.push_back({ W, V });
	}


	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (j < items[i-1].first)
				dp[i][j] = dp[i - 1][j];
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i-1].first] + items[i-1].second);
			}
		}
	}
	cout << dp[N][K] << '\n';
}












// 답안 예시1 - https://www.acmicpc.net/source/30741285
// 내 답안1의 이중 for문으로 구현한 dp 간단 버전
/*
#include<ios>
int main(){
	int n,k,w,v,i=1,j; scanf("%d%d",&n,&k);
	int dp[k+1]={};
	for(;i<=n;i++){
		scanf("%d%d",&w,&v);
		for(j=k;j>=w;j--)if(dp[j-w]+v>dp[j])
			dp[j]=dp[j-w]+v;
	}
	printf("%d",dp[k]);
}
*/