// 서로 다른 부분 문자열의 개수
// 문자열 S가 주어졌을 때, 서로 다른 부분 문자열의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int answer = 0;
string s = "";
unordered_set<string> hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 0; j <= s.length() - i; j++)
		{
			if (hmap.find(s.substr(j, i)) == hmap.end())
			{
				answer++;
				hmap.insert(s.substr(j, i));
			}
		}
	}

	cout << answer << '\n';
}