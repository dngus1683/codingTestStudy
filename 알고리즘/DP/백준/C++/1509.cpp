// 팰린드롬 분할
// 문자열 S가 주어진다. 해당 문자열을 팰린드롬의 집합으로 나눌 때, 집합의 원소 개수의 최솟값을 구하라.


// 내 답안1
// 완전 탐색 알고리즘. -> 시간 초과
/*
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321

using namespace std;

inline int min(const int& a, const int& b)
{
	return (a < b ? a : b);
}

bool IsPalindrome(string s1, const int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		if (s1[i] != s1[length - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int Brute(string& s, int start, int length, int cnt)
{
	if (start == length)
	{
		return cnt;
	}

	int ans = INF;

	for (int j = 1; j <= length - start; j++)
	{
		string sub = s.substr(start, j);
		if (IsPalindrome(sub, j))
		{
			ans = min(ans, Brute(s, start + j, length, cnt + 1));
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ans = INF;
	string S = "";

	cin >> S;

	cout << Brute(S, 0, S.size(), 0) << '\n';
}
*/



// 내 답안2
// dp
// 내 답안1과 같은 완전 탐색에서, 중복되는 계산을 table에 저장하여 시간 초과를 극복.
#include <iostream>
#include <string>
#include <algorithm>

#define INF 987654321
#define MAX_LENGTH 2501

using namespace std;

int dp[MAX_LENGTH][MAX_LENGTH];

bool palendrome(int start, int end, string& s)
{
	end--;
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		else
		{
			start++;
			end--;
		}
	}
	return true;
}

void recursive(int start, int cnt, string& s)
{
	for(int i=cnt; i>0; i--)
	{
		if (palendrome(start, start + i, s))
		{
			dp[start][start + i - 1] = 1;
			if (i != cnt)
			{
				if (dp[start + i][s.length() - 1] == INF)
					recursive(start + i, cnt - i, s);
				dp[start][start + cnt - 1] = min(dp[start][start + cnt - 1], dp[start][start + i - 1] + dp[start + i][start + cnt - 1]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s = "";

	cin >> s;

	fill(&dp[0][0], &dp[MAX_LENGTH - 1][MAX_LENGTH], INF);

	recursive(0, s.length(), s);

	cout << dp[0][s.length() - 1] << endl;
}