// 후위 표기식
// 수식 표기법에는 일반적으로 3가지가 있다. 
// + 중위 표기법(일반적인 수식) : a+b
// + 전위 표기법: +ab
// + 후위 표기법: ab+
// 중위 표기식이 주어졌을 때, 후위 표기식으로 변환하라.


// 내 답안1
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> stk;

void ToPostfix(string& s, int start, int end)
{
	if (start == end)
	{
		stk.push(s[start]);
		return;
	}
	int BracketFlag = 0;
	int WhileFlag = 0;
	while(s[start] == '(' && s[end] == ')')
	{
		for (int i = end; i >= start; i--)
		{
			if (s[i] == ')') BracketFlag += 1;
			else if (s[i] == '(') BracketFlag -= 1;

			if (BracketFlag == 0 && i != start)
			{
				WhileFlag = 1;
				break;
			}
		}
		if (WhileFlag)
			break;
		else
		{
			start += 1;
			end -= 1;
		}
	}

	int CalIdx = end;
	BracketFlag = 0;
	for (int i = end; i >= start; i--)
	{
		if (s[i] == ')') BracketFlag += 1;
		else if(s[i] == '(') BracketFlag -= 1;

		if (BracketFlag == 0)
		{
			if ((s[i] == '*' || s[i] == '/') && CalIdx == end)
				CalIdx = i;
			else if (s[i] == '+' || s[i] == '-')
			{
				CalIdx = i;
				break;
			}
		}
	}
	stk.push(s[CalIdx]);
	ToPostfix(s, CalIdx + 1, end);
	ToPostfix(s, start, CalIdx-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s = "";

	cin >> s;
	ToPostfix(s, 0, s.length()-1);

	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	cout << '\n';
	
}


// (A+B)*(A+B*(C-D)/E)
// 0123456789012345678