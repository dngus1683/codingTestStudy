// 균형잡힌 세상
// 문자열이 주어졌을 때, () 와 []이 균형이 잡혀있는지 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int sm = 0, la=0, flag = 1;
		string s;
		stack<char> st;

		getline(cin, s, '.');
		cin.ignore();

		if (s.length() == 0) break;

		for (int i = 0; i < s.length(); i++)
		{
			char top = (st.empty() ? '-1' : st.top());

			if (s[i] == '(' || s[i] == '[')
			{
				st.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (top == '(')
				{
					st.pop();
				}
				else
				{
					flag = 0;
					break;
				}
			}
			else if (s[i] == ']' )
			{
				if (top == '[') st.pop();
				else
				{
					flag = 0;
					break;
				}
			}
		}

		if (flag && st.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}