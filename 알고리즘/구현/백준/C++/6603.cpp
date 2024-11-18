// 로또
// 독일 로또는 1~49에서 6개를 고른다. 이중 k개의 수를 골라 집합 S를 만든 다음, 그 수만을 가지고 번호를 선택해 로또 번호를 구성하기로 한다.
// 집합 S와 K가 주어졌을 때 로또 수를 구하는 모든 방법을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_K 14

using namespace std;

int K = 0;

void combination(int start, vector<int>& S, vector<int>& picked)
{
	if (picked.size() == 6)
	{
		for (int n : picked)
		{
			cout << n << ' ';
		}
		cout << '\n';
	}

	for (int i = start; i < K; i++)
	{
		picked.push_back(S[i]);
		combination(i + 1, S, picked);
		picked.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> K;

		if (K == 0) break;

		vector<int> S(MAX_K);
		vector<int> picked;
		for (int i = 0; i < K; i++)
		{
			cin >> S[i];
		}

		combination(0, S, picked);
		cout << '\n';
	}
}