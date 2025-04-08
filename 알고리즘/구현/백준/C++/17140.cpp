// 이차원 배열과 연산
// 크기가 3x3인 배열이 있다. 해당 배열에 대해 매 초마다, 행 개수 >= 열 개수면 모든 행에 대한 정렬을, 그 반대면 열에 대한 정렬을 실행한다.
// 여기서 정렬이란, 각 행과 열에 포함된 숫자의 개수의 오름차순으로 진행되며, 개수가 같다면 숫자의 오름차순으로 정렬한다. 정렬한 후 기존의 배열에 추가한다.
// 배열의 크기가 100을 넘었다면, 처음 100개를 제외한 나머지는 버린다.
// 초기 배열 A와 r, c, k가 주어졌을 때, A[r][c]에 들어있는 값이 K가 되기 위한 최소 시간을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_N 101

using namespace std;

int r = 0;
int c = 0;
int k = 0;
int Rmax = 3;
int Cmax = 3;
int cnt = 0;
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N, 0));

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		vector<int> vec;
		for (int j = 1; j <= 3; j++)
		{
			cin >> graph[i][j];
		}
	}

	while (cnt != 100)
	{
		if (graph[r][c] == k) break;

		vector<vector<int>> tmp(MAX_N, vector<int>(MAX_N, 0));

		if (Rmax >= Cmax)
		{
			for (int i = 1; i <= Rmax; i++)
			{
				vector<int> Ecnt(MAX_N, 0);
				set<pair<int, int>> arr;

				for (int j = 1; j <= Cmax; j++)
				{
					Ecnt[graph[i][j]]++;
				}
				for (int k = 1; k < MAX_N; k++)
				{
					if (Ecnt[k] != 0)
					{
						arr.insert({ Ecnt[k], k });
					}
				}

				int idx = 1;
				for (auto pair : arr)
				{
					if (idx == MAX_N) break;
					tmp[i][idx++] = pair.second;
					tmp[i][idx++] = pair.first;
				}
				Cmax = max(Cmax, (idx - 1));
			}
		}
		else
		{
			for (int j = 1; j <= Cmax; j++)
			{
				vector<int> Ecnt(MAX_N, 0);
				set<pair<int, int>> arr;

				for (int i = 1; i <= Rmax; i++)
				{
					Ecnt[graph[i][j]]++;
				}
				for (int k = 1; k < MAX_N; k++)
				{
					if (Ecnt[k] != 0)
					{
						arr.insert({ Ecnt[k], k });
					}
				}

				int idx = 1;
				for (auto pair : arr)
				{
					if (idx == MAX_N) break;
					tmp[idx++][j] = pair.second;
					tmp[idx++][j] = pair.first;
				}
				Rmax = max(Rmax, (idx - 1));
			}
		}
		graph = tmp;
		cnt++;
	}

	if (graph[r][c] == k)
	{
		cout << cnt << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}


}
