// 짐 챙기는 숌
// 숌은 짐을 챙겨서 겨울캠프에서 집으로 가려고 한다. 근데 숌은 공부를 많이 하러 캠프에 온 것이기 때문에 책을 엄청나게 많이 가지고 왔다. 숌은 이 책을 방에 탑처럼 쌓아 놨다.
// 숌은 책을 박스에 차곡차곡 넣어서 택배로 미리 보내려고 한다. 책은 탑처럼 차곡차곡 쌓여있기 때문에, 차례대로 박스에 넣을 수밖에 없다.
// 각각의 책은 무게가 있다. 그리고 박스는 최대 넣을수 있는 무게가 있다. 숌이 필요한 박스의 개수의 최솟값을 구하는 프로그램을 작성하시오.


// 내 답안1
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



// 답안 예시1
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//  int n, m;
//  scanf("%d%d", &n, &m);
//  int ans = 0, left = 0;
//  for (int i = 0; i < n; i++) {
//	int v;
//	scanf("%d", &v);
//	if (left < v) {
//	  left = m; ans++;
//	}
//	left -= v;
//  }
//  printf("%d\n", ans);
//  return 0;
//}
