// 파이프 옮기기1
// N x N 크기의 맵에 빈 공간 0과 벽 1이 주어진다. 2x1 크기의 파이프를 (1, 1) 에서 (N, N)까지 이동시켜야 한다. 이동은 3시, 5시, 6시 방향으로만 가능하다. 
// 목표지점까지 이동시키는 방법의 개수를 구하라.


// 내 답안1
// dfs
// 파이프를 객체를 구현하여 모든 케이스를 방문.
#include <iostream>

#define MAX_N 17
using namespace std;

typedef struct pipe
{
	int head[2] = {};
	int tail[2] = {};
	int state()
	{
		if (head[0] == tail[0])
			return 0;
		else if (head[1] == tail[1])
			return 1;
		else
			return 2;
	}
};

int N = 0;
int graph[MAX_N][MAX_N];
int HeadDi[7] = { 0, 1, 1, 1, 0, 1, 1 };
int HeadDj[7] = { 1, 1, 0, 1, 1, 0, 1 };
int TailDi[7] = { 0, 0, 1, 1, 1, 1, 1 };
int TailDj[7] = { 1, 1, 0, 0, 1, 1, 1 };
int ans = 0;

void dfs(pipe now)
{
	if (now.head[0] == N && now.head[1] == N)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 7; i++)
	{
		pipe next;
		if (now.state() == 0 && (i != 0 && i != 1)) continue;
		if (now.state() == 1 && (i != 2 && i != 3)) continue;
		if (now.state() == 2 && (i != 4 && i != 5 && i != 6)) continue;

		next = { {now.head[0] + HeadDi[i], now.head[1] + HeadDj[i]}, {now.tail[0] + TailDi[i], now.tail[1] + TailDj[i]} };

		if (next.head[0] > N || next.head[1] > N || next.tail[0] > N || next.tail[1] > N) continue;
		if (graph[next.head[0]][next.head[1]] == 1 || graph[next.tail[0]][next.tail[1]] == 1) continue;
		if (next.state() == 2 && (graph[next.head[0] - 1][next.head[1]] == 1 || graph[next.head[0]][next.head[1] - 1] == 1)) continue;

		dfs(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];
		}
	}

	pipe start = { {1, 2}, {1, 1} };

	dfs(start);

	cout << ans << '\n';

}











// 답안 예시 - https://www.acmicpc.net/source/78468629
// dp
// 꼬리 부분은 고려 X, 단순히 head 부분의 이동만 고려하여 dp
/*
#include <stdio.h>
int main() {
	int dp[17][17][3]{}, map[17][17]{}, N;
	scanf("%d", &N);
	for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) scanf("%d", &map[r][c]);

	dp[1][2][0] = 1;
	for (int r = 1; r <= N; ++r) for (int c = 3; c <= N; ++c) {

		if (map[r][c]) continue;
		dp[r][c][0] = dp[r][c-1][0] + dp[r][c-1][1];
		dp[r][c][2] = dp[r-1][c][1] + dp[r-1][c][2];

		if (map[r-1][c] || map[r][c-1]) continue;
		dp[r][c][1] = dp[r-1][c-1][0] + dp[r-1][c-1][1] + dp[r-1][c-1][2];
	}

	printf("%d", dp[N][N][0] + dp[N][N][1] + dp[N][N][2]);
}
*/