// 이친수
// 이진수 중, 0으로 시작하지 않고, 1이 두 번 연속으로 나타나지 않는 수를 이친수라 한다. 
// N이 주어졌을 때, N자리 이친수의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 91
#define ULL unsigned long long
using namespace std;

int N = 0;
ULL dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N] << '\n';
}
