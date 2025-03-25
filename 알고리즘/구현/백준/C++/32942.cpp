// 그래프와 그래프
// Ax + By = C의 계수가 주어진다. 해당 그래프를 지나는 1~10사이의 값인 점 (x, y)에 대해, x정점에서 y정점으로 향하는 간선을 추가하는 방향으로 그래프를 그릴 때, 최종 그래프를 출력하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int A = 0;
int B = 0;
int C = 0;
vector<set<int>> graph(11);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> C;

	for (int i = 1; i <= 10; i++)
	{
		if (B == 0)
		{
			if (A * i == C)
			{
				for (int j = 1; j <= 10; j++)
				{
					graph[i].insert(j);
				}
			}
		}
		else if (A == 0)
		{
			if (C % B == 0 && C / B >= 1 && C / B <= 10)
			{
				graph[i].insert(C / B);
			}
		}
		else if ((C - A * i) % B == 0 && (C - A * i) / B >= 1 && (C - A * i) / B <= 10)
		{
			graph[i].insert((C - A * i) / B);
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int n : graph[i])
		{
			cout << n << ' ';
		}
		if (graph[i].empty())
		{
			cout << 0;
		}
		cout << '\n';
	}
}