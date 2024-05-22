// 곱셈
// 자연수 A를 B번 곱한 수를 알고 싶다.단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <cmath>

#define ullint unsigned long long int

using namespace std;

ullint A = 0;
ullint B = 0;
ullint C = 0;

ullint divide(ullint x)
{
	if (x == 1 || x == 0)
		return A%C;
	else
	{
		ullint value = divide(x / 2);
		if (x % 2 == 0)
		{
			return (value * value)%C;
		}
		else
		{
			return ((value * value) % C * A%C)%C;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> C;

	cout << divide(B) << '\n';
}

// 2147483647 2147483647 2147483647