// 문자열 집합
// 총 N개의 문자열로 이루어진 집합 S가 주어진다.
// 입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_set>

#define MAX_N 10'001
#define MAX_M 10'001

using namespace std;

int N = 0;
int M = 0;
int answer = 0;
unordered_set<string> uset;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s = "";

		cin >> s;
		uset.insert(s);
	}
	for (int i = 0; i < M; i++)
	{
		string s = "";

		cin >> s;

		if (uset.find(s) != uset.end())
		{
			answer++;
		}
	}

	cout << answer << '\n';
}