// 쇠막대기
// 쇠막대의 양 끝을 (, ), 레이저를 ()로 표현한다. 레이저로 여러 쇠막대를 겹쳐 잘라 토막을 내려할 때, 잘려진 쇠막대기 조각의 총 개수를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int answer = 0;
string s = "";
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	for (char c : s)
	{
		if (c == ')')
		{
			if (stk.top() == -1)
			{
				stk.pop();
				if (!stk.empty() && stk.top() != -1)
				{
					stk.top() += 1;
				}
				else
				{
					stk.push(1);
				}
			}
			else
			{
				int Rcnt = stk.top();
				stk.pop();

				answer += (Rcnt + 1);
				stk.pop();

				if (!stk.empty() && stk.top() != -1)
				{
					stk.top() += Rcnt;
				}
				else
				{
					stk.push(Rcnt);
				}
			}
		}
		else if (c == '(')
		{
			stk.push(-1);
		}
	}

	cout << answer << '\n';
}



// 답안 예시1 - https://www.acmicpc.net/source/28088613
// 레이저로 한 번 자를 때마다 앞의 파이프 시작 개수가 잘려진 막대 개수다.
/*
#include <cstdio>
int cnt = 0, ans = 0, ch, pch;
int main() {
	while ((ch=getchar()) != '\n') {
		if (ch == '(') cnt++;
		else cnt--, ans += pch == '(' ? cnt : 1;
		pch = ch;
	}
	printf("%d", ans);
}
*/