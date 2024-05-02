// 듣보잡
// N개의 듣도 못한 명단과 M개의 보도 못한 명단이 주어질 때, 듣도 보도 못한 명단을 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

#define MAX_N 500001

using namespace std;

unordered_set<string> DontListen;
string SArr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int N, M, cnt = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;

		cin >> s;
		DontListen.insert(s);
	}
	for (int i = 0; i < M; i++)
	{
		string s;

		cin >> s;
		
		if (DontListen.find(s) != DontListen.end())
		{
			SArr[cnt++] = s;
		}
	}

	sort(SArr, SArr + cnt);

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
	{
		cout << SArr[i] << '\n';
	}
}