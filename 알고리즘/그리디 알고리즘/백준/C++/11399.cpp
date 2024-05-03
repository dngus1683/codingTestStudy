// ATM
// N명의 사람이 ATM 기에서 볼 일 보는 시간이 주어진다. N명이 줄서서 기다리는 사간의 총 합의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		ans += ((N-i) * arr[i]);
	}

	cout << ans << '\n';

}


















// 답안 예시1 - https://www.acmicpc.net/source/32507301
// 계수를 활용하여 구현.
/*
#include<stdio.h>
int main(void){
	int n,a[1000]={0},k,s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);a[k-1]++;
	}
	k=0;
	while(n>0){
		if(a[k]>=1){
			s+=n*(k+1);a[k]--;n--;
		}
		else
			k++;
	}
	printf("%d",s);
}
*/