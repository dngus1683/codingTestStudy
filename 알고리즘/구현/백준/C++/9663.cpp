// N-Queen
// N-Queen 문제는 크기가 N x N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제다.
// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하라.
// + 퀸은 상하좌우 대각 어느 방향이든 어느 거리든 이동가능하다.

// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

inline unsigned int abs(int& a)
{
	return (a >= 0 ? a : -a);
}

int N = 0;
int ans = 0;
void func(vector<pair<int, int>>& Picked, int i, int count)
{
	if (count == N)
	{
		ans += 1;
		return;
	}

	for (int j = 0; j < N; j++)
	{
		int flag = 1;
		for (auto pick : Picked)
		{
			if (j == pick.second || (abs(pick.first - i) == abs(pick.second - j)))
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			Picked.push_back({ i, j });
			func(Picked, i + 1, count + 1);
			Picked.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<pair<int, int>> Picked;

	cin >> N;

	func(Picked, 0, 0);
	cout << ans << '\n';
}
