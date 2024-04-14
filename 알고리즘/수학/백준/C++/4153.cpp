// 직각삼각형
// 주어진 세변의 길이를 통해 삼각형이 직각삼각형인지 구분하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) return 0;

		if (a > b && a > c)
		{
			if (a * a == b * b + c * c)
				cout << "right" << '\n';
			else
				cout << "wrong" << '\n';
		}
		else if (b > a && b > c)
		{
			if (b * b == a * a + c * c)
				cout << "right" << '\n';
			else
				cout << "wrong" << '\n';
		}
		else
		{
			if (c * c == b * b + a * a)
				cout << "right" << '\n';
			else
				cout << "wrong" << '\n';
		}
	}
}