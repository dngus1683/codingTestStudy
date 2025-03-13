// 애너그램 그룹
// 영어단어 w가 다른 단어 v의 애너그램이 되려먼 알파벳의 순서을 바꿔서 만들 수 있어야 한다.
// 단어들이 주어질 때, 가장 큰 애너그램 그룹 다섯 개를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, set<string>>> arr(30001);
unordered_map<string, int> hmap;

bool compare(pair<int, set<string>>& p1, pair<int, set<string>>& p2)
{
	if (p1.first != p2.first)
	{
		return p1.first > p2.first;
	}
	else
	{
		return *p1.second.begin() < *p2.second.begin();
	}
}

int main()
{
	int idx = 0;
	string s = "";
	while (cin >> s)
	{
		string sKey = s;
		sort(sKey.begin(), sKey.end());

		if (hmap.find(sKey) == hmap.end())
		{
			hmap[sKey] = idx;
			idx++;
		}
		arr[hmap[sKey]].first++;
		arr[hmap[sKey]].second.insert(s);
	}
	sort(arr.begin(), arr.begin() + idx, compare);

	for (int i = 0; i < 5; i++)
	{
		cout << "Group of size " << arr[i].first << ": ";
		for (string sOut : arr[i].second)
		{
			cout << sOut << ' ';
		}
		cout << '.' << '\n';
	}
}