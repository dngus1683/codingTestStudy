/* 그리디 알고리즘 1049 달걀판매
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, mnp, mxs = 0;
	int p[1000] = {};

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &p[i]);
	}

	sort(p, p + m,greater<int>());

	for (int i = 0; i < m; i++) {
		int cnt = n <= (i + 1) ? n : (i + 1);
		if (p[i] * cnt > mxs) {
			mxs = p[i] * (i + 1);
			mnp = p[i];
		}
	}
	printf("%d %d\n", mnp, mxs);
}
*/

