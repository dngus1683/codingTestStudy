// 2007년
// 오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int x = 0;
int y = 0;
int TotalDays = 0;
int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> x >> y;
	for (int i = 1; i < x; i++)
	{
		TotalDays += months[i];
	}
	TotalDays += y;

	cout << days[(TotalDays - 1) % 7] << '\n';

}