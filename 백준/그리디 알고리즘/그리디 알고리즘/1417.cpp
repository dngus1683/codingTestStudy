/* 그리디 알고리즘 1417 국회의원 선거 (실버5) 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int per[50] = {};
int cnt = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &per[i]);
	}

	sort(per+1, per + n , greater <int>());

	while (per[1] >= per[0]) {
		cnt++;
		per[0] += 1;
		per[1] -= 1;
		sort(per + 1, per + n, greater <int>());
	}

	printf("%d\n", cnt);

	return 0;
}
*/