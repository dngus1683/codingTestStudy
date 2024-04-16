// 스택
// 스택을 구현하라. 양의 정수 N이 주어질 때, N개의 스택 명령어를 수행하라.


// 내 답안1
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	stack<int> st;

	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		int num;
		string s, s1;
		stringstream ss;

		getline(cin, s);

		if (s.find(' ') != string::npos)
		{
			ss << s;
			ss >> s1 >> num;
		}
		else
			s1 = s;

		if (s1 == "push")
		{
			st.push(num);
		}
		else if (s1 == "pop")
		{
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s1 == "size")
		{
			cout << st.size() << '\n';
		}
		else if (s1 == "empty")
		{
			cout << st.empty() << '\n';
		}
		else if (s1 == "top")
		{
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
			}
		}
	}
	
}











// 답안 예시1
// top을 배열의 인덱스로 활용한 간단한 방법
/*
#include<stdio.h>
char i[5];
int main() {
	int s[10000], top = 0, n;
	scanf("%d", &n);
	for (; n--;) {
		scanf("%s", i);
		if (i[0] == 'p' && i[1] == 'u')
			scanf("%d", &s[top++]);
		else if (i[0] == 'p' && i[1] == 'o')
			printf("%d\n", top ? s[--top] : -1);
		else if (i[0] == 's')
			printf("%d\n", top);
		else if (i[0] == 'e')
			printf("%d\n", top ? 0 : 1);
		else if (i[0] == 't') { printf("%d\n", top ? s[top - 1] : -1); }
	}
}
*/