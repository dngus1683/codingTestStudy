// ??!
// 어느 사이트에 회원가입을 할 아이디가 주어진다.
// 해당 아이디는 이미 존재하여 (아이디 + ??!)로 놀람을 표현한다.
// 아이디가 주어질 때 적절할 놀람을 표현하라.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

string s = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	cout << s << "??!" << '\n';
}