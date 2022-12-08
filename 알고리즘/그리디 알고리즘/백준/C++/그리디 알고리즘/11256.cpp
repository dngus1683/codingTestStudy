/* 그리디 알고리즘 11256 사탕 (실버5)

#include <iostream>
#include <algorithm>

using namespace std;

int T, J, N, RC[1000], cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> J >> N;
		for (int i = 0; i < N; i++) {
			int R, C;
			cin >> R >> C;
			RC[i] = R * C;
		}
		sort(RC, RC + N, greater<int>());
		for (int i = 0; i < N && J > 0; i++) {
			J -= RC[i];
			cnt++;
		}
		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}
*/
