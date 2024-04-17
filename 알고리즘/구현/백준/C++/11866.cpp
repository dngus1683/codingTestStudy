// 요세푸스 문제 0
// 정수 N, K가 주어질 때, 1~N이 원으로 나열되어 있고, K번째 숫자를 계속해서 제거해나간다. 제거된 수의 순서를 나열한 것을 요세푸스 순열이라 한다. 
// N, K가 주어졌을 때 요세푸스 순열을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ans;
queue<int> q1, q2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, cnt = 1, flag = 1;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q1.push(i);

	while (!(ans.size() == n))
	{
		if (q1.empty()) flag = 2;
		if (q2.empty()) flag = 1;

		if (flag == 2)
		{
			if (cnt == k)
			{
				ans.push_back(q2.front());
				q2.pop();
				cnt = 1;
			}
			else
			{
				q1.push(q2.front());
				q2.pop();
				cnt++;
			}
		}
		else if (flag == 1)
		{
			if (cnt == k)
			{
				ans.push_back(q1.front());
				q1.pop();
				cnt = 1;
			}
			else
			{
				q2.push(q1.front());
				q1.pop();
				cnt++;
			}
		}

	}

	cout << '<';
	for (int i = 0; i < n - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[n - 1] << '>' << '\n';
}