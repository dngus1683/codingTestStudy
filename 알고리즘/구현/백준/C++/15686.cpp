// 치킨 배달
// N x N 크기의 맵에, 빈 칸 0, 집 1, 치킨집 2 가 주어진다. 치킨 거리는 집에서 가장 가까운 치킨집까지의 거리다. 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.
// M개의 치킨 집만 계속 영업을 하고 나머지 가게는 모두 폐업한다고 할 때, 도시의 치킨 거리의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 51
#define MAX_M 14

using namespace std;

int N = 0;
int M = 0;
int graph[MAX_N][MAX_N];
vector<int> dp[MAX_M];
vector<pair<int, int>> chickens;

inline int min(const int& a, const int& b)
{
	return (a < b ? a : b);
}

int CalDistance(int& a1, int & a2, int& b1, int& b2)
{
	int x = (a1 > b1 ? a1 - b1 : b1 - a1);
	int y = (a2 > b2 ? a2 - b2 : b2 - a2);

	return x + y;
}

int brute(int start, int size, vector<int>& pick, int count)
{
	if (count == 0)
	{
		int ans = 0;
		for (int i = 0; i < dp[0].size(); i++)
		{
			int mn = 987654321;
			for (auto idx : pick)
			{
				mn = min(mn, dp[idx][i]);
			}
			ans += mn;
		}
		return ans;
	}
	else
	{
		int ans = 987654321;
		for (int i = start + 1; i < size; i++)
		{
			pick.push_back(i);
			ans = min(ans, brute(i, size, pick, count - 1));
			pick.pop_back();
		}
		return ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
				chickens.push_back({ i, j });
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1)
			{
				for (int k = 0; k < chickens.size(); k++)
				{
					int dist = CalDistance(i, j, chickens[k].first, chickens[k].second);
					dp[k].push_back(dist);
				}
			}
		}
	}
	vector<int> pick;
	cout << brute(-1, chickens.size(), pick, M) << '\n';
}