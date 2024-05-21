// 상수
// 같지 않은 세 자리 수가 주어질 때, 두 수를 거꾸로 읽었을 때 큰 수를 출력하라.


// 내 답안1
#include <iostream>

using namespace std;

int reverse(int n)
{
	int tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		tmp += n % 10;
		tmp *= 10;
		n /= 10;
	}

	return tmp / 10;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N1 = 0;
	int N2 = 0;
	int ans = 0;

	cin >> N1 >> N2;

	N1 = reverse(N1);
	N2 = reverse(N2);

	cout << (N1 > N2 ? N1 : N2) << endl;
}



// 내 답안2
/*
#include <iostream>

using namespace std;

int main()
{
	char a[5];
	char b[5];
	int an, bn;

	cin >> a;
	cin >> b;

	an = (a[2] - '0') * 100 + (a[1] - '0') * 10 + (a[0] - '0');
	bn = (b[2] - '0') * 100 + (b[1] - '0') * 10 + (b[0] - '0');

	if (an > bn) cout << an << endl;
	else cout << bn << endl;

}
*/