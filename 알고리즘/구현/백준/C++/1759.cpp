// 암호 만들기
// 주어진 C개의 문자로 길이가 L이며, 오름차순이고 최소 하나의 모음은 포함하는 비밀번호들을 모두 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int L = 0;
int C = 0;
int IsUsedVowel = 0;
string Inputs = "";
string answer = "";
unordered_map<char, bool> IsVowel;

void func(int start)
{
	if (answer.length() == L && (IsUsedVowel > 0 && IsUsedVowel < L-1))
	{
		cout << answer << '\n';
		return;
	}

	for (int i = start; i < C; i++)
	{
		if (IsVowel[Inputs[i]])
		{
			IsUsedVowel++;
		}
		answer.push_back(Inputs[i]);
		func(i + 1);
		answer.pop_back();
		if (IsVowel[Inputs[i]])
		{
			IsUsedVowel--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	IsVowel['a'] = true;
	IsVowel['e'] = true;
	IsVowel['i'] = true;
	IsVowel['o'] = true;
	IsVowel['u'] = true;

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char chr = ' ';

		cin >> chr;
		Inputs.push_back(chr);
	}

	sort(Inputs.begin(), Inputs.end());

	func(0);
}