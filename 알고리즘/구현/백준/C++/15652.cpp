// N과 M (4)
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
// + 1부터 N까지 자연수 중에서 M개를 고른 수열
// + 같은 수를 여러 번 골라도 된다.
// + 고른 수열은 비내림차순이어야 한다.
// + + 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK - 1 ≤ AK를 만족하면, 비내림차순이라고 한다.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 8

using namespace std;

int N = 0;
int M = 0;

void combination(int start, vector<int>& pick, int length)
{
	if (length == 0)
	{
		for (int i = 0; i < M - 1; ++i)
		{
			cout << pick[i] << ' ';
		}
		cout << pick[M - 1] << '\n';
	}
	else
	{
		for (int i = start; i <= N; ++i)
		{
			pick.push_back(i);
			combination(i, pick, length - 1);
			pick.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> comb;

	cin >> N >> M;

	combination(1, comb, M);
}