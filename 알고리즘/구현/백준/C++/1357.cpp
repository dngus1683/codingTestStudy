// 뒤집힌 덧셈
// 정수 2개가 주어질 때, 두 수의 역순이 된 수의 합의 역순을 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int Rev(int num)
{
	int res = 0;

	while (num > 0)
	{
		res *= 10;
		res += num % 10;
		num /= 10;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int X = 0;
	int Y = 0;

	cin >> X >> Y;
	cout << Rev(Rev(X) + Rev(Y)) << endl;
}