// 진법 변환 2
// 10진법 수 N이 주어진다.이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
// 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다.이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
// A: 10, B : 11, ..., F : 15, ..., Y : 34, Z : 35


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int N = 0;
int B = 0;
string s = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> B;

	while (N >= B)
	{
		int res = N % B;

		if (res >= 10)
		{
			s.push_back('A' + (res - 10));
		}
		else
		{
			s.push_back('0' + res);
		}
		N /= B;
	}

	if (N >= 10)
	{
		s.push_back('A' + (N - 10));
	}
	else
	{
		s.push_back('0' + N);
	}

	for (int i = s.length() - 1; i >= 0; i--)
	{
		cout << s[i];
	}
	cout << endl;
}