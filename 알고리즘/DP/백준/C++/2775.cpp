// 부녀회장이 될테야
// 0층부터 있는 아파트는 a층 b호에 사는 사람의 수는 (a-1)층 1호~b호까지 사는 사람의 수 합이다. 0층 i호에는 i명 살 때, k층 n호에는 몇 명 사는지 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 15

using namespace std;

int people[MAX_N][MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;

	cin >> T;

	for (int i = 1; i < MAX_N; i++)
		people[0][i] = i;
	for (int i = 1; i < MAX_N; i++)
		people[i][1] = 1;

	for (int i = 1; i < MAX_N; i++)
		for (int j = 1; j < MAX_N; j++)
		{
			people[i][j] = people[i][j - 1] + people[i - 1][j];
		}

	while (T--)
	{
		int k, n;

		cin >> k;
		cin >> n;

		cout << people[k][n] << '\n';

	}
}