// 1로 만들기 2
// 정수 X에 사용할 수 있는 연산은 다음과 같은 세 가지다.
// 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
// 2. X가 2로 나누어 떨어지면, 2로 나눈다.
// 3. 1을 뺀다.
// 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들 때, 연산 최소 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

#define MAX_N 1'000'001
#define INF 987654321

using namespace std;

int N = 0;
int X = 0;
int d[MAX_N];
int path[MAX_N];
stack<int> answerPath;

void bfs(int start)
{
	priority_queue<pair<int,int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty())
	{
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (d[now] < dist)
		{
			continue;
		}

		int next1 = (now % 3 == 0 ? now / 3 : -1);
		int next2 = (now % 2 == 0 ? now / 2 : -1);
		int next3 = now - 1;

		if (d[next1] > (dist + 1) && next1 != -1)
		{
			path[next1] = now;
			d[next1] = dist + 1;
			pq.push({ -d[next1], next1 });
		}
		if (d[next2] > (dist + 1) && next2 != -1)
		{
			path[next2] = now;
			d[next2] = dist + 1;
			pq.push({ -d[next2], next2 });
		}
		if (d[next3] > (dist + 1) && next3 != -1)
		{
			path[next3] = now;
			d[next3] = dist + 1;
			pq.push({ -d[next3], next3 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	fill(d, d + MAX_N, INF);

	bfs(N);

	cout << d[1] << '\n';
	int num = 1;
	while (num != N)
	{
		answerPath.push(num);
		num = path[num];
	}
	cout << N << ' ';
	while (!answerPath.empty())
	{
		cout << answerPath.top() << ' ';
		answerPath.pop();
	}
}