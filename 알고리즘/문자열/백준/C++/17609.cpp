// 회문
// 회문 == 펠린드롬, 유사회문 == 한 문자 제거 시 펠린드롬
// 문자가 주어졌을 때, 회문인지 유사회문인지 일반 단어인지 구분하라.


// 내 답안1
#include <iostream>

#define PALIN 0
#define SIM 1
#define NONE 2

using namespace std;

int T = 0;
string s = "";

bool IsPaline(string& s, int& start, int& end)
{
	while (start <= end)
	{
		if(s[start] != s[end])
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> s;

		int start = 0;
		int end = s.length() - 1;

		if (IsPaline(s, start, end))
		{
			cout << PALIN << '\n';
			continue;
		}
		else
		{
			int start2 = start + 1;
			int end2 = end - 1;
			if (IsPaline(s, start2, end) || IsPaline(s, start, end2))
			{
				cout << SIM << '\n';
			}
			else
			{
				cout << NONE << '\n';
			}
		}
	}
}
