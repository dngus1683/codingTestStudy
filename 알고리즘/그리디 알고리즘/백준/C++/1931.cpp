// 회의실 배정
// 한 회의실을 사용하고자 하는 회의가 N개 있다. 각 회의의 시작시간과 끝시간이 주어질 때, 최대로 진행할 수 있는 회의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 100001

using namespace std;

typedef struct Meeting
{
	int start;
	int end;

	bool operator < (const Meeting& a) const
	{
		if (start == a.start)
			return end < a.end;
		return start < a.start;
	}
}Meeting;

Meeting Meetings[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans = 1;
	Meeting pre;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;

		cin >> a >> b;
		Meetings[i] = { a, b };
	}

	sort(Meetings, Meetings + N);

	pre = Meetings[0];
	for (int i=1; i<N; i++)
	{
		if (pre.end <= Meetings[i].start)
		{
			ans++;
			pre = Meetings[i];
		}
		else if (pre.end > Meetings[i].end)
		{
			pre = Meetings[i];
		}
	}

	cout << ans << '\n';
}