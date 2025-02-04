// 맥주 마시면서 걸어가기
// 50미터를 걷기 위해서는 맥주를 한 병 마셔야 한다. 총 20병의 맥주가 들어가는 박스를 들고 페스티벌로 향한다. 중간중간에 맥주를 다시 20병 채울 수 있는 편의점이 존재한다.
// 출발지점, 편의점들의 위치, 도착지점이 좌표료 주어질 때, 페스티벌에 도착할 수 있는지 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <cmath>

#define MAX_N 101
#define MAX_DISTANCE 20*50

using namespace std;

int T = 0;
int N = 0;

inline int CalDistance(int x1, int y1, int x2, int y2)
{
	return (abs(x1 - x2) + abs(y1 - y2));
}

bool dfs(int start, int end, bool visited[], vector<int> graph[] )
{
	visited[start] = true;
	if (start == end) return true;

	bool flag = false;

	for (int next : graph[start])
	{
		if (!visited[next])
		{
			if (dfs(next, end, visited, graph))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		pair<int, int> coord[MAX_N];
		vector<int> graph[MAX_N];
		bool visited[MAX_N] = { false, };

		cin >> N;
		for (int i = 0; i < N + 2; i++)
		{
			cin >> coord[i].first >> coord[i].second;
		}
		
		for (int i = 0; i < N + 2; i++)
		{
			for (int j = i; j < N + 2; j++)
			{
				if (CalDistance(coord[i].first, coord[i].second, coord[j].first, coord[j].second) <= MAX_DISTANCE)
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		if (dfs(0, N + 1, visited, graph))
		{
			cout << "happy" << '\n';
		}
		else
		{
			cout << "sad" << '\n';
		}
	}
}