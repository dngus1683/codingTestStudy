// 과일 탕후루
// N개의 과일이 꽂혀있는 과일 탕후루가 있다. 꼬치의 앞에서 a개, 뒤에서 b개를 빼서 두 종류 이하의 과일만 꽂혀있도록 할 때, 과일 개수가 가장 많이 꽂혀있을 때 과일 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 200'000

using namespace std;

int fruit[MAX_N];
int pick[2] = { 0, 0 };

static inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int PickCnt = 1;
	int Fcnt = 1;
	int Pcnt = 1;
	int post = 0;
	int ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> fruit[i];

	pick[0] = post = fruit[0];
	for (int i = 1; i < N; i++)
	{
		if (fruit[i] == pick[0] || fruit[i] == pick[1])
		{
			Fcnt++;
		}
		else
		{
			if (PickCnt == 1)
			{
				pick[1] = fruit[i];
				Fcnt++;
				PickCnt++;
			}
			else
			{
				ans = max(ans, Fcnt);
				Fcnt = Pcnt+1;
				pick[0] = post;
				pick[1] = fruit[i];
			}
		}

		if (fruit[i] == fruit[i - 1])
			Pcnt++;
		else
		{
			Pcnt = 1;
			post = fruit[i];
		}
	}
	cout << max(ans, Fcnt) << '\n';
}