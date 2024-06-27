// 토마토
// N x M x H칸에 토마토가 들어있다. 토마토 하나가 익었다면 인접한 곳에 위치한 토마토도 익게 된다. 모든 토마토가 익는 최소 일수를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 101

using namespace std;

typedef struct Point
{
	int i = 0;
	int j = 0;
	int k = 0;
	int dist = 0;
	bool operator < (const Point& a) const
	{
		return dist > a.dist;
	}
}Point;

int N = 0;
int M = 0;
int H = 0;

int d[MAX_N][MAX_N][MAX_N];
int graph[MAX_N][MAX_N][MAX_N];
int di[6] = { -1, 1, 0, 0, 0 ,0 };
int dj[6] = { 0, 0, -1, 1, 0 ,0 };
int dk[6] = { 0, 0, 0, 0, -1 ,1 };

void dijkstra(Point start)
{
	priority_queue<Point> pq;
	pq.push(start);

	d[start.i][start.j][start.k] = 0;

	while (!pq.empty())
	{
		int IdxI = pq.top().i;
		int IdxJ = pq.top().j;
		int IdxK = pq.top().k;
		int dist = pq.top().dist;
		pq.pop();

		for (int i = 0; i < 6; i++)
		{
			if (IdxI + di[i] < 0 || IdxI + di[i] >= H || IdxJ + dj[i] < 0 || IdxJ + dj[i] >= N || IdxK + dk[i] < 0 || IdxK + dk[i] >= M)
				continue;
			
			int cost = 0;

			if (graph[IdxI + di[i]][IdxJ + dj[i]][IdxK + dk[i]] == -1) continue;
			else if (graph[IdxI + di[i]][IdxJ + dj[i]][IdxK + dk[i]] == 0)
				cost = d[IdxI][IdxJ][IdxK] + 1;
			else
				cost = 0;

			if (d[IdxI + di[i]][IdxJ + dj[i]][IdxK + dk[i]] > cost)
			{
				d[IdxI + di[i]][IdxJ + dj[i]][IdxK + dk[i]] = cost;
				pq.push({IdxI + di[i], IdxJ + dj[i], IdxK + dk[i], cost });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> graph[i][j][k];
			}
		}
	}

	fill(&d[0][0][0], &d[H - 1][N - 1][M], INF);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (graph[i][j][k] == 1 && d[i][j][k] != 0)
					dijkstra({i, j, k, 0});
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if(graph[i][j][k] != -1)
					ans = max(ans, d[i][j][k]);
			}
		}
	}

	if (ans >= INF)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
} 





// 답안 예시 - https://www.acmicpc.net/source/6640668
/*
#include <cstdio>

char b[100][100][100];
char buf[1<<15];
int idx = 1<<15;
struct pos { char z, y, x; int c; };

inline char read()
{
	if (idx == 1<<15)
	{
		fread(buf, 1, 1<<15, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt()
{
	int sum = 0;
	bool fl = false;
	char nw = read();

	while (nw == ' ' || nw == '\n' || nw == '\r') nw = read();
	if (nw == '-') fl = true, nw = read();
	while (nw >= '0' && nw <= '9')
	{
		sum = sum*10 + nw-48;
		nw = read();
	}

	return fl ? -sum : sum;
}
int main()
{
	int m, n, h;
	pos q[1000000];
	int fnt = 0, bck = 0;
	int zero = 0;

	m = readInt();
	n = readInt();
	h = readInt();
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				b[i][j][k] = readInt();
				if (b[i][j][k] == 1) {
					q[bck++] = { i,j,k,0 };
					b[i][j][k] = 2;
				}
				else if (!b[i][j][k]) zero++;
			}
		}
	}

	while (fnt != bck) {
		int z = q[fnt].z;
		int y = q[fnt].y;
		int x = q[fnt].x;
		int c = q[fnt].c + 1;

		fnt++;

		if (z && b[z - 1][y][x] == 0) zero--, q[bck++] = { z - 1,y,x,c }, b[z - 1][y][x] = 2;
		if (y && b[z][y - 1][x] == 0) zero--, q[bck++] = { z,y - 1,x,c }, b[z][y - 1][x] = 2;
		if (x && b[z][y][x - 1] == 0) zero--, q[bck++] = { z,y,x - 1,c }, b[z][y][x - 1] = 2;
		if (z < h - 1 && b[z + 1][y][x] == 0) q[bck++] = { z + 1,y,x,c }, b[z + 1][y][x] = 2, zero--;
		if (y < n - 1 && b[z][y + 1][x] == 0) q[bck++] = { z,y + 1,x,c }, b[z][y + 1][x] = 2, zero--;
		if (x < m - 1 && b[z][y][x + 1] == 0) q[bck++] = { z,y,x + 1,c }, b[z][y][x + 1] = 2, zero--;
	}

	printf("%d", zero > 0 ? -1 : q[--bck].c);

	return 0;
}
*/