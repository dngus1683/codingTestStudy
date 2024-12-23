// 수학은 비대면강의입니다
// 연립방정식의 계수와 상수가 주어질 때, 연립방정식의 해를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int a = 0;
int b = 0;
int c = 0; 
int d = 0;
int e = 0;
int f = 0;
int x = 0;
int y = 0;
bool xflag = false;
bool yflag = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> c >> d >> e >> f;

	y = (c*d - a*f) / (b*d - a*e);
	if( a != 0)
		x = (c - b * y) / a;
	else
		x = (f - e * y) / d;

	cout << x << ' ' << y << '\n';


}