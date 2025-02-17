// 폰 호석만
// 10진법 수인 X를 A진법으로 표현한 수와 B진법으로 표현한 수가 주어진다. 두 수를 보고 X, A, B를 구하라.
// 만약 그 조합이 여러 개라면 Multiple, 없다면 Impossible을 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull X = 0;
int A = 0;
int B = 0;
int AMin = 0;
int BMin = 0;
int cnt = 0;
string ANum = "";
string BNum = "";

ull ctou(char c)
{
	if (c - '0' >= 0 && c - '0' <= 9)
	{
		return c - '0';
	}
	else
	{
		return (c - 'a') + 10;
	}
}

ull func(string& s, int n)
{
	ull num = 0;
	ull e = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		num += ctou(s[i]) * e;
		e *= n;
	}
	return num;
}

int FindMax(string s)
{
	sort(s.begin(), s.end(), greater<>());

	return ctou(s[0])+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> ANum >> BNum;

	AMin = FindMax(ANum);
	BMin = FindMax(BNum);

	for (int i = AMin; i <= 36; i++)
	{
		ull an = func(ANum, i);
		for (int j = BMin; j <= 36 && i != j; j++)
		{
			ull bn = func(BNum, j);

			if (an == bn)
			{
				X = an;
				A = i;
				B = j;
				cnt++;
			}
		}
	}

	if (cnt == 1)
	{
		cout << X << ' ' << A << ' ' << B << endl;
	}
	else if (cnt == 0)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << "Multiple" << endl;
	}
}
