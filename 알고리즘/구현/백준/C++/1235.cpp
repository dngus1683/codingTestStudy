// 학생 번호
// 학생들의 고유번호가 주어질 때, 뒤에서 k자리만을 추려서 남겨 놓았을 때 모든 학생들의 번호를 서로 다르게 만들 수 있는 최소의 k를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N = 0;
string stdNums[1001];
unordered_set<string> hset;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> stdNums[i];
	}

	for (int i = 1; i <= stdNums[0].length(); i++)
	{
		bool flag = true;
		for (int j =0; j<N; j++)
		{
			string sub = stdNums[j].substr(stdNums[0].length() - i, i);

			if (hset.find(sub) == hset.end())
			{
				hset.insert(sub);
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << i << '\n';
			break;
		}
	}


}