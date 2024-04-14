// 괄호
// 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
// 이때 문자열이 올바르게 열리고 닫히면 이를 올바른 괄호 문자열(Valid PS, VPS)라 부른다.
// 이 VPS를 VPS로 감싸면 이 역시 VPS이며 VPS+VPS역시 VPS다. ex) (())() : VPS
// 입력으로 주어진 PS가 VPS인지 아닌지 판별하라.


// 내 답안1
#include <iostream>
#include <cstring>

#define MAX_N 51

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;

	cin >> T;
	while (T--)
	{
		int cnt = 0;
		string ps;

		cin >> ps;

		for (int i = 0; i < ps.length(); i++)
		{
			if (ps[0] == ')')
			{
				cnt = 1;
				break;
			}
			if (cnt == -1)
			{
				break;
			}
			if (ps[i] == '(') cnt++;
			if (ps[i] == ')') cnt--;
		}

		if (!cnt) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}