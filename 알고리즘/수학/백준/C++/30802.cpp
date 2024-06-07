// 웰컴 키트
// 대회에 참여한 사람에게 티셔츠 1장과 펜 1자루로 구성된 웰컴 키트를 나눠줄 예정이다. 때문에 티셔츠와 펜을 준비해놔야 하는데, 티셔츠는 6가지 사이즈가 있으며 같은 사이즈의 T장 묶음으로만 주문할 수 있고, 펜은 P자루씩 묶음으로 주문하거나 한자루씩 낱개로 주문가능하다.
// 펜은 참여자 수에 딱 맞게 주문해야 하고 티셔츠는 남아도 되지만 부족하지 않게 최소 묶음으로 주문하고자 할 때, 티셔츠 묶음 수와 펜의 묶음 수와 낱개 주문 수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int T = 0;
	int P = 0;
	int ansT = 0;
	int ansP = 0;
	int ansPP = 0;
	int TArr[6] = {};



	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> TArr[i];
	cin >> T >> P;

	for (int i = 0; i < 6; i++)
	{
		if (TArr[i] % T != 0)
			ansT += TArr[i] / T + 1;
		else
			ansT += TArr[i] / T;
	}

	ansP = N / P;
	ansPP = N % P;

	cout << ansT << '\n' << ansP << ' ' << ansPP << '\n';
}