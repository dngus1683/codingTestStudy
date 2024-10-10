// 포도주 시식
// 각기 다른 양의 포도주 n개가 일렬로 나열되어 있다. 연속으로 놓여 있는 3잔을 모두 마실 수 없을 때, 최대한 먹을 수 있는 포도주의 양을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10'001

using namespace std;

int dp[MAX_N][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	int answer = 0;
	vector<int> vec;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int mount = 0;

		cin >> mount;
		vec.emplace_back(mount);
	}
	dp[0][0] = vec[0]; dp[0][1] = vec[0];
	dp[1][0] = vec[1]; dp[1][1] = vec[0] + vec[1];
	dp[2][0] = vec[0] + vec[2]; dp[2][1] = vec[1] + vec[2];

	answer = max(max(dp[1][1], dp[2][0]), dp[2][1]);

	for (int i = 3; i < n; i++)
	{
		dp[i][0] = max(max(dp[i - 3][0], dp[i - 3][1]), max(dp[i - 2][0], dp[i - 2][1])) + vec[i];
		dp[i][1] = dp[i - 1][0] + vec[i];
		answer = max(answer, max(dp[i][0], dp[i][1]));
	}

	cout << answer << endl;

}









// 답안 예시 - https://www.acmicpc.net/source/56827987
// 
/*
#include <cstdio>

#define m(a,b) a>b?a:b

int main() {
	int n,a{0},b{0},c{0};
	scanf("%d",&n);
	while(n--){
		int x,t{a};
		scanf("%d",&x);
		a=m(a,(m(b,c)));
		c=b+x;
		b=t+x;
	}
	printf("%d",m(a,(m(b,c))));
}
*/