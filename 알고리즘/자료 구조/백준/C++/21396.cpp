// 이진수 더하기
// N개의 정수가 주어진다. 그 중, 두 수의 올림을 하지 않는 이진수 합이 x인 쌍의 개수를 구하라.


// 내 답안1
// xor = ^
// a xor b = c 라면, c xor a = b 다.
#include <iostream>
#include <vector>
#include <unordered_map>

#define ull long long

using namespace std;

ull T = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		ull n = 0;
		ull x = 0;
		ull answer = 0;
		unordered_map<ull, ull> hmap;

		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			ull num = 0;
			
			cin >> num;
			hmap[num]++;
		}
		for (auto a : hmap)
		{
			if (hmap[a.first] == 0)
				continue;
			if (hmap.find(a.first ^ x) != hmap.end())
			{
				if (a.first == (a.first ^ x))
				{
					answer += (hmap[a.first] * (hmap[a.first] - 1));
				}
				else
				{
					answer += hmap[a.first] * hmap[a.first^x];
				}
			}
		}
		cout << answer << '\n';
	}
}