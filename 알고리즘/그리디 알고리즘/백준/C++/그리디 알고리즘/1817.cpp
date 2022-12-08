/* ±×¸®µð ¾Ë°í¸®Áò 1817 Áü Ã¬±â´Â ¼ò (½Ç¹ö5)
#include <iostream>

using namespace std;

int N, M, p = 0, cnt = 0;
int book[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> book[i];
		if ((p + book[i]) > M) {
			cnt++;
			p = book[i];
		}
		else {
			p += book[i];
		}
	}

	cout << (N == 0 ? cnt : ++cnt) << '\n';


	return 0;
}
*/


/*
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ans = 0, left = 0;
  for (int i = 0; i < n; i++) {
	int v;
	scanf("%d", &v);
	if (left < v) {
	  left = m; ans++;
	}
	left -= v;
  }
  printf("%d\n", ans);
  return 0;
}
*/