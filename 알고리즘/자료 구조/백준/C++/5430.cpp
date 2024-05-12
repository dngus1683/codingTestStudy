// AC
// 선영이가 AC라는 새로운 언어를 만들었다. AC의 함수 중에는 R, D가 있는데, R은 배열을 뒤집고, D는 첫 원소를 삭제한다.
// 각 테스트 케이스마다 배열과 일련의 함수가 주어질 때, 해당 함수를 수행하라.


// 내 답안1
// 직접 배열을 뒤집고 삭제함. -> 시간초과.
/*
#include <iostream>
#include <string>
#include <sstream>

#define MAX_P 100001
#define MAX_N 100001
using namespace std;

void Reverse(int* a, int n)
{
	int ReArr[MAX_N];

	for (int i = 0; i < n; i++)
	{
		ReArr[i] = a[n - i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = ReArr[i];
	}
}

void Delete(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		int n = 0;
		int Arr[MAX_N] = { 0 };
		bool flag = true;
		char Useless;
		string P;
		string InputArr;
		stringstream ss;

		cin >> P;
		cin >> n;
		cin >> InputArr;
		ss << InputArr;

		ss >> Useless;
		for (int i = 0; i < n; i++)
		{
			ss >> Arr[i] >> Useless;
		}

		for (int i = 0; i < P.length(); i++)
		{
			if (P[i] == 'R')
			{
				Reverse(Arr, n);
			}
			else if (P[i] == 'D')
			{
				if (n == 0)
				{
					flag = false;
					break;
				}
				else
				{
					Delete(Arr, --n);
				}
			}
		}

		if (!flag)
		{
			cout << "error" << '\n';
			continue;
		}

		cout << '[';
		for (int i = 0; i < n; i++)
		{
			cout << Arr[i];
			if (!(i == n - 1))
				cout << ',';
		}
		cout << ']';
	}
}
*/



// 내 답안2 - 정답
// 내 답안1과 같은 알고리즘이지만 직접 삭제하거나 뒤집지 않고, 인덱싱으로 구현.

#include <iostream>
#include <string>
#include <sstream>

#define MAX_P 100001
#define MAX_N 100001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		int n = 0;
		int start = 0;
		int NowIdx = 0;
		int end = 0;
		int Arr[MAX_N] = { 0 };
		bool flag = true;
		char Useless;
		string P;
		string InputArr;
		stringstream ss;

		cin >> P;
		cin >> n;
		cin >> InputArr;
		ss << InputArr;

		ss >> Useless;
		for (int i = 0; i < n; i++)
		{
			ss >> Arr[i] >> Useless;
		}

		end = n;
		for (int i = 0; i < P.length(); i++)
		{
			if (P[i] == 'R')
			{
				NowIdx = (NowIdx == start ? end : start);
			}
			else if (P[i] == 'D')
			{
				if (NowIdx == start)
				{
					NowIdx++;
					start++;
				}
				else
				{
					NowIdx--;
					end--;
				}
			}
		}

		if (start > end)
		{
			cout << "error" << '\n';
			continue;
		}
		else
		{
			cout << '[';
			if (NowIdx == start)
			{
				for (int i = start; i < end; i++)
				{
					cout << Arr[i];
					if (!(i == end-1))
						cout << ',';
				}
			}
			else
			{
				for (int i = end-1; i >= start; i--)
				{
					cout << Arr[i];
					if (!(i == start))
						cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}
}




// 내 답안3 - 정답
// deque stl 활용
/*
#include <iostream>
#include <string>
#include <sstream>
#include <deque>

#define MAX_P 100001
#define MAX_N 100001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		int n = 0;
		bool flag = true;
		bool Re = false;
		char Useless;
		string P;
		string InputArr;
		stringstream ss;
		deque<int> dq;

		cin >> P;
		cin >> n;
		cin >> InputArr;
		ss << InputArr;

		ss >> Useless;
		for (int i = 0; i < n; i++)
		{
			int a = 0;
			ss >> a >> Useless;
			dq.push_back(a);
		}

		for (int i = 0; i < P.length(); i++)
		{
			if (P[i] == 'R')
			{
				Re = !Re;
			}
			else if (P[i] == 'D')
			{
				if (dq.empty())
				{
					flag = false;
					break;
				}
				if (!Re)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (!flag)
		{
			cout << "error" << '\n';
			continue;
		}
		else
		{
			cout << '[';
			if (!Re)
			{
				while(!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ',';
				}
			}
			else
			{
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}
}
*/