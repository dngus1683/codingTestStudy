// 감시
// N x M 크기의 방에 벽과 cctv가 주어진다. cctv의 종류는 총 5가지(1: 한 방향, 2: 일직선의 양 방향, 3: 수직의 양 방향, 4: 3방향, 5: 모든 방향)다. cctv는 벽을 뚫고 감시할 수 없다.
// cctv의 방향을 적절히 정해 cctv가 감시할 수 없는 사각지대의 최소 크기를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 9

using namespace std;

struct Point
{
	int i;
	int j;
	Point operator+(const Point& other)
	{
		return { i + other.i, j + other.j };
	}
};
struct CCTV
{
	Point p;
	int type;
};

Point direction[4] = { {-1, 0}, {1,0}, {0,-1},{0,1} };

int N = 0; 
int M = 0;
vector<vector<int>> office(MAX_N, vector<int>(MAX_N, 0));
vector<CCTV> cctvs;


void detect(Point start, const Point& dir, vector<vector<bool>>& visited)
{
	while (true)
	{
		if ((start + dir).i < 0 || (start + dir).i >= N || (start + dir).j < 0 || (start + dir).j >= M) break;
		if (office[(start + dir).i][(start + dir).j] == 6) break;
		else
		{
			start = start + dir;
			visited[start.i][start.j] = true;
		}
	}
}

int func(int i, vector<vector<bool>>& visited)
{	
	if (i == cctvs.size())
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visited[i][j] && office[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}

	int answer = 987654321;
	vector<vector<bool>> tmp = visited;

	if (cctvs[i].type == 1)
	{
		for (int k = 0; k < 4; k++)
		{
			detect(cctvs[i].p, direction[k], tmp);
			answer = min(answer, func(i + 1, tmp));
			tmp = visited;
		}
	}
	else if (cctvs[i].type == 2)
	{
		for (int k = 0; k < 4; k += 2)
		{
			detect(cctvs[i].p, direction[k], tmp);
			detect(cctvs[i].p, direction[k+1], tmp);
			answer = min(answer, func(i + 1, tmp));
			tmp = visited;
		}
	}
	else if (cctvs[i].type == 3)
	{
		for (int k = 0; k < 2; k++)
		{
			detect(cctvs[i].p, direction[k], tmp);
			detect(cctvs[i].p, direction[2], tmp);
			answer = min(answer, func(i + 1, tmp));
			tmp = visited;
		}
		for (int k = 0; k < 2; k++)
		{
			detect(cctvs[i].p, direction[k], tmp);
			detect(cctvs[i].p, direction[3], tmp);
			answer = min(answer, func(i + 1, tmp));
			tmp = visited;
		}
	}
	else if (cctvs[i].type == 4)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == k) continue;
				detect(cctvs[i].p, direction[j], tmp);
			}
			answer = min(answer, func(i + 1, tmp));
			tmp = visited;
		}
	}
	else if (cctvs[i].type == 5)
	{
		for (int k = 0; k < 4; k++)
		{
			detect(cctvs[i].p, direction[k], tmp);
		}
		answer = min(answer, func(i + 1, tmp));
		tmp = visited;
	}

	return answer;
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
			cin >> office[i][j];

			if (office[i][j] != 0 && office[i][j] != 6)
			{
				cctvs.push_back({ {i, j}, office[i][j]});
			}
		}
	}
	vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_N, false));

	cout << func(0, visited) << '\n';
}
