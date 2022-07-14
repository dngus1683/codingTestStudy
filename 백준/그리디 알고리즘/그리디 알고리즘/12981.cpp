/* 그리디 알고리즘 12981 공 포장하기 (실버5)
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
*/
/*
#include <stdio.h>

int main() {
	int a,b,c, ans;

	scanf("%d%d%d",&a,&b,&c);
	if((a+b+c)%3==0) {
		if(a%3!=b%3 && a%3!=c%3 && b%3!=c%3) ans = (a+b+c)/3+1;
		else ans = (a+b+c)/3;
	} 
	else ans = (a+b+c)/3+1;

	printf("%d", ans);
	return 0;
}
*/
