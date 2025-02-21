// 암호
// 문자의 집합이 주어진다. 한 글자부터 집합의 순서대로 문자열을 만들어 암호를 찾으려 할 때, 몇 번의 시도로 암호를 풀 수 있는지 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_map>

#define MOD_NUM 900528

using namespace std;

string s = "";
string pwd = "";
int answer = 0;
unordered_map<char, int>hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	cin >> pwd;

	for (int i = 0; i < s.length(); i++)
	{
		hmap[s[i]] = i + 1;
	}
	int num = 1;
	for (int i = 1; i <= pwd.length() - 1; i++)
	{
		num *= (s.length() % MOD_NUM);
		num %= MOD_NUM;

		answer += num;
		answer %= MOD_NUM;
	}

	int mulNum = 1;
	for (int i = pwd.length() - 1; i >= 0; i--)
	{
		answer += ((hmap[pwd[i]] - 1) * mulNum) % MOD_NUM;
		answer %= MOD_NUM;

		mulNum *= s.length();
		mulNum %= MOD_NUM;
	}
	answer = (answer + 1) % MOD_NUM;

	cout << answer << '\n';
}

/*
abcdefghijklmnopqrstuvwxyz
bfk

1 * 26 * 26 + 1 * 5 * 26 + 1 * 1 * 10 + 1

(b-1) * 26 ^ 2 + (f-1)*26^1 + (k-1) * 26^0 +1

2 * 6 * 11 = 23
*/