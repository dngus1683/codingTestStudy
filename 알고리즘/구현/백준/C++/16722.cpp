// 결! 합!
// 배경색, 도형모양, 도형색이 다양한 그림 3개가 주어진다. 각 그림의 속성이 모두 같거나 모두 다르면 '합'이다.
// 그림이 총 9개가 주어진다. 합의 조합마다 +1점, 모든 합이 다 나왔을 때, '결'을 외치면 +3점, 합이 아닌 조합이나 잘못된 결을 외치면 -1점.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int TotalOfH = 0;
int answer = 0;
int cnt = 0;
bool hset[10][10][10] = { false, };
vector<vector<int>> vec(9);

bool findH(vector<int>& picked)
{
	for (int i = 0; i < 3; i++)
	{
		bool allSame = vec[picked[0]][i] == vec[picked[1]][i] && vec[picked[1]][i] == vec[picked[2]][i];
		bool allDiff = vec[picked[0]][i] != vec[picked[1]][i] && vec[picked[1]][i] != vec[picked[2]][i] && vec[picked[2]][i] != vec[picked[0]][i];
		if (!(allSame || allDiff))
		{
			return false;
		}
	}
	return true;
}

void backtracking(int start, vector<int>& picked)
{
	if (picked.size() == 3)
	{
		if (findH(picked))
		{
			hset[picked[0]+1][picked[1]+1][picked[2]+1] = true;
			TotalOfH++;
		}
		return;
	}

	for (int i = start; i < 9; i++)
	{
		picked.push_back(i);
		backtracking(i + 1, picked);
		picked.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			string s = "";

			cin >> s;
			if (s == "CIRCLE" || s == "YELLOW" || s == "GRAY")
			{
				vec[i].push_back(1);
			}
			else if (s == "SQUARE" || s == "RED" || s == "BLACK")
			{
				vec[i].push_back(2);
			}
			else
			{
				vec[i].push_back(3);
			}
		}
	}

	vector<int> picked;
	backtracking(0, picked);

	cin >> N;
	while (N--)
	{
		char c = ' ';
		int p1 = 0;
		int p2 = 0;
		int p3 = 0;

		cin >> c;

		if (c == 'H')
		{
			cin >> p1 >> p2 >> p3;

			int mn = min(p1, min(p2, p3));
			int mx = max(p1, max(p2, p3));
			int middle = p1 + p2 + p3 - mn - mx;

			if (hset[mn][middle][mx])
			{
				answer += 1;
				cnt++;
				hset[mn][middle][mx] = false;
			}
			else
			{
				answer -= 1;
			}
		}
		else if(c == 'G')
		{
			if (cnt == TotalOfH)
			{
				answer += 3;
				TotalOfH = -1;
			}
			else
			{
				answer -= 1;
			}
		}
	}

	cout << answer << '\n';
}