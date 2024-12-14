// 킥다운
// 킥다운은 자동차에서 낮은 기어로 바꾸는 장치를 의미한다.
// 기어의 홈을 1, 이를 2라 하고, 두 기어의 이와 홈의 정보가 주어질 때, 두 기어가 맞물렸을 때 최소 길이를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int answer = 1000;
string s1 = "";
string s2 = "";


void func(string& a, string& b)
{
	for (int i = 0; i < a.length(); i++)
	{
		int idxI = i;
		int idxJ = b.length() - 1;
		bool possible = true;

		while (idxI >= 0 && idxJ >= 0)
		{
			if (a[idxI] == '2' && b[idxJ] == '2')
			{
				possible = false;
				break;
			}
			idxI--;
			idxJ--;
		}
		if (possible)
		{
			int length = max(max(a.length(), b.length()), a.length() + b.length() - (i + 1));
			answer = min(answer, length);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s1;
	cin >> s2;

	answer = s1.length() + s2.length();

	func(s1, s2);
	func(s2, s1);

	cout << answer << '\n';
	
}