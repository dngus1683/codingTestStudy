// 점수 계산
// 8개의 점수가 주어지고, 최종 점수는 본인이 받은 점수 중 5개의 합이 가장 높은 수다. 총 점수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int score[8];
int pick[8] = { 1,1,1,1,1,1,1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 8; i++)
	{
		cin >> score[i];
	}

	for (int i = 0; i < 3; i++)
	{
		int mn = 200;
		int idx = 0;
		for (int j = 0; j < 8; j++)
		{
			if (mn > score[j])
			{
				mn = score[j];
				idx = j;
			}
		}
		score[idx] = 200;
		pick[idx] = 0;
	}

	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		if (pick[i])
			ans += score[i];
	}

	cout << ans << '\n';
	for (int i = 0; i < 8; i++)
	{
		if (pick[i])
			cout << i+1 << ' ';
	}
}