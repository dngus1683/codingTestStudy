/* 그리디 알고리즘 3135 라디오 (실버5) 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> // abs()의 해더 -  정수의 절댓값을 알고 싶다면 cstdlib, 실수형의 절댓값을 알고 싶다면 cmath

int a, b, min, n;
int num[5] = {};

int main() {
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	min = abs(a - b);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		num[i] = abs(num[i] - b);
		min > num[i] ? min = num[i]  : NULL;
	}
	printf("%d\n", min == abs(a - b) ? min : min + 1);



	return 0;
}
*/
