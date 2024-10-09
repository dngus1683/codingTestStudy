// 소트인사이드
// 배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.


// 내 답안1
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> pq;
	int number = 0;

	cin >> number;
	while (number > 0)
	{
		pq.push(number % 10);
		number /= 10;
	}

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
}








// 답안 예시1 - https://www.acmicpc.net/source/32655933
// 자릿수 순서대로 하나씩 입력받고, 계수정렬 방식을 활용.
/*
#include<stdio.h>

int main() 
{ 
	int i, p[10] = {}; 
	for (; ~scanf("%1d", &i);)
		p[i]++; 
	for (i = 10; i--;)
		if (p[i]--)printf("%d", i++); 
}
*/