// 최대 힙
// 최대 힙을 활용하여, 1. x를 배열에 넣고, 2. 배열에서 가장 큰 값을 출력하고 제거하는 연산을 지원하는 프로그램을 작성하라.


// 내 답안1
#include <iostream>
#include <queue>

#define MAX_N 100'001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	priority_queue<int> pq;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x = 0;

		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}


