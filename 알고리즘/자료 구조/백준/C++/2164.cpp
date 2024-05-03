// 카드2
// N장의 카드 더미가 1이 맨 위로가도록 차례대로 정리되어 있다. 
// 1. 맨 위 카드를 버린다
// 2. 맨 위 카드를 맨 아래로 옮긴다.
// 위 과정을 계속해서 반복하였을 때, 마지막에 남게 되는 카드를 구하라.


// 내 답안1
// 시간 초과
/*
#include <iostream>
#include <vector>

#define MAX_N 500001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, flag = 0;
	vector<int> v;

	cin >> N;

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	while (v.size() != 1)
	{
		if (flag == 0)
		{
			v.erase(v.begin());
			flag = 1;
		}
		else
		{
			v.push_back(v[0]);
			v.erase(v.begin());
			flag = 0;
		}
	}

	cout << v[0] << '\n';

}
*/


// 내 답안2
// 틀린 접근
/*
#include <iostream>
#include <vector>

#define MAX_N 500001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, flag = 0;
	vector<int> v, a;

	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}
	
	while (v.size() != 1)
	{
		a = v;
		v.clear();
		if (flag == 0)
		{
			for (int i = 1; i < a.size(); i += 2)
			{
				v.push_back(a[i]);
			}
		}
		else
		{
			for (int i = 0; i < a.size(); i += 2)
			{
				v.push_back(a[i]);
			}
		}
		if (a.size() % 2 == 0) flag = 0;
		else flag = 1;
	}
	cout << v[0] << '\n';
}
*/



// 내 답안3
// 내 답안1에서 vector 대신 queue 활용. 시간 초과 해결.
// empty()는 시간 복잡도가 O(1)이지만 size()는 O(n)이 될 수 있으므로 내 답안1에서 시간 초과가 난 것 같다.
#include <iostream>
#include <queue>

#define MAX_N 500001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans, flag = 1;
	queue<int> q;

	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (1)
	{
		ans = q.front();
		if (flag == 0)
		{
			q.push(q.front());
			q.pop();
			flag = 1;
		}
		else
		{
			q.pop();
			flag = 0;
		}
		if (q.empty()) break;
	}

	cout << ans << '\n';

}






// 답안 예시1 - https://www.acmicpc.net/source/65655536
/*
#import<ios>

int s = 1, n;
main()
{
	for (scanf("%d", &n); s < n; s *= 2);
	printf("%d", 2 * n - s);
}
*/