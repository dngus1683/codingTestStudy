/* 그리디 알고리즘 9329 패스트 푸드 상금 (실버5)*/

#include <iostream>

using namespace std;

int T, n, m, k, fp[30] = { 0 },pc;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				int c, mc = 30;
				cin >> c;

				fp[c]++;
			}
			cin >> pc;
		}
		for (int i = 0; i < m; i++) {
			int c;
			cin >> c;
			fp[c]--;
		}
	}

	return 0;
}