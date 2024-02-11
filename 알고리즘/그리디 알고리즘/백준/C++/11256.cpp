// 사탕
// 당신은 사탕 공장의 주인이다. 날마다, 당신은 J개의 사탕을 가게에 보내기 위해 상자에 포장해야 한다.
// 당신은 크기가 다른 상자 N개를 가지고 있다. 당신은 편리를 위해 상자를 최소한으로 쓰려고 한다. (박스를 다 채울 필요는 없다. 일부분만 채워도 된다.)
// 당신이 공장에서 나오는 사탕의 개수와 각 상자의 크기를 입력받고, 상자를 최소한으로 쓸 때의 사용되는 상자 개수를 출력하는 프로그램을 작성하라. 사탕들을 포장할 공간은 충분하다는 것이 보장된다.


// 내 답안1
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
