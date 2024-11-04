// Fly me to the Alpha Centauri
// 행성 간의 이동 시, 바로 직전 이동의 -1, 0 +1 만큼 이동할 수 있다. 마지막 도착할 때는 반드시 1만큼만 이동한다고 할 때, 이동 횟수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ull long long

using namespace std;

int T = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		ull x = 0;
		ull y = 0;
		ull answer = 0;

		cin >> x >> y;
		
		ull dis = y - x;
		ull tmp = 1;

		while (dis >= tmp)
		{
			if (dis > tmp)
			{
				answer += 2;
			}
			else
			{
				answer++;
			}
			dis -= (tmp * 2);
			tmp++;
		}
		if (dis > 0) answer++;
		cout << answer << '\n';
	}
}