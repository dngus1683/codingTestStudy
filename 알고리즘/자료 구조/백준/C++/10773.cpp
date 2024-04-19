// 제로
// 정수 K가 주어진다. 이때 0이 주어지면 가장 최근에 입력된 정수를 지운다. 이렇게 나열된 모든 정수의 총 합을 구하라.


// 내 답안1
#include <iostream>
#include <stack>

#define MAX_K 100001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, ans = 0;
	stack<int> st;

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		
		cin >> a;

		if (a == 0 && !st.empty())
			st.pop();
		else
			st.push(a);
	}

	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}

	cout << ans << '\n';
}