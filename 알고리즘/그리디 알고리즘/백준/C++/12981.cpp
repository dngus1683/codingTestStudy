// 공 포장하기
// 빨간 공 R개, 초록 공 G개, 파란 공 B개를 가지고 있다.
// 오늘은 이 공을 박스로 포장하려고 한다. 박스에는 공이 1개, 2개, 또는 3개 들어갈 수 있다.
// 박스에 들어가는 공의 색은 모두 다르거나, 모두 같아야 한다.
// 필요한 박스 개수의 최솟값을 구하는 프로그램을 작성하시오.


// 내 답안1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int r, g, b, m;
int box = 0;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> g >> b;

	box = box + r / 3 + g / 3 + b / 3;
	r = r % 3; g = g % 3; b = b % 3;

	m = max(max(r, g), b);
	if (r > 0) cnt++;
	if (g > 0) cnt++;
	if (b > 0) cnt++;

	m > cnt ? box += cnt : box += m;


	cout << box << '\n';

	return 0;
}




// 답안 예시1 - https://www.acmicpc.net/source/41894743
// #include<stdio.h>

// int main(){
// 	int a, b, c, m, t;
// 	scanf("%d %d %d", &a, &b, &c);
// 	m=a<b?(a<c?a:c):(b<c?b:c);
// 	t=m; a-=m; b-=m; c-=m;
// 	if((a==0&&b==0)||(b==0&&c==0)||(c==0&&a==0)) printf("%d", t+(a+b+c+2)/3);
// 	else{
// 		if(b==0) b=a;
// 		else if(c==0){ c=b; b=a; }
// 		t+=b/3+c/3;
// 		b-=3*(b/3); c-=3*(c/3);
// 		if(b!=0&&c!=0) t+=b>c?b:c;
// 		else if((b!=0&&c==0)||(b==0&&c!=0)) t+=1;
// 		printf("%d", t);
// 	}
// }
