// 회사에 있는 사람
// 상근이는 자율 출퇴근 회사에 다니고 있다. 모든 사람의 출입 시스템 로그가 주어질 때, 현재 회사에 있는 모든 사람을 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
unordered_set<string> hset;
vector<string> leave;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	while (n--)
	{
		string name = "";
		string state = "";

		cin >> name >> state;

		if (state == "enter")
		{
			hset.insert(name);
		}
		else
		{
			hset.erase(name);
		}
	}
	for (string n : hset)
	{
		leave.push_back(n);
	}

	sort(leave.begin(), leave.end(), greater<>());
	for (string n : leave)
	{
		cout << n << '\n';
	}

}



// 답안 예시1 - https://www.acmicpc.net/source/66702794
// 출입 기록을 벡터로 받고 정렬한 다음, 이름이 중복되면 출력하지 않음.
/*
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<string> tlist(n);
	string tmp;

	for (auto& i : tlist)
		cin >> i >> tmp;

	sort(tlist.begin(), tlist.end(), greater<string>());

	for (int i = 0; i < n; i++) {
		if (i != n - 1 && tlist[i] == tlist[i + 1])
			i++;
		else
			cout << tlist[i] << "\n";
	}

	return 0;
}
*/