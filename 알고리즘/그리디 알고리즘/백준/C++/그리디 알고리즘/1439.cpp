/* 그리디 알고리즘 1439 뒤집기 (실버5) 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int zeroCnt = 0;
int oneCnt = 0;
char s[1000001] = {};

int main() {

	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++) {
		while (s[i] == '0') {
			if (s[i + 1] == '0') {
				i++;
			}
			else {
				zeroCnt++;
				break;
			}
		}
		while (s[i] == '1') {
			if (s[i + 1] == '1') {
				i++;
			}
			else {
				oneCnt++;
				break;
			}
		}
	}

	printf("%d\n", zeroCnt > oneCnt ? oneCnt : zeroCnt);
	return 0;
}
*/



/* 이전 값을 저장하면서 그값과 비교하며 계산하는 method
* 
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int d[2];
char b, c;

int main() {
	while (true) {
		scanf("%c", &c);

		if (c != '1' && c != '0')break;
		if (c != b)d[c - '0']++, b = c;
	}
	printf("%d", (d[0] > d[1]) ? d[1] : d[0]);
}
*/
