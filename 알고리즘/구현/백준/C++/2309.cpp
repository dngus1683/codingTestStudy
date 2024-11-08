// 일곱 난쟁이
// 일곱 난쟁이의 키의 합이 100이다. 아홉 난쟁이의 키가 모두 주어질 때, 일곱 난쟁이들의 키를 모두 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> length(9);
vector<int> picked;

bool backtracking(int start, int sum)
{
	if (picked.size() == 7)
	{
		if (sum == 100)
		{
			return true;
		}
	}

	for (size_t i = start; i < 9; i++)
	{
		picked.push_back(length[i]);
		if (backtracking(i + 1, sum + length[i]))
		{
			return true;
		}
		picked.pop_back();
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		cin >> length[i];
	}

	backtracking(0, 0);

	sort(picked.begin(), picked.end());
	for (auto num : picked)
	{
		cout << num << '\n';
	}
}