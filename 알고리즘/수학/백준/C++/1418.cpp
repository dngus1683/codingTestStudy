// K-세준수
// 오세준은 어떤 자연수의 소인수중 최댓값이 K보다 크지 않을때 그 수를 K-세준수라고 부른다.
// N보다 작거나 같은 자연수 중에 K - 세준수가 총 몇 개인지 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>

#define MAX_N 100'001

using namespace std;

int N = 0;
int K = 0;
int answer = 0;
int dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> K;

	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (dp[i] == 0)
		{
			for (int j = i; j <= N; j += i)
			{
				dp[j] = i;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dp[i] <= K)
		{
			answer++;
		}
	}
	cout << answer << '\n';
}