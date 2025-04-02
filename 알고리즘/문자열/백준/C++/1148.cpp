// 단어 만들기
// 3x3 크기의 퍼즐판에 알파벳이 놓여있다. 정중앙의 알파벳은 무조건 사용하고, 4개 이상, 각 알파벳 당 한 번씩만 사용하여 단어를 만든다.
// 단어 사전과 퍼즐판 정보가 주어질 때, 만들 수 있는 단어의 개수가 가장 많을 때와 적을 때 중앙에 놓이는 알파벳을 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int cnt = 0;
int dict[200001][26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		string s = "";

		cin >> s;
		if (s == "-") break;

		for (char c : s)
		{
			dict[cnt][c - 'A']++;
		}
		cnt++;
	}

	while (true)
	{
		int mn = 987654321;
		int mx = 0;
		string puzzle = "";
		vector<int> alpha(26);
		vector<int> answer(26);
		set<char> minSet;
		set<char> maxSet;

		cin >> puzzle;
		if (puzzle == "#") break;

		for (char c : puzzle)
		{
			alpha[c-'A']++;
		}

		for (int i = 0; i < cnt; i++)
		{
			bool possible = true;

			for (int j = 0; j < 26; j++)
			{
				if (dict[i][j] > alpha[j])
				{
					possible = false;
					break;
				}
			}

			if (possible)
			{
				for (int j = 0; j < 26; j++)
				{
					if (dict[i][j] > 0)
					{
						answer[j]++;
					}
				}
			}
		}

		for (char c : puzzle)
		{
			mn = min(mn, answer[c - 'A']);
			mx = max(mx, answer[c - 'A']);
		}
		for (char c : puzzle)
		{
			if (mn == answer[c - 'A'])
			{
				minSet.insert(c);
			}
		}
		for (char c : puzzle)
		{
			if (mx == answer[c - 'A'])
			{
				maxSet.insert(c);
			}
		}
		
		for (char c : minSet)
		{
			cout << c;
		}
		cout << ' ' << mn << ' ';
		for (char c : maxSet)
		{
			cout << c;
		}
		cout << ' ' << mx << '\n';
	}
}
