// 에디터
// 영어 소문자로 이루어진 문자열이 주어진다.
// L: 커서를 왼쪽으로 한 칸 옮김.
// D: 커서를 오른쪽으로 한 칸 옮김.
// B: 커서 왼쪽의 문자를 삭제.
// P $: 커서 왼쪽에 새로 입력된 문자 $를 추가.
// M개의 명령어를 실행했을 때, 문자열의 결과를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int M = 0;
list<char>::iterator cursor;
string s = "";
list<char> slist;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> s;
	for (char c : s)
	{
		slist.push_back(c);
	}
	cursor = slist.end();

	cin >> M;
	while (M--)
	{
		char command = ' ';

		cin >> command;

		if (command == 'L')
		{
			if (cursor != slist.begin())
			{
				cursor--;
			}
		}
		else if (command == 'D')
		{
			if (cursor != slist.end())
			{
				cursor++;
			}
		}
		else if (command == 'B')
		{
			if (cursor == slist.begin()) continue;
			cursor--;
			cursor = slist.erase(cursor);
		}
		else if (command == 'P')
		{
			char nc = ' ';

			cin >> nc;
			slist.insert(cursor, nc);
		}
	}
	for (char c : slist)
	{
		cout << c;
	}
	cout << '\n';


}