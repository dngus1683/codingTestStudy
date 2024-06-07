// FizzBuzz
// FizzBuzz 문제는 i = 1, 2,... 에 대해 다음 규칙에 따라 문자열을 한 줄에 하나씩 출력하는 문제다.
// i가 3의 배수이면서 5의 배수이면 “FizzBuzz”를 출력.
// i가 3의 배수이지만 5의 배수가 아니면 “Fizz”를 출력.
// i가 3의 배수가 아니지만 5의 배수이면 “Buzz”를 출력.
// i가 3의 배수도 아니고 5의 배수도 아닌 경우 i를 그대로 출력.
// FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열이 주어질 때, 이 세 문자열 다음에 올 문자열을 구하라.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s[3] = {};
	int num = 0;
	int cnt = 3;

	cin >> s[0] >> s[1] >> s[2];

	for (int i = 0; i < 3; i++)
	{
		if ((s[i][0] - '0' >= 0) && (s[i][0] - '0' <= 9))
		{
			num = stoi(s[i]);
			cnt -= i;
			break;
		}
	}

	if ((num + cnt) % 3 == 0 && (num + cnt) % 5 == 0)
		cout << "FizzBuzz" << '\n';
	else if ((num + cnt) % 3 == 0)
		cout << "Fizz" << '\n';
	else if ((num + cnt) % 5 == 0)
		cout << "Buzz" << '\n';
	else
		cout << (num + cnt) << '\n';
}