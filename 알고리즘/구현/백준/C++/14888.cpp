// 연산자 끼워넣기
// N개의 수로 이루어진 수열이 주어진다. 각 수 사이에 사칙연산을 넣는다. 이때 계산은 연산자 우선 순위를 무시하고 앞에서 부터 차례대로 계산한다.
// 만들 수 있는 식의 결과의 최댓값과 최솟값을 구하라.


// 내 답안1
// next_permutation을 활용해 연산자들의 순열을 구한 다음 각 순열에 따른 결과를 비교.
#include <iostream>
#include <algorithm>
#include <vector>

#define PINF 1'000'000'001
#define NINF -1'000'000'001
#define MAX_N 12
#define MAX_A 101

using namespace std;

int num[MAX_N];
vector<char> opr;
char OprSym[4] = { '+', '-', '*', '/' };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int mx = NINF;
	int mn = PINF;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;

		cin >> cnt;
		while (cnt--)
		{
			opr.push_back(OprSym[i]);
		}
	}

	sort(opr.begin(), opr.end());

	do
	{
		int sum = num[0];
		for (int i = 0; i < N-1; i++)
		{
			if (opr[i] == '+')
			{
				sum = sum + num[i + 1];
			}
			else if (opr[i] == '-')
			{
				sum = sum - num[i + 1];
			}
			else if (opr[i] == '*')
			{
				sum = sum * num[i + 1];
			}
			else if (opr[i] == '/')
			{
				sum = sum / num[i + 1];
			}
		}
		mn = min(mn, sum);
		mx = max(mx, sum);

	} while (next_permutation(opr.begin(), opr.end()));

	cout << mx << '\n' << mn << '\n';
}














// 답안 예시1 - https://www.acmicpc.net/source/24716821
// 완전 탐색, 백트래킹
/*
#include<stdio.h>
int N,A[11],a,s,m,d,G=-1e9,L=1e9;
void f(int l,int v){
	if(l==N){
		if(G<v)G=v;
		if(L>v)L=v;
		return;
	}
	if(a)--a,f(l+1,v+A[l]),++a;
	if(s)--s,f(l+1,v-A[l]),++s;
	if(m)--m,f(l+1,v*A[l]),++m;
	if(d)--d,f(l+1,v/A[l]),++d;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;++i)scanf("%d",A+i);
	scanf("%d%d%d%d",&a,&s,&m,&d);
	f(1,A[0]);
	printf("%d\n%d",G,L);
}
*/