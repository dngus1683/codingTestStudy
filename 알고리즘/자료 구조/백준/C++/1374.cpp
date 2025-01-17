// 강의실
// 모든 강의의 시작하는 시간과 끝나는 시간을 알고 있다. 최대한 적은 수 의 강의실을 사용하여 모든 강의가 이뤄지게 할 때, 최소 강의실의 수를 출력하라.
// 이때 한 강의실에서 동시에 2개 이상의 강의를 진행할 수 없다.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0;
vector<pair<int, int>> table;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		int start = 0;
		int end = 0;

		cin >> a >> start >> end;

		table.push_back({ start, end });
	}

	sort(table.begin(), table.end());
	pq.push(-table[0].second);

	for (int i = 1; i < n; i++)
	{
		if (-pq.top() <= table[i].first)
		{
			pq.pop();
		}
		pq.push(-table[i].second);
	}
	cout << pq.size() << '\n';
}