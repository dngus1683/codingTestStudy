// 최소 힙
// 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하라.
// 1. 배열에 자연수 x를 넣는다.
// 2. 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.


// 내 답안1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	priority_queue<int> pq;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;

		scanf("%d", &num);
		if (num == 0)
		{
			if (pq.empty()) printf("0\n");
			else
			{
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(-num);
		}
	}
}