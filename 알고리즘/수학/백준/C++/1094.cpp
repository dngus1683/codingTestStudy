// 막대기
// 64cm의 막대가 있다. 이를 계속 절반으로 잘라 이어붙여 X cm의 막대를 만드려 한다. 모든 막대의 길이의 합이 X보다 크면, 가장 짧은 막대를 반으로 자른다. 자른 막대 중 하나를 제외한 총 길이가 x보다 크면 그 막대는 버린다. X cm를 구성하는 막대의 개수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int X = 0;
	int cnt = 0;

	cin >> X;

	while (X != 1)
	{
		if (X % 2 == 1) cnt++;
		X /= 2;
	}

	cout << cnt+1 << '\n';

}