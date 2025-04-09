// 빙산
// N x M의 공간에 빙산의 높이 정보가 주어진다. 빙산은 사방으로 맞닿아있는 바다가 있다면 바다 타일 개수만큼 매년 빙산의 높이가 줄어든다.
// 빙산은 사방으로 연결되어 있다면 하나의 빙산으로 생각한다.
// 한 덩어리의 빙산이 주어질 때, 빙산이 두 덩어리 이상으로 분리되는 최초의 년을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 301

using namespace std;

int N = 0;
int M = 0;
int answer = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N, 0));

void dfs(bool visited[][MAX_N], int nowI, int nowJ)
{
	visited[nowI][nowJ] = true;

	for (int d = 0; d < 4; d++)
	{
		int nextI = nowI + di[d];
		int nextJ = nowJ + dj[d];

		if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= M) continue;

		if (graph[nextI][nextJ] != 0 && !visited[nextI][nextJ])
		{
			dfs(visited, nextI, nextJ);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
		}
	}

	while (true)
	{
		answer++;

		// 녹이기
		vector<vector<int>> tmp = graph;

		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (graph[i][j - 1] == 0) tmp[i][j] = max(tmp[i][j] - 1, 0);
				if (graph[i][j + 1] == 0) tmp[i][j] = max(tmp[i][j] - 1, 0);
				if (graph[i - 1][j] == 0) tmp[i][j] = max(tmp[i][j] - 1, 0);
				if (graph[i + 1][j] == 0) tmp[i][j] = max(tmp[i][j] - 1, 0);
			}
		}
		graph = tmp;

		// 빙산 개수 알아보기
		bool visited[MAX_N][MAX_N] = { false, };
		int cnt = 0;

		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (!visited[i][j] && graph[i][j] != 0)
				{
					cnt++;
					dfs(visited, i, j);
				}
			}
		}

		if (cnt >= 2)
		{
			cout << answer << '\n';
			break;
		}
		else if (cnt == 0)
		{
			cout << 0 << '\n';
			break;
		}
	}
}