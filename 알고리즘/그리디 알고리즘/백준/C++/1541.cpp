// 잃어버린 괄호
// 양수와 +, - 로 이루어진 식이 주어질 때, 적절히 괄호를 쳐서 값을 최소로 만들어라.


// 내 답안1
// 덧셈에만 괄호를 부여하면 최솟값을 만들 수 있다.
// 계산 기호 없이 숫자 하나만 입력될 수 있다는 경우도 고려해야 했다.
/*
#include <iostream>
#include <string>

#define MAX_L 51
using namespace std;

int number[MAX_L], MinusNumber[MAX_L];
char cal[MAX_L];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;

	cin >> s;

	int ten = -1, num = 0, CalIdx = 0, NumIdx = 0, MinusIdx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+')
		{
			cal[CalIdx++] = s[i];
			ten = -1;
			number[NumIdx++] = num;
		}
		else if (s[i] == '-')
		{
			cal[CalIdx++] = s[i];
			ten = -1;
			number[NumIdx++] = num;
		}
		else
		{
			if (ten == -1)
			{
				ten = 1;
				num = s[i] - '0';
			}
			else
			{
				num = (s[i] - '0') + num * 10;
			}
		}
	}
	number[NumIdx++] = num;

	for (int i = 0; i < CalIdx; i++)
	{
		if (cal[i] == '+')
		{
			number[i + 1] += number[i];
		}
		else
		{
			MinusNumber[MinusIdx++] = number[i];
		}
	}

	MinusNumber[MinusIdx++] = number[NumIdx - 1];

	for (int i = 0; i < MinusIdx; i++)
	{
		MinusNumber[i + 1] = MinusNumber[i] - MinusNumber[i + 1];
	}

	cout << MinusNumber[MinusIdx-1] << '\n';

}
*/











// 답안 예시1
// 기존 아이디어처럼 덧셈에만 괄호를 부여하면 최솟값을 만들 수 있다.
// 그 말인 즉슨, 수식에서 첫 뺄셈이 나온 순간부터 이어지는 모든 계산은 뺄셈으로 바꿔도 값은 똑같다는 의미다.
/*
#include <stdio.h>
int n,s,f=1;
char c;
int main(void){
  while(c!=10){
	scanf("%d%c",&n,&c);
	s+=n*f;
	if(c=='-')f=-1;
  }
  printf("%d",s);
}
*/






// 답안 예시2
// 답안 예시1과 같은 방법이며, 입력을 c++방식으로, stringstream을 활용하였다.
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string input;
	getline(cin, input); // 한 줄을 문자열로 읽음

	stringstream ss(input);
	int s = 0;
	char op;
	int num, flag = 1;

	ss >> num; // 첫 번째 숫자를 읽음
	s += num;  // 첫 번째 숫자를 더함

	while (ss >> op >> num) { // 연산자와 숫자를 읽음
		if (op == '+') {
			s += num * flag;
		}
		else if (op == '-') {
			s -= num;
			flag = -1;
		}
	}

	cout << s << endl;

	return 0;
}
