// 경로 찾기
// 가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 길이가 양수인 경로가 있는지 없는지 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <queue>

#define MAX_N 101

using namespace std;

int N = 0;
int graph[MAX_N][MAX_N];

void BFS(int start)
{
	bool visited[MAX_N] = { false, };
	queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && graph[now][i])
			{
				visited[i] = true;
				graph[start][i] = 1;
				q.push(i);
			}
			else if (graph[now][start])
				graph[start][start] = 1;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++)
		BFS(i);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

}










// 답안 예시1 - https://www.acmicpc.net/source/21746058
// 플로이드 워셜로, i에서 j까지 갈 때, 그 중간 단계인 ik -> kj를 모두 확인.
/*
#include <cstdio>

int main() {
	int n, i, j, k, v[100][100]; scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) scanf("%d", &v[i][j]);

	for (k = 0; k < n; ++k)
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (v[i][k] && v[k][j]) v[i][j] = 1;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) printf("%d ", v[i][j]);
		puts("");
	}
}
*/