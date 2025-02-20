// 졸려
// 눈을 깜박일 때마다 문자열의 배열이, 뒤에서 부터 앞의 짝수 번째 위치로 이동하게 된다.
// 눈을 깜박인 횟수 X와 깜박인 후 본 단어가 주어질 때, 원래의 단어를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>

#define MAX_X 1'000'000'001

using namespace std;

int X = 0;
string S = "";
string answer = "";
vector<string> vec;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> X;
	cin >> S;

	int cnt = 1;
	string tmp = S;

	while (true)
	{
		int idxL = 0;
		int idxR = tmp.length() - 1;
		string next = "";

		while (idxL < idxR)
		{
			next += tmp[idxL++];
			next += tmp[idxR--];
		}
		if (idxL == idxR)
		{
			next += tmp[idxL];
		}
		vec.push_back(next);

		if (next == S)
		{
			X = X % cnt;
			cout << vec[vec.size() - 1 - X] << '\n';
			break;
		}
		cnt++;
		tmp = next;
	}
}