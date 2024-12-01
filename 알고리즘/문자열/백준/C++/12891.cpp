// DNA 비밀번호
// A, C, G, T로만 이루어진 문자열이 주어진다. 해당 문자열의 길이가 N인 부분 문자열 중, 네 알파벳의 각각 최소 개수를 만족하는 부분 문자열의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <map>
#include <string>

#define MAX_L 1'000'001

using namespace std;

int L = 0;
int N = 0;
int answer = 0;
string s;
int cnt[4];
int least[4];
map<char, int> DNA = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};


bool IsPossible()
{
	for (int i = 0; i < 4; i++)
	{
		if (cnt[i] < least[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> L >> N;
	cin >> s;
	for (int i = 0; i < 4; i++)
	{
		cin >> least[i];
	}

	for (int i = 0; i < N; i++)
	{
		cnt[DNA[s[i]]]++;
	}
	if (IsPossible())
	{
		answer++;
	}

	for (int i = 0; i < L - N; i++)
	{
		cnt[DNA[s[i]]]--;
		cnt[DNA[s[i+N]]]++;
		if (IsPossible())
		{
			answer++;
		}
	}

	cout << answer << '\n';
}