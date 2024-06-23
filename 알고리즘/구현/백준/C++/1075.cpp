// 나누기
// 정수 N과 F가 주어진다. 이때, N의 뒷 두자리 수를 적절히 변경하여 F에 나눠 떨이지도록 하려 한다. 이때 N은 가능한 작게 만든다. 변경된 N의 마지막 두자리를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int F = 0;
	int ans = 0;

	cin >> N >> F;

	N = N / 100;
	N = N * 100;

	for (int i = N; i <= N + 99; i++)
	{
		if (i % F == 0)
		{
			ans = i;
			break;
		}
	}

	int ans2 = ans % 10;
	ans = ans / 10;
	int ans1 = ans % 10;

	cout << ans1 << ans2 << '\n';
}