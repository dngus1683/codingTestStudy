#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	char name[50];
	int asc[26] = {0};
	int oddCnt = 0;
	int oddIndex = 0;

	scanf("%s", name);

	for (int i = 0; i < strlen(name); i++) {
		asc[int(name[i]) - 65] ++;
	}
	for (int i = 0; i < 26; i++) {
		if (asc[i] % 2 == 1) {
			oddCnt++;
			oddIndex = i;
			asc[i] = (asc[i] - 1)/2;
		}
		else {
			asc[i] = asc[i] / 2;
		}
	}
	if (oddCnt >= 2 || strlen(name) % 2 == 0) {
		printf("I'm Sorry Hansoo\n");
	}
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < asc[i]; j++)
				printf("%c", i + 65);
		}
		if (oddCnt == 1) {
			printf("%c", oddIndex + 65);
		}
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < asc[i]; j++)
				printf("%c", i + 65);
		}
		printf("\n");

	}
	

	return 0;
}