/* 그리디 알고리즘 4796 캠핑 (실버5)

#include <iostream>

using namespace std;

int P, L, V, cnt;
int i = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) return 0;
		cnt = L * (V / P) + (L > (V % P) ? V % P : L);
		cout << "Case " << i << ": " << cnt << '\n';
		cnt = 0; i++;
	}

	return 0;
}
*/

/*
V/P를 처리한 후 남은 일 수를 계산할 때, 그 값이 L보다 작은지를 확인해야했다.
*/


