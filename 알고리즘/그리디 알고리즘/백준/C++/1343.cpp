// 폴리오미노
// 민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다. AAAA와 BB
// 이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다. 이때, '.'는 폴리오미노로 덮으면 안 된다.
// 폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.


// 내 답안1
/*
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



// 답안 예시1 - https://www.acmicpc.net/source/56214089
#include <stdio.h>
char x[99],y[99],c,i,j;
void f(){
	for(j=0;j<c/4;j++) y[i-c+j*4]=y[i-c+j*4+1]=y[i-c+j*4+2]=y[i-c+j*4+3]=65;
	if(c%4) y[i-2]=y[i-1]=66;
	if(x[i]) y[i]='.';
}
int main(){
	scanf("%s",x);
	for(;x[i];i++) if(x[i]>65) c++; else if(c%2) return 0*printf("-1"); else f(),c=0;
	if(c%2) printf("-1");
	else f(),printf("%s",y);
}