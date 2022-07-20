/* 그리디 알고리즘 16435 스네이크버드 (실버5)
#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int h[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> h[i];
	sort(h, h + N);
	for (int i = 0; i < N && L >= h[i]; i++) if (L >= h[i]) L++;

	cout << L << '\n';

	return 0;
}
*/
