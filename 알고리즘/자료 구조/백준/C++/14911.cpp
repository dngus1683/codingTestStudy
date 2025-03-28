// 궁합 쌍 찾기
// 첫째 줄에 주어진 여러 개의 정수 중에서 합이 둘째 줄에 주어진 수와 같은 서로 다른 위치에 있는 두 수의 쌍을 모두 출력하고 맨 아래에 이 쌍의 개수를 이어서 출력하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

set<int> numbers;
set<pair<int, int>> answer;
unordered_map<int, int> hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin.eof()!='\n')
	{
		int a = 0;

		cin >> a;
		numbers.insert(a);
		hmap[a]++;

		if (cin.peek() == '\n')
		{
			break;
		}
	}

	int b = 0;

	cin >> b;

	for (int left : numbers)
	{
		for (int right : numbers)
		{
			if (left == right && hmap[left] < 2)
			{
				continue;
			}
			if (left + right == b)
			{
				int big = max(left, right);
				int little = min(left, right);
				
				answer.insert({ little, big });
			}
		}
	}

	for (pair<int,int> p : answer)
	{
		cout << p.first << ' ' << p.second << '\n';
	}
	cout << answer.size() << '\n';

}