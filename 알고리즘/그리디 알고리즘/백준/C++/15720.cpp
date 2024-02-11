// 카우버거
//윤진이는 이번에 카우버거 알바생으로 뽑히게 되었다. 그녀는 카우버거를 평소에 이용하면서 들었던 의문점 한가지가 있었다.
// "카우버거에는 왜 세트 메뉴에 대한 할인이 존재하지 않는가?"
// 따라서 윤진이의 아이디어로 카우버거에 세트 할인을 도입하고자 한다. 세트 메뉴는 버거 1개, 사이드 메뉴 1개, 음료 1개를 선택 할 경우 각각의 제품에 대해서 10%의 세트 할인을 적용하는 방식으로 진행된다.
// 하지만 카우버거 점주는 POS기의 소프트웨어가 오래되어 세트 할인에 대한 내용을 추가할 수가 없었다. 따라서 소프트웨어학부에 재학 중인 윤진이는 전공을 살려 직접 프로그램을 만들어보려고 한다. 윤진이를 도와 POS기에 들어갈 세트 할인에 대한 프로그램을 작성해보자.


// 내 답안1
#include <iostream>
#include <algorithm>

using namespace std;

int B, C, D, mn;
int Bp[1000], Cp[1000], Dp[1000];
int preP = 0;
int P = 0;

void priceInput(int n, int nP[]) {
	for (int i = 0; i < n; i++) {
		cin >> nP[i];
		preP += nP[i];
	}
	sort(nP, nP + n, greater<int>());
}

void restP(int n, int nP[]) {
	for (int i = mn; i < n; i++) {
		P += nP[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> B >> C >> D;
	mn = min(min(B, C), D);

	priceInput(B, Bp);
	priceInput(C, Cp);
	priceInput(D, Dp);

	for (int i = 0; i < mn; i++) {
		Bp[i] = Bp[i] * 0.9;
		Cp[i] = Cp[i] * 0.9;
		Dp[i] = Dp[i] * 0.9;
		P = P + Bp[i] + Cp[i] + Dp[i];
	}
	restP(B, Bp);
	restP(C, Cp);
	restP(D, Dp);


	cout << preP << '\n' << P << '\n';

	return 0;
}