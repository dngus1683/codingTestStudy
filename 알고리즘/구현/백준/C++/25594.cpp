// HG 음성기호
// NATO 표준음성기호를 본 따 HG 음성기호를 만들었다. 문자열이 주어질 때, HG 음성기호만으로 이루어져 있는지 확인하고 원래 단어를 출력하라.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

string S = "";
string answer = "";
string HG[26] = { "aespa"
, "baekjoon"
, "cau"
, "debug"
, "edge"
, "firefox"
, "golang"
, "haegang"
, "iu"
, "java"
, "kotlin"
, "lol"
, "mips"
, "null"
, "os"
, "python"
, "query"
, "roka"
, "solvedac"
, "tod"
, "unix"
, "virus"
, "whale"
, "xcode"
, "yahoo"
, "zebra" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;

	for (int idx = 0; idx < S.length();)
	{
		char startC = S[idx];
		int hgIdx = 0;

		while (hgIdx < HG[startC - 'a'].length())
		{
			if (HG[startC - 'a'][hgIdx] != S[idx])
			{
				cout << "ERROR!" << '\n';
				return 0;
			}
			hgIdx++;
			idx++;
		}

		answer += startC;
	}

	cout << "It's HG!" << '\n' << answer << '\n';
}