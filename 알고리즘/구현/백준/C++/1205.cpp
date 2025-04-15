// 등수 구하기
// N개의 비오름차순 랭커 점수가 주어진다. P 개수까지만 랭킹에 들어갈 수 있다고 할 때, 입력된 새로운 점수는 몇 등인지 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define MAX_N 51

using namespace std;

int N = 0;
int NewPoint = 0;
int P = 0;
vector<int> ranking(MAX_N , -1);
stack<int> rankS;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> NewPoint >> P;
	for (int i = 0; i < N; i++)
	{
		cin >> ranking[i];
	}
	sort(ranking.begin(), ranking.end(), greater<>());

	int idx = 0;
	int answer = 0;
	while(ranking[idx] >= NewPoint && idx < ranking.size())
	{
		rankS.push(ranking[idx]);
		idx++;
	}

	if (!rankS.empty() && rankS.size() == P)
	{
		cout << -1 << '\n';
	}
	else
	{
		while (!rankS.empty() && rankS.top() == NewPoint)
		{
			rankS.pop();
		}
		rankS.push(NewPoint);

		cout << rankS.size() << '\n';
	}


}





// 답안 예시 - https://www.acmicpc.net/source/79755499
// 훨씬 간단한 아이디어
/*
#include <stdio.h>

int main()
{
	int N,s,P,n,i,r=1;
	
	scanf("%d %d %d",&N,&s,&P);
	for(i=0;i<N;i++)
	{
	scanf("%d",&n);
	if(n>s) r++;
	}
	if(N==P&&n>=s) r=-1;
	printf("%d",r);
}
*/