// 삼각형 외우기
// 삼각형의 세 각을 입력받은 다음,
// 세 각의 크기가 모두 60이면, Equilateral
// 세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
// 세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
// 세 각의 합이 180이 아닌 경우에는 Error
// 를 출력하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>

using namespace std;

int a = 0;
int b = 0;
int c = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> c;

	if (a + b + c != 180)
	{
		cout << "Error\n";
	}
	else if (a == b && b == c)
	{
		cout << "Equilateral\n";
	}
	else if (a == b || b == c || a == c)
	{
		cout << "Isosceles\n";
	}
	else
	{
		cout << "Scalene\n";
	}
}