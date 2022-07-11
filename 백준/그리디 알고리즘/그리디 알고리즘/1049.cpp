/* 그리디 알고리즘 1049 기타줄 구매 (실버4)
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	int prc[2][50] = {};

	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &prc[0][i], &prc[1][i]);
	}
	sort(prc[0], prc[0] + m);
	sort(prc[1], prc[1] + m);


	if (prc[1][0] * 6 <= prc[0][0]) {
		printf("%d\n", prc[1][0] * n);
	}
	else {
		if (int rem = n % 6) {
			if (((prc[0][0] * (n / 6)) + prc[0][0]) <= ((prc[0][0] * (n / 6)) + prc[1][0] * rem)) {
				printf("%d\n", ((prc[0][0] * (n / 6)) + prc[0][0]));
			}
			else {
				printf("%d\n", ((prc[0][0] * (n / 6)) + prc[1][0] * rem));
			}
		}
		else {
			printf("%d\n", ((prc[0][0] * (n / 6))));
		}
	}


	return 0;

}
*/



/*
    < min()을 활용한 답안 >
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n,m,s=1000,t=1000,a,b;
	scanf("%d%d",&n,&m);
	while(m--)
		scanf("%d%d",&a,&b),t=min(t,a),s=min(s,b);
	a=0;
	while(n>=6)
		a+=min(t,s*6),n-=6;
	printf("%d",a+min(t,s*n));
}
*/

/*
	< 삼항 연산지를 활용한 답안 >
#include<stdio.h>

int n,m,i,p,q,a,b;
int main(){
	scanf("%d%d",&n,&m);
	p=q=9999;
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		p=p<a?p:a;
		q=q<b?q:b;
	}
	p=p<q*6?p:q*6;
	printf("%d",n/6*p+(n%6*q<p?n%6*q:p));
}
*/