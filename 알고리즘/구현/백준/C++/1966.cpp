// 프린터 큐
// 큐는 FIFO구조다. 이를 변형하여 중요도가 같이 주어질 때, 중요도 순서로 출력되는 프린터를 통해, 입력으로 주어진 문서가 몇 번째로 출력되는지 구하라.


// 내 답안1
// 우선순위 큐 활용 - 가중치가 같을 경우 답과 다르게 나옴. 가중치가 같다면 인덱스가 큰 것을 먼저 pop
/*
#include <iostream>
#include <queue>

#define MAX_N 101

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;

	cin >> T;
	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int n, m, ans = 0;
		priority_queue<pair<int, int>> pq;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int doc;
			cin >> doc;

			pq.push({ doc, i });
		}

		while (!pq.empty())
		{
			int num = pq.top().second;
			pq.pop();

			ans++;
			if (num == m) break;
		}

		cout << ans << '\n';
	}
}
*/


// 내 답안2
// 구현 - 시뮬레이션
#include <iostream>
#include <vector>

#define MAX_N 101

using namespace std;

typedef struct doc
{
	int weight;
	int number;
}doc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;

	cin >> T;
	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int n, m, ans = 0;
		vector<doc> q;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			
			q.push_back({ w, i });
		}

		while (!q.empty())
		{
			int idx = 0;
			doc now = q[0];
			doc tmp = q[0];

			for (int i = 1; i < q.size(); i++)
			{
				if (tmp.weight < q[i].weight)
				{
					tmp = q[i];
					idx = i;
				}
			}
			
			q.erase(q.begin());
			
			if (idx == 0)
			{
				ans++;
				if (tmp.number == m)
				{
					cout << ans << '\n';
					break;
				}
			}
			else
			{
				q.push_back(now);
			}
		}
	}

}
