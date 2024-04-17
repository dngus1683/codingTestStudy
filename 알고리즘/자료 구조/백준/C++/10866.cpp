// 덱
// 덱를 구현하라. 양의 정수 N이 주어질 때, N개의 덱 명령어를 수행하라.


// 내 답안1
#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	deque<int> dq;

	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		int num;
		string s, s1;
		stringstream ss;

		getline(cin, s);

		if (s.find(' ') != string::npos)
		{
			ss << s;
			ss >> s1 >> num;
		}
		else
			s1 = s;

		if (s1 == "push_front")
		{
			dq.push_front(num);
		}
		else if (s1 == "push_back")
		{
			dq.push_back(num);
		}
		else if (s1 == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s1 == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (s1 == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (s1 == "empty")
		{
			cout << dq.empty() << '\n';
		}
		else if (s1 == "front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else if (s1 == "back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}

}







// 답안 예시
// queue와 비슷한 방식으로, 양방향 queue를 구현해야 하므로 첫 배열 인덱스를 0이 아닌 중간값으로 잡고 좌우로 이동하도록 구현.
/*
#include <stdio.h>
int main() {
	int arr[20010];
	int top = 10000, bot = 10000;
	char com[10];
	int N;
	scanf("%d", &N);
	for (size_t i = 0; i < N; i++)
	{
		scanf("%s", com);
		if (com[1] == 'u' && com[5] == 'f') scanf("%d", &arr[--top]);
		else if (com[1] == 'u' && com[5] == 'b') scanf("%d", &arr[bot++]);
		else if (com[1] == 'o' && com[4] == 'f') printf("%d\n", bot - top ? arr[top++] : -1);
		else if (com[1] == 'o' && com[4] == 'b') printf("%d\n", bot - top ? arr[--bot] : -1);
		else if (com[1] == 'i') printf("%d\n", bot - top);
		else if (com[1] == 'm') printf("%d\n", bot - top ? 0 : 1);
		else if (com[1] == 'r') printf("%d\n", bot - top ? arr[top] : -1);
		else if (com[1] == 'a') printf("%d\n", bot - top ? arr[bot - 1] : -1);
	}
	return 0;
}
*/