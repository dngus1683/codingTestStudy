// 베스트셀러
// 오늘 하루 동안 팔린 책의 제목이 입력으로 들어왔을 때, 가장 많이 팔린 책의 제목을 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N = 0;
int mx = 0;
string answer = "";
unordered_map<string, int> hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--)
	{
		string s = "";

		cin >> s;

		hmap[s]++;
	}

	for (auto it = hmap.begin(); it != hmap.end(); it++)
	{
		if (mx < (*it).second)
		{
			answer = (*it).first;
			mx = (*it).second;
		}
		else if (mx == (*it).second && answer > (*it).first)
		{
			answer = (*it).first;
			mx = (*it).second;
		}
	}

	cout << answer << '\n';
}