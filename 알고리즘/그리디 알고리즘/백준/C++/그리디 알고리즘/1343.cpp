/* �׸��� �˰��� 11343 �������̳� (�ǹ�5)
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



/*
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
			if (sz & 1) {		// ��Ʈ �����ڷ� ����, 10,100�� 2,4�� ������� 0�� �����Ƿ� ���ǿ� ����x, �̷� ���� 2,4�� ����� �ƴ� ���� �ɷ�����.
				puts("-1");
				return 0;
			}
			int k = (sz / 4)*4;
			while (k--) arr[idx++] = 'A';
			while (idx < j) arr[idx++] = 'B';
		}
		else idx++;				// ���ǹ��� X�� �������� ��� �ִµ� �ش�Ǵ� X�� �̹� A�� B�� �ٲ���� ������ index�� �߰����� �۾��� ��� ���� ������ �����ϴ�.
	}
	puts(arr);
	return 0;
}
*/