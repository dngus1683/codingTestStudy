// 스택 수열
// 1~n까지의 정수가 중복없이 특정 수열로 주어진다. 1~n까지 수를 스택 자료구조에 push / pop을 하여 해당 수열을 만들어라.


// 내 답안1
#include <iostream>
#include <stack>
#include <vector>

#define MAX_N 100001

using namespace std;

int arr[MAX_N];
vector<char> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, idxR = 0, idxS = 1, num = 2;
	stack<int> sk;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sk.push(1);
	ans.push_back('+');

	for (int i = 2, ar = 0, an = 0; an < n*2; an++)
	{
		int t = (sk.empty() ? -1 : sk.top());

		if (arr[ar] == t)
		{
			sk.pop();
			ans.push_back('-');
			ar++;
		}
		else if(i <= n)
		{
			sk.push(i);
			ans.push_back('+');
			i++;
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans.size() != n*2)
		{
			cout << "NO" << '\n';
			break;
		}
		cout << ans[i] << '\n';
	}

}
