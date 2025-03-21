// 전쟁 - 땅따먹기
// 각 땅별로 전쟁이 벌어진다. 해당 땅에 배치된 수만큼 그 나라의 번호가 주어진다. 이때, 한 나라의 군사가 절반을 초과한다면 그 땅은 그 번호의 나라가 먹게 된다.
// 각 땅에서의 현 상황이 주어질 때 지배 상태를 구하라.


// 내 답안1
#include <iostream>
#include <unordered_map>

#define ll long long
using namespace std;

int N = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--)
	{
		bool flag = true;
		int T = 0;
		unordered_map<ll, int> hmap;

		cin >> T;
		for (int i = 0; i < T; i++)
		{
			ll ni = 0;

			cin >> ni;
			hmap[ni]++;
		}

		for (auto iter : hmap)
		{
			if (iter.second > (T / 2))
			{
				cout << iter.first << '\n';
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "SYJKGW\n";
		}
	}
}