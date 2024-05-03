// 기타줄
// N개의 기타줄이 끊어졌다. 기타줄은 6개와 1개로 살 수 있는데, 적어도 N개를 사는데 필요한 돈의 수를 최소화하는 프로그램을 작성하라.


// 내 답안1
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




// 답안 예시1 - https://www.acmicpc.net/source/60007983
// #include <stdio.h>
// int main()
// {
//   int n, m, a, b, mp=1000, ms=1000;
//   scanf("%d%d",&n,&m);
//   while(m--) 
//   { 
//   scanf("%d%d",&a,&b); 
//   mp=(a<mp)?a:mp; 
//   ms=(b<ms)?b:ms; 
//   }
//   if(ms*6<mp)
//   mp=ms*6;
//   ms=((n%6)*ms>mp)?mp:(n%6)*ms;
//   printf("%d\n",(n/6)*mp+ms);
// }
