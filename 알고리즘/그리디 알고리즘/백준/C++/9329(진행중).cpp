/* 그리디 알고리즘 9329 패스트 푸드 상금 (실버5)*/

#include <iostream>
#include <algorithm>

using namespace std;

int T, n, m, k, a, b, mfp[11], fp[31], cfp[31][10], pc[11], cnt[31],mul[11], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		a = 1;
		ans = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> k;
			mfp[a] = 100;
			for (int j = 0; j < k; j++) {
				int c;
				cin >> c;
				cfp[c][i] = a;
			}
			cin >> pc[a];
			a++;
		}
		for (int i = 1; i < m+1; i++) {
			cin >> fp[i];
			for (int j = 0; j < n; j++) {
				mfp[cfp[i][j]] = min(mfp[cfp[i][j]], fp[i]);
				if (cfp[i][j] != 0) cnt[i]++;
			}
		}
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n+1; j++) {
				mul[j] = mfp[j] * pc[j];
				if (cnt[i] > 1) {
					b > mfp[j] ? mfp[j] = 0 : b = mfp[j];
				}
			}
		}
		for (int i = 1; i < n+1; i++) {
			ans = ans + mul[i];
		}
		cout << ans << '\n';
		
	}

	return 0;
}
