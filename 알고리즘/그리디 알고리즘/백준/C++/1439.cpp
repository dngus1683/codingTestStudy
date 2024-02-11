// 뒤집기
// 0과 1로 이루어진 배열이 주어질 때, 연속된 1 또는 0을 한 번에 뒤집어 모두 같은 수로 바꾸려 한다.
// 모든 수가 0 또는 1로 이루어지도록 뒤집어야 하는 최소 행동 수를 구하라.


// 내 답안1
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





// 답안 예시1
// 이전 값을 저장하면서 그값과 비교하며 계산하는 method

//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//
//int d[2];
//char b, c;
//
//int main() {
//	while (true) {
//		scanf("%c", &c);
//
//		if (c != '1' && c != '0')break;
//		if (c != b)d[c - '0']++, b = c;
//	}
//	printf("%d", (d[0] > d[1]) ? d[1] : d[0]);
//}

