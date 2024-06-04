// 치즈
// N x M 크기의 모눈종이 위에 치즈가 놓여있다. 상하좌우 2변 이상 빈 공간과 마주하고 있다면 그 치즈는 1시간 후 녹아 없어진다. 치즈로 둘러쌓인 빈 공간에 대해서는 녹지 않는다.
// 치즈가 모두 녹는 시간을 구하라.


// 내 답안1
// MAX_N이 100이기 때문에 삼중 반복문이어도 충분할 것이라 판단
// == 알고리즘 ==
// simulation: 인접한 픽셀 중 2개 이상이 -1(외부 공기)이라면 해당 픽셀값을 -1로 변경. 외부 공기로 변환되었을 때, 해당 픽셀 주변에 0(내부 공기)가 있다면 그 공기에 대한 CheckOutside 함수 호출
// CheckOutside: 해당 픽셀을 기준으로, 0값을 가진 인접한 픽셀들은 모두 -1로 값을 교체 DFS. 
// 1. CheckOuside함수를 통해 외부 공기는 -1, 내부 공기는 0로 분할.
// 2. 모든 픽셀 값을 순회하며, 값이 1이면 simulation 함수 호출. 한 픽셀이라도 값을 1을 가지면 cnt 상승 & 2단계 반복
// 3. 모든 픽셀 값이 0이면 cnt 출력.
#include <iostream>

#define MAX_N 101

using namespace std;


int N = 0;
int M = 0;
int graph1[MAX_N][MAX_N];
int graph2[MAX_N][MAX_N];
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

void CheckOutside(int NowI, int NowJ, int graph[MAX_N][MAX_N])
{
	graph[NowI][NowJ] = -1;
	for (int i = 0; i < 4; i++)
	{
		if (NowI + di[i] < 0 || NowI + di[i] >= N || NowJ + dj[i] < 0 || NowJ + dj[i] >= M)
			continue;
		if (graph[NowI + di[i]][NowJ + dj[i]] == 0)
			CheckOutside(NowI + di[i], NowJ + dj[i], graph);
	}
}

void Simulation(int NowI, int NowJ, int im[MAX_N][MAX_N], int ex[MAX_N][MAX_N])
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (NowI + di[i] < 0 || NowI + di[i] >= N || NowJ + dj[i] < 0 || NowJ + dj[i] >= M)
			continue;
		if (ex[NowI + di[i]][NowJ + dj[i]] == -1)
			flag++;
	}
	if (flag >= 2)
	{
		im[NowI][NowJ] = -1;
		for (int i = 0; i < 4; i++)
		{
			if (NowI + di[i] < 0 || NowI + di[i] >= N || NowJ + dj[i] < 0 || NowJ + dj[i] >= M)
				continue;
			if (ex[NowI + di[i]][NowJ + dj[i]] == 0)
				CheckOutside(NowI + di[i], NowJ + dj[i], im);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int flag = 0;
	int ans = 0;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph1[i][j];
			if (graph1[i][j] == 1) flag = 1;
		}
	}

	CheckOutside(0, 0, graph1);

	while (flag)
	{
		flag = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				graph2[i][j] = graph1[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (graph1[i][j] == 1)
				{
					flag = 1;
					Simulation(i, j, graph1, graph2);
				}
			}
		}
		if(flag == 1)
			ans++;
	}
	cout << ans << '\n';
}






// 답안 예시1 - https://www.acmicpc.net/source/67541378
// 우선순위 큐 사용
// 100% 외부 공기인 (0, 0)에서 시작. -> 인접한 외부 공기(0)를 우선순위 큐에 포함. 그리고 그 외부 공기 값을 0에서 a로 교체(visited 역할) -> 인접한 치즈(1)를 만나면 해당 값을 2로 교체. (큐에 넣지는 않음) 
// -> 큐를 통해 외부 공기를 돌다가 인접한 픽셀 값이 2라면, 해당 치즈는 외부 공기를 두 번 만난 것 == 인접한 외부공기가 두 군데 이므로 cnt값을 하나 늘리고 해당 위치를 큐에 넣음. 그리고 해당 값은 방문한 외부 공기 a로 바꿈
// -> 그렇게 만난 치즈 개수가 총 치즈 개수와 같아지면 cnt 출력.
/*
//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int main() {
	char g[101][101];
	short n, m;
	short dy[] = { 1,-1,0,0 };
	short dx[] = { 0,0,1,-1 };
	short t = 0;
	scanf("%hd %hd", &n, &m);

	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			scanf(" %c", &g[i][j]);
			if (g[i][j] == '1') {
				t++;
			}
		}
	}
	priority_queue<pair<short, pair<short, short>>> air;
	air.push({ 0, {1,1} });
	g[1][1] = 'a';
	short a = 0;
	while (!air.empty()) {
		short y = air.top().second.first;
		short x = air.top().second.second;
		short cnt = -air.top().first;
		air.pop();
		for (short i = 0; i < 4; ++i) {
			short ny = y + dy[i];
			short nx = x + dx[i];
			if (nx >= 1 && ny >= 1 && ny <= n && nx <= m) {
				if (g[ny][nx] == 'a') continue;
				else if(g[ny][nx] != '0'){
					if (g[ny][nx] == '1') {
						g[ny][nx] = '2';
						continue;
					}
					else {
						a++;
						if (a == t) {
							printf("%hd", cnt + 1);
							return 0;
						}
						air.push({ -(cnt + 1), {ny, nx} });
						g[ny][nx] = 'a';
					}
				}
				else {
					g[ny][nx] = 'a';
					air.push({ -cnt, {ny,nx} });
				}
			}
		}
	}
}

*/