/* 그리디 알고리즘 15720 카우버거 (실버5)

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
*/