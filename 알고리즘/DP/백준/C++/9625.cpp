// BABBA
// 첫 화면에 A만 표시되어진 기계가 있다. 버튼을 누르면 A->B로 바뀌고, B->BA로 바뀐다. 
// 버튼을 K번 눌렀을 때, 화면에 A와 B의 개수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int K = 0;
int A = 1;
int B = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;

	while (K--)
	{
		int tmpA = A;
		int tmpB = B;

		B += tmpA;
		A = tmpB;
	}

	cout << A << ' ' << B << endl;
}
