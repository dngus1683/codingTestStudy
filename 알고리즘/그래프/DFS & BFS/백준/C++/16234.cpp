// 인구 이동
// NxN 크기의 땅에 존재하는 1x1 크기의 나라들에 사는 사람의 인구수가 주어진다. 모든 나라는 국경선을 공유하는 나라끼리의 인구 수 차가 L이상 R이하 일 때, 국경이 열리고 인구를 평균으로 나눠가진다.
// 인구 이동이 며칠 동안 발생하는 지 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <cmath>

#define MAX_N 51
#define MAX_L 101
#define MAX_R 101
#define MAX_LAND 101

using namespace std;

int N = 0;
int L = 0;
int R = 0;
int answer = 0;
int A[MAX_LAND][MAX_LAND];

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
bool judge(int a, int b)
{
	if (abs(a - b) >= L && abs(a - b) <= R)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool bfs(int startI, int startJ, bool visited[][MAX_LAND])
{
	bool flag = false;
	int total = A[startI][startJ];
	queue<pair<int, int>> q;
	queue<pair<int, int>> path;

	q.push({ startI, startJ });
	path.push({ startI, startJ });
	visited[startI][startJ] = true;
	while (!q.empty())
	{
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nextI = nowI + di[d];
			int nextJ = nowJ + dj[d];

			if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= N) continue;
			if (visited[nextI][nextJ]) continue;

			if (judge(A[nowI][nowJ], A[nextI][nextJ]))
			{
				total += A[nextI][nextJ];
				q.push({ nextI, nextJ });
				path.push({ nextI, nextJ });
				visited[nextI][nextJ] = true;
				flag = true;
			}
		}
	}

	total = total / path.size();

	while (!path.empty())
	{
		A[path.front().first][path.front().second] = total;
		path.pop();
	}

	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	while (true)
	{
		bool flag = false;
		bool visited[MAX_LAND][MAX_LAND] = { false, };

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					if (bfs(i, j, visited))
						flag = true;
				}
			}
		}

		if (!flag) break;
		answer++;
	}
	cout << answer << '\n';
}