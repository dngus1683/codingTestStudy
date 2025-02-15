// 아름다운 문자열
// 문자열 S와 T가 주어진다. T는 목표하는 문자열이며 이는 모든 문자가 서로 다르다. S의 문자 순서에 맞춰 문자를 골라내 T를 만들 때, 만들 수 있는 T의 최대 개수를 구하라.
// 이 때 한 번 T를 만드는데 사용한 문자들은 다시 사용할 수 없다.


// 내 답안1
#include <iostream>
#include <string>

#define MAX_S 1'000'001

using namespace std;

string S = "";
string T = "";
int dp[MAX_S];
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;
	cin >> T;

	for (int idxT = 0; idxT < T.length(); idxT++)
	{
		int preCnt = 0;
		for (int idxS = 0; idxS < S.length(); idxS++)
		{
			if (idxT == 0)
			{
				if (S[idxS] == T[idxT])
				{
					dp[idxS] = idxT + 1;
				}
			}
			else
			{
				if (S[idxS] == T[idxT])
				{
					if (preCnt > 0)
					{
						dp[idxS] = idxT + 1;
						preCnt--;
					}
					else
					{
						dp[idxS] = 0;
					}
				}
				else if (dp[idxS] == idxT)
				{
					preCnt++;
				}
			}
		}
	}
	for (int i = 0; i < S.length(); i++)
	{
		if (dp[i] == T.length())
		{
			answer++;
		}
	}
	cout << answer << '\n';

}