// 큐
// 큐를 구현하라. 양의 정수 N이 주어질 때, N개의 큐 명령어를 수행하라.


// 내 답안1
/*
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	queue<int> q;

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

		if (s1 == "push")
		{
			q.push(num);
		}
		else if (s1 == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s1 == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s1 == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (s1 == "front")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (s1 == "back")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
	}

}

*/


// 내 답안2
// queue 사용하지 않고 구현
#include <iostream>
#include <string>
#include <sstream>

#define MAX_N 10001

using namespace std;

int queue[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, front = 0, back = 0;

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
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

		if (s1 == "push")
		{
			queue[back] = num;
			back++;
		}
		else if (s1 == "pop")
		{
			if (back - front)
			{
				cout << queue[front] << '\n';
				front++;
			}
			else
				cout << -1 << '\n';
		}
		else if (s1 == "size")
		{
			cout << back - front << '\n';
		}
		else if (s1 == "empty")
		{
			cout << (back - front ? 0 : 1) << '\n';
		}
		else if (s1 == "front")
		{
			cout << (back - front ? queue[front] : -1) << '\n';
		}
		else if (s1 == "back")
		{
			cout << (back - front ? queue[back-1] : -1) << '\n';
		}
	}
}