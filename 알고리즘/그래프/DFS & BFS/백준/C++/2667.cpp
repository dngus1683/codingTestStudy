// 단지번호붙이기
// N x N의 좌표에 집은 1로 주어진다. 상하좌우로 붙어있는 집끼리 하나의 단지라고 할 때, 총 단지 개수와 각 단지의 집 개수를 오름차순으로 출력하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 26

using namespace std;

char graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int HouseGroup[MAX_N * MAX_N];
int dn[4] = { -1, 1, 0, 0 };
int dm[4] = { 0, 0, -1, 1 };
int N = 0;

int bfs(int StartN, int StartM)
{
	int HouseCnt = 1;
	queue<pair<int, int>> q;
	q.push({ StartN, StartM });

	visited[StartN][StartM] = true;

	while (!q.empty())
	{
		int NowN = q.front().first;
		int NowM = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			bool IsOutOfBoundary = NowN + dn[i] < 0 || NowN + dn[i] >= N || NowM + dm[i] < 0 || NowM + dm[i] >= N;
			bool IsZeroNextCoord = graph[NowN + dn[i]][NowM + dm[i]] == '0';
			if (IsOutOfBoundary || IsZeroNextCoord) continue;

			if (!visited[NowN + dn[i]][NowM + dm[i]])
			{
				HouseCnt++;
				visited[NowN + dn[i]][NowM + dm[i]] = true;
				q.push({ NowN + dn[i], NowM + dm[i] });
			}
		}
	}

	return HouseCnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int idx = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> graph[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && graph[i][j] == '1')
			{
				HouseGroup[idx++] = bfs(i, j);
			}
		}
	}

	sort(HouseGroup, HouseGroup + idx);

	cout << idx << '\n';
	for (int i = 0; i < idx; i++)
		cout << HouseGroup[i] << '\n';
}