// 신기한 소수
// 7331은 그 자체도 소수, 733, 73, 7도 소수다. 이러한 수를 신기한 소수라 하자.
// N자리 자연수 중, 신기한 소수를 모두 구하라.


// 내 답안1
#include <iostream>
#include <unordered_set>

#define MAX_N 80'000'000

using namespace std;
int N = 0;
unordered_set<int> IsNotPrime;

void backtracking(int num, int cnt)
{
	if (cnt == N)
	{
		cout << num << '\n';
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		int nextNum = num * 10 + i;
		bool IsPrime = true;

		if (nextNum == 0 || nextNum == 1) IsPrime = false;
		for (int j = 2; j < nextNum; j++)
		{
			if (nextNum % j == 0)
			{
				IsPrime = false;
				break;
			}
		}
		if (IsPrime)
		{
			backtracking(num * 10 + i, cnt + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	backtracking(0, 0);
}