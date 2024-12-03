// 큐2
// 정수를 저장하는 큐를 구현하라.


// 내 답안1
#include <iostream>
#include <string>

#define MAX_N 2'000'001

using namespace std;

int N = 0;
int queue[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int push = 0;
	int pop = 0;

	while (N--)
	{
		string s = "";

		cin >> s;

		if (s == "push")
		{
			int num = 0;

			cin >> num;
			queue[push++] = num;
		}
		else if (s == "pop")
		{
			if (push == pop)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue[pop++] << '\n';
			}
		}
		else if (s == "size")
		{
			cout << push - pop << '\n';
		}
		else if (s == "empty")
		{
			if (push == pop)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (s == "front")
		{
			if (push == pop)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue[pop] << '\n';
			}
		}
		else if (s == "back")
		{
			if (push == pop)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue[push - 1] << '\n';
			}
		}
	}
}