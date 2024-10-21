// N과 M (3)
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
// + 1부터 N까지 자연수 중에서 M개를 고른 수열
// + 같은 수를 여러 번 골라도 된다.


// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

void func(vector<int>& picked)
{
	if (picked.size() == M)
	{
		for (auto num : picked)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		picked.push_back(i);
		func(picked);
		picked.pop_back();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	vector<int> picked;
	func(picked);
}