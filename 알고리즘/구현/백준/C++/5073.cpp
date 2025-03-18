// 삼각형과 세 변
// 세 변의 길이가 주어질 때, 삼각형을 정의하라.
// Equilateral :  세 변의 길이가 모두 같은 경우
// Isosceles: 두 변의 길이만 같은 경우
// Scalene : 세 변의 길이가 모두 다른 경우
// Invalid : 삼각형이 불가능한 경우


// 내 답안1
#include <iostream>

using namespace std;

int a = 0;
int b = 0;
int c = 0;

inline int max(int a, int b, int c)
{
	int d = (b > c ? b : c);
	return (a > d ? a : d);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		int mx = max(a, b, c);

		if ((a + b + c) - mx <= mx)
		{
			cout << "Invalid" << '\n';
		}
		else if (a == b && b == c)
		{
			cout << "Equilateral" << '\n';
		}
		else if (a == b || b == c || c == a)
		{
			cout << "Isosceles" << '\n';
		}
		else 
		{
			cout << "Scalene" << '\n';
		}
	}
}