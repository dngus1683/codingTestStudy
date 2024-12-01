// 팰린드롬인지 확인하기
// 알파벳 소문자로만 이루어진 단어가 주어질 때, 이 단어가 팰린드롬인지 확인하라.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

bool answer = 1;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			answer = 0;
			break;
		}
	}
	cout << answer << '\n';
}