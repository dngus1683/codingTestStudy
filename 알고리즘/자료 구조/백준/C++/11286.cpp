// 절댓값 힙
// 절댓값 힙은 다음과 같은 연산을 지원하는 자료구조다.
// 1. 배열에 정수 x(!=0)를 넣는다. 
// 2. 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거한다. 가장 작은 값이 여러 개라면, 실제 가장 작은 수를 출력한다.


// 내 답안1
#include <iostream>
#include <queue>
#include <cmath>

#define MAX_N 100001

using namespace std;

typedef struct Num
{
	int x;
	bool operator < (const Num& a) const
	{
		if (abs(x) == abs(a.x)) return x > a.x;
		else return abs(x) > abs(a.x);
	}
}Num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	priority_queue<Num> pq;

	cin >> N;
	while (N--)
	{
		Num x;

		cin >> x.x;
		if (x.x == 0)
		{
			if (pq.empty()) cout << 0 << '\n';
			else
			{
				cout << pq.top().x << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
}