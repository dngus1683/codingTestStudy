// 타일 장식물
// 1x1 크기의 정사각형 1개로부터 시작해서, 직사각형의 가장 긴 변 길이만큼의 정사각형을 이어붙여 나가는 방식으로 나선 모양처럼 점점 큰 타일을 붙인 형태로 이어나간다.
// 타일의 개수 N이 주어졌을 때, N개의 타일로 구성된 직사각형의 둘레를 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 81

using namespace std;

int N = 0;
vector<long long> dp(MAX_N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << (dp[N] + dp[N - 1]) * 2 + dp[N] * 2 << '\n';
}