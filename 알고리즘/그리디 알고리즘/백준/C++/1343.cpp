// 폴리오미노
// 민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다. AAAA와 BB
// 이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다. 이때, '.'는 폴리오미노로 덮으면 안 된다.
// 폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.


// 내 답안1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main() {
	char board[50] = {};
	int cnt = 0;
	int num = 0;
	int flag = 0;

	scanf("%s", board);

	for (int i = 0; i < strlen(board)+1; i++) {
		if (board[i] == 'X') {
			cnt++;
			flag = 0;
		}
		else if ((board[i] == '.' || board[i] == NULL)) {
			if ((cnt % 4 == 2 || cnt % 4 == 0) && flag == 0)
			{
				flag = 1;
				int idx = i - cnt;
				while (cnt / 4) {
					board[idx] = 'A';
					idx++;
					num++;
					if (num == 4) {
						cnt -= 4;
						num = 0;
					}
				}
				while (cnt / 2) {
					board[idx] = 'B';
					idx++;
					num++;
					if (num == 2) {
						cnt -= 2;
						num = 0;
					}
				}
			}
			else if (flag == 1) continue;
			else {
				cnt = -1;
				break;
			}
		}
	}

	cnt == -1 ? printf("%d\n", cnt) : printf("%s\n", board);
	return 0;
}
*/



// 답안 예시1
#include <cstdio>

char arr[510];
int idx;

int main() {
	gets(arr);
	while(arr[idx]) {
		if (arr[idx] == 'X') {
			int j = idx;
			while(arr[j] == 'X') j++;
			int sz = j - idx;
			if (sz & 1) {   // 비트 연산자로 인해, 10,100인 2,4는 결과값이 0이 나오므로 조건에 충족x, 이로 인해 2,4의 배수가 아닌 수는 걸러진다.
				puts("-1");
				return 0;
			}
			int k = (sz / 4)*4;
			while (k--) arr[idx++] = 'A';
			while (idx < j) arr[idx++] = 'B';
		}
		else idx++;     // 조건문이 X를 기준으로 잡고 있는데 해당되는 X는 이미 A나 B로 바뀌었기 때문에 index에 추가적인 작업이 없어도 다음 진행이 가능하다.
	}
	puts(arr);
	return 0;
}
