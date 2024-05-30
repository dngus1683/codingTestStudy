// 가장 긴 증가하는 부분 수열
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
// 예를 들어, 수열 A = { 10, 20, 10, 30, 20, 50 } 인 경우에 가장 긴 증가하는 부분 수열은 A = { 10, 20, 10, 30, 20, 50 } 이고, 길이는 4이다.


// 내 답안1
// 재귀함수를 활용하여 품. 시간초과.
/*
#include <iostream>
#include <vector>

#define MAX_N 1'000

using namespace std;

int N = 0;
int ans = 0;
vector<int> NumArr;

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

void combination(int start, vector<int>& pick, int count)
{
	int MaxNum = 0;
	for (int i = start + 1; i < N; i++)
	{
		if ((count == 0) && (i != (N - 1)) && (NumArr[i] > NumArr[i + 1])) continue;
		if (pick.empty() || (!pick.empty() && pick.back() < NumArr[i]))
		{
			if (NumArr[i] >= MaxNum && MaxNum != 0) continue;
			MaxNum = NumArr[i];
			pick.push_back(NumArr[i]);
			combination(i, pick, count + 1);
			pick.pop_back();
		}
	}
	ans = max(ans, count);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> pick;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		NumArr.push_back(num);
	}

	combination(-1, pick, 0);

	cout << ans << '\n';

}
*/



// 내 답안2
// dp로 풀기
#include <iostream>
#include <vector>

#define MAX_N 1'000

using namespace std;

int N = 0;
int ans = 0;
int dp[MAX_N];
vector<int> NumArr;

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		NumArr.push_back(num);
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (NumArr[i] > NumArr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}