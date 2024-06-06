// A + B - C
// 수가 3개 주어질 때, 수로서 A + B - C 값과, 문자열로서(A+B= AB, A-B = 수 뺴기와 동일) A + B - C 값을 출력하라.


// 내 답안1
#include <iostream>
#include <string>

#define MAX_N 1'000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string A = "";
	string B = "";
	int C = 0;

	cin >> A >> B >> C;

	cout << stoi(A) + stoi(B) - C << '\n';
	cout << stoi(A + B) - C << '\n';

}
