// 세로읽기
// 영어 대문자, 소문자, 숫자로 이루어진 단어 5개가 주어진다.
// 단어를 세로로 읽은 결과를 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int MX = 0;
string s[5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		cin >> s[i];

		MX = max(MX, (int)s[i].length());
	}

	for (int i = 0; i < MX; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= s[j].length() - 1)
			{
				cout << s[j][i];
			}
		}
	}

	cout << '\n';
}
