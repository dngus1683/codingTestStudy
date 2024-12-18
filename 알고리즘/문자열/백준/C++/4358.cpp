// 생태학
// 여러 나무의 종이 주어질 때, 각 종이 전체에서 몇 %를 차지하는지 구하라.


// 내 답안1
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

int total = 0;
string s = "";
set<string> treeName;
unordered_map<string, int> hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (getline(cin, s))
	{
		treeName.insert(s);
		hmap[s]++;
		total++;
	}

	for (string tree : treeName)
	{
		cout << fixed;
		cout.precision(4);

		cout << tree << ' ' << ((float)hmap[tree] / (float)total) * 100<< '\n';
	}

}