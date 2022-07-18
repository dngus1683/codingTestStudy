/* 그리디 알고리즘 14916 거스름돈 (실버5)
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

*/


/*
#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);

	int cnt = 0;
	while (n != 1 && n % 5 != 0) {
		n = n - 2;
		cnt++;
	}

	if (n == 1) cnt = -1;
	else cnt += (n / 5);

	printf("%d", cnt);
}*/