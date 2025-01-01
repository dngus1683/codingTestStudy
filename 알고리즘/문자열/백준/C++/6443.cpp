// 애너그램
// 한 문자의 철자들로 만들 수 있는 모든 단어를 애너그램이라 한다. 단어가 N개 주어질 때, 중복없이 알파벳 순으로 모든 애너그램을 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int N = 0;

void backtracking(string& s, string picked, set<string>& Sset, vector<int>& alpha)
{
	if (picked.length() == s.length())
	{
		Sset.insert(picked);
		return;
	}

	for (int i = 0; i < alpha.size(); i++)
	{
		if (alpha[i] > 0)
		{
			picked.push_back('a' + i);
			alpha[i]--;
			backtracking(s, picked, Sset, alpha);
			alpha[i]++;
			picked.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	while (N--)
	{
		vector<int> alpha(26, 0);
		string S = "";
		string picked;
		set<string> Sset;

		cin >> S;

		for (int i = 0; i < S.length(); i++)
		{
			alpha[S[i] - 'a']++;
		}

		backtracking(S, picked, Sset, alpha);

		for (string c : Sset)
		{
			cout << c << '\n';
		}
	}
}





// 답안 예시1
// 단어를 우선 정렬한 후 next_permutation()을 통한 순열 계산으로 출력.
/*
#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int N;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> str;
		sort(str.begin(), str.end());
		do {
			cout << str << '\n';
		} while (next_permutation(str.begin(), str.end()));
	}

	return 0;
}
*/