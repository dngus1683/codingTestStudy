/* �׸��� �˰��� 3135 ���� (�ǹ�5) 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> // abs()�� �ش� -  ������ ������ �˰� �ʹٸ� cstdlib, �Ǽ����� ������ �˰� �ʹٸ� cmath

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
