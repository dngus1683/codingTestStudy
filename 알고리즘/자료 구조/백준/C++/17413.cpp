// 단어 뒤집기2
// 주어지는 문자열 내에 모든 단어들을 뒤집어라. 이때, <>안의 문자열은 뒤집지 않는다.


// 내 답안1
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

bool flag = false;
int idx = 0;
string s = "";
string answer = "";
queue<char> q;
stack<char> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	getline(cin, s);

	while (idx != s.length())
	{
		if (s[idx] == '<')
		{
			while (!stk.empty())
			{
				answer.push_back(stk.top());
				stk.pop();
			}
			answer.push_back(s[idx]);

			flag = true;
		}
		else if(s[idx] == ' ')
		{
			if (flag)
			{
				q.push(s[idx]);
			}
			else
			{
				while (!stk.empty())
				{
					answer.push_back(stk.top());
					stk.pop();
				}
				answer.push_back(s[idx]);
			}
		}
		else if (s[idx] == '>')
		{
			while (!q.empty())
			{
				answer.push_back(q.front());
				q.pop();
			}
			answer.push_back(s[idx]);
			flag = false;
		}
		else
		{
			if (!flag)
			{
				stk.push(s[idx]);
			}
			else
			{
				q.push(s[idx]);
			}
		}
		idx++;
	}
	while (!q.empty())
	{
		answer.push_back(q.front());
		q.pop();
	}
	while (!stk.empty())
	{
		answer.push_back(stk.top());
		stk.pop();
	}
	cout << answer << '\n';
}