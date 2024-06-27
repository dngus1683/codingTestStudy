// A -> B
// 정수 A를 B로 바꾸려고 한다.가능한 연산은 다음과 같은 두 가지이다.
// + 2를 곱한다.
// + 1을 수의 가장 오른쪽에 추가한다.
// A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.


// 내 답안1
#include <iostream>
#include <queue>
#include <map>

#define MAX_N 987654321

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int A = 0;
	long long int B = 0;

	cin >> A >> B;

	priority_queue<pair<long long int, long long int>> pq;
	map<long long int, long long int> m;
	
	pq.push({ 0, A });
	m[A] = 0;

	while (!pq.empty())
	{
		long long int now = pq.top().second;
		long long int dist = -pq.top().first;
		pq.pop();

		if (m[now] < dist) continue;
		if ((m.find(now * 2) == m.end() || m[now * 2] > dist + 1) && ((now * 2) <= B))
		{
			m[now * 2] = dist + 1;
			pq.push({ -(dist + 1), now * 2 });
		}
		if ((m.find((now * 10) + 1) == m.end() || m[(now * 10) + 1] > dist + 1) && (((now * 10) + 1) <= B))
		{
			m[(now * 10) + 1] = dist + 1;
			pq.push({ -(dist + 1), (now * 10) + 1 });
		}
	}


	cout << (m[B] == 0 ? -1 : m[B]+1) << '\n';
}










// 답안 예시1 - https://www.acmicpc.net/source/30166154
// 이 알고리즘은 A->B가 아닌 B->A로 거꾸로 계산한다.
// B의 첫째자리 수가 1이 아닌 홀수라면 불가능하다. 
// 그 이외의 경우, 첫째자리가 1이라면 1부터 없애야 하며, 짝수라면 2를 나누는 수 밖에 없다.
// 계속 연산했을 때 B가 A보다 작아졌다면 이 역시 계산 불가능이라 판단한다.
/*
#include<stdio.h>

int a,b,s;
int main()
{
	scanf("%d%d",&a,&b);
	while(b!=a)
	{
		if((b%10!=1&&b%10%2)||b<a)
		{
			printf("-1");
			return 0;
		}
		if(b%10==1) b/=10;
		else b/=2;
		s++;
	}
	printf("%d",s+1);
}
*/