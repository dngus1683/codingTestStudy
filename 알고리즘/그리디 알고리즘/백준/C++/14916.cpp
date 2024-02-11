// 거스름돈
// 춘향이는 편의점 카운터에서 일한다.
// 손님이 2원짜리와 5원짜리로만 거스름돈을 달라고 한다. 2원짜리 동전과 5원짜리 동전은 무한정 많이 가지고 있다. 동전의 개수가 최소가 되도록 거슬러 주어야 한다. 거스름돈이 n인 경우, 최소 동전의 개수가 몇 개인지 알려주는 프로그램을 작성하시오.
// 예를 들어, 거스름돈이 15원이면 5원짜리 3개를, 거스름돈이 14원이면 5원짜리 2개와 2원짜리 2개로 총 4개를, 거스름돈이 13원이면 5원짜리 1개와 2원짜리 4개로 총 5개를 주어야 동전의 개수가 최소가 된다.


// 내 답안1
#include <iostream>

using namespace std;

int n;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	if (n / 5 == 0 && n % 2 == 1) {
		cnt = -1;
	}
	else if ((n%5)%2) {
		cnt = (n / 5) - 1;
		n = (n % 5) + 5;
		cnt = cnt + (n / 2);
	}
	else {
		cnt = n / 5;
		n = n % 5;
		cnt = cnt + n / 2;
	}

	cout << cnt << '\n';

	return 0;
}




// 답안 예시1
//#include <stdio.h>
//
//int n;
//
//int main() {
//	scanf("%d", &n);
//
//	int cnt = 0;
//	while (n != 1 && n % 5 != 0) {
//		n = n - 2;
//		cnt++;
//	}
//
//	if (n == 1) cnt = -1;
//	else cnt += (n / 5);
//
//	printf("%d", cnt);
//}