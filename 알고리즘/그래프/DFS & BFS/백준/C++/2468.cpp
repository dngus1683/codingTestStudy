// 안전 영역
// N x N 크기의 지역에 높이 정보가 주어진다. 비의 양에 따라 잠기지 않은 안전한 지역은 인접한 영역에 대해서는 하나의 영역으로 볼 때,
// 물에 잠기지 않는 안전한 영역의 최대 개수를 구하라.


// 내 답안1
#include <iostream>
#include <set>
#include <algorithm>

#define MAX_N 101

using namespace std;

int answer = 1;
int N = 0;
int graph[MAX_N][MAX_N];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
set<int> height;

void dfs(int nowI, int nowJ, const int std, bool visited[][MAX_N])
{
	visited[nowI][nowJ] = true;

	for (int d = 0; d < 4; d++)
	{
		int NextI = nowI + di[d];
		int NextJ = nowJ + dj[d];

		if (NextI >= 0 && NextI < N && NextJ >= 0 && NextJ < N)
		{
			if (!visited[NextI][NextJ] && graph[NextI][NextJ] > std)
			{
				dfs(NextI, NextJ, std, visited);
			}
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
			height.emplace(graph[i][j]);
		}
	}

	for (auto h : height)
	{
		int cnt = 0;
		bool visited[MAX_N][MAX_N] = {0,};
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && graph[i][j] > h)
				{
					cnt++;
					dfs(i, j, h, visited);

				}
			}
		}

		answer = max(answer, cnt);
	}

	cout << answer << endl;
}







// 답안 예시1 - https://www.acmicpc.net/source/46234277
// disjoinset 방식.
/*
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int find(vector<int>& parent, int x) {
	if (parent[x] == -1) {
		return x;
	}
	return parent[x] = find(parent, parent[x]);
}

int Union(vector<int>& parent, int x, int y) {
	int px = find(parent, x);
	int py = find(parent, y);

	if (px == py) return 0;
	parent[py] = px;
	return 1;
}

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	for (auto& row : grid) {
		for (auto& i : row) {
			cin >> i;
		}
	}

	int maxv = 1;

	int cnt = 0;
	vector<int> parent(n * n, -1);
	for (int k = 100; k > 0; k--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == k) {
					cnt++;
					for (int d = 0; d < 4; d++) {
						int nx = i + xd[d];
						int ny = j + yd[d];

						if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
						if (grid[nx][ny] < k) continue;

						cnt-=Union(parent, i * n + j, nx * n + ny);
					}
				}
			}
		}
		maxv = max(maxv, cnt);
	}
	cout << maxv;
}
*/