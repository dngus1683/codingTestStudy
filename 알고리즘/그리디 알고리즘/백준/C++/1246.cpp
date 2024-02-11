// 온라인 판매
// N개의 달걀을 M명에게 하나 씩 팔아야 한다. 구매자들이 각기 다른 구매희망 가격을 제시할 때, 최대의 이득을 보기 위해 달갈 1개 당 얼마에 팔아야 하며 총 수익이 얼마인지 구하라.


// 내 답안1
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


