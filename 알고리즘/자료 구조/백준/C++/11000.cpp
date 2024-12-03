// 강의실 배정
// Si에 시작해서 Ti에 끝나는 N개의 수업이 주어진다. 최소 강의실을 사용하여 모든 수업을 가능하도록 할 때, 강의실 개수를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 200'001

using namespace std;

struct OneClass
{
	int s;
	int t;

	OneClass() : s(0), t(0) {}
	OneClass(int InS, int InT) : s(InS), t(InT) {}

	bool operator <(OneClass& other)
	{
		if (other.s == s)
		{
			return t < other.t;
		}
		else
		{
			return s < other.s;
		}
	}
};

int N = 0;
OneClass classes[MAX_N];
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int s = 0;
		int t = 0;

		cin >> s >> t;

		classes[i] = OneClass(s, t);
	}

	sort(classes, classes + N);

	for (size_t i = 0; i < N; i++)
	{
		if (pq.empty())
		{
			pq.push(-classes[i].t);
		}
		else
		{
			if (-pq.top() <= classes[i].s)
			{
				pq.pop();
			}
			pq.push(-classes[i].t);
		}
	}

	cout << pq.size() << '\n';

}