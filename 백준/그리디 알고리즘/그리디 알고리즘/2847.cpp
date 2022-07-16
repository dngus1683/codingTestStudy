/* 그리디 알고리즘 2847 (실버4)
#include <iostream>

using namespace std;

int N;
int level[100];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}
	for (int i = N - 2; i >= 0; i--) {
		while (level[i + 1] <= level[i]) {
			level[i]--;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
*/