// 1로 만들기
// 정수 x에 대해 할 수 있는 계산은 세가지(1. 3으로 나누기, 2. 2로 나누기, 3. 1 빼기). 정수 N이 주어졌을 때, 1로 만드는 연산 횟수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <cmath>

#define MAX_N 1000001

using namespace std;

int d[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    d[0] = 0;
    d[1] = 0;
    for(int i=2; i<=N; i++)
    {
        d[i] = d[i-1] + 1;
        if(i%2==0)
            d[i] = min(d[i], d[i/2]+1);
        if(i%3==0)
            d[i] = min(d[i],d[i/3]+1);
    }

    cout << d[N] << '\n';
}








// 답안 예시1 - https://www.acmicpc.net/source/45900016
//#include <stdio.h>
//int f(int x)
//{
//	if(x<=1) return 0;
//	int d1=f(x/3)+x%3+1;
//	int d2=f(x/2)+x%2+1;
//	return d1<d2?d1:d2;
//}
//int main(){
//	int N;
//	scanf("%d", &N);
//	printf("%d", f(N));
//}