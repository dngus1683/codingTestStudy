// DSLR
// [0, 9999]의 범위를 갖는 정수 n에 대하여, D, S, L, R 4가지 연산을 수행할 수 있다.
// D: n을 두 배한다. 대신 값이 9999를 넘는다면 10000의 mod 값을 갖는다.
// S: 1을 뺀다. n-1이 0이라면 9999를 갖는다.
// L: 각 자릿수를 왼편으로 회전시킨다
// R: 각 자릿수를 오른편으로 회전시킨다.
// 정수 A, B가 주어질 때, A가 B가 되기 위해서 실행해야 할 최소한의 명령어를 구하라.


// 내 답안1
// dijkstra로 풀었다가, 매 테스트 케이스마다 fill()을 통해 가중치 배열을 INF로 초기화를 했었는데,
// 이 작업이 시간을 굉장히 소모하여 시간초과가 떴다.
// 이 문제는 가중치가 없기 때문에 BFS로도 충분히 풀 수 있다.
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 10'000

using namespace std;

static inline int CalD(int n)
{
	return (n * 2) % MAX_N;
}

static inline int CalS(int n)
{
	return (n == 0 ? 9999 : n - 1);
}

static int CalL(int n)
{
	int d[4] = { 0, 0, 0, 0 };

	for (int i =3; i>= 0;  i--)
	{
		d[i] = n % 10;
		n /= 10;
	}
	return ((d[1] * 10 + d[2]) * 10 + d[3])*10+d[0];
}

static int CalR(int n)
{
	int d[4] = { 0, 0, 0, 0 };

	for (int i = 3; i >= 0; i--)
	{
		d[i] = n % 10;
		n /= 10;
	}
	return ((d[3] * 10 + d[0]) * 10 + d[1]) * 10 + d[2];
}

void bfs(int start, int end)
{
	char ans[MAX_N];
	bool visited[MAX_N] = { false, };
	pair<int, char> path[MAX_N];
	queue<int> q;
	q.push(start);

	visited[start] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == end) break;

		if (!visited[CalD(now)])
		{
			visited[CalD(now)] = true;
			path[CalD(now)] = { now, 'D' };
			q.push(CalD(now));
		}
		if (!visited[CalS(now)])
		{
			visited[CalS(now)] = true;
			path[CalS(now)] = { now, 'S' };
			q.push(CalS(now));
		}
		if (!visited[CalL(now)])
		{
			visited[CalL(now)] = true;
			path[CalL(now)] = { now, 'L' };
			q.push(CalL(now));
		}
		if (!visited[CalR(now)])
		{
			visited[CalR(now)] = true;
			path[CalR(now)] = { now, 'R' };
			q.push(CalR(now));
		}
	}
	int idx = 0;
	while (start != end)
	{
		ans[idx++] = path[end].second;
		end = path[end].first;
	}
	while (idx--)
	{
		cout << ans[idx];
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;

	while (TestCase--)
	{
		int A = 0;
		int B = 0;

		cin >> A >> B;

		bfs(A, B);
	}
}