/* 그리디 알고리즘 17262 팬덤이 넘쳐흘러 (실버5)
#include <iostream>

using namespace std;

int N,s[100000],e[100000],maxS=0,minE=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s[i] >> e[i];
		i == 0 ? maxS = s[i], minE = e[i] : maxS = max(maxS, s[i]), minE = min(minE, e[i]);
	}

	cout << ((maxS > minE ) ? maxS - minE : 0) << '\n';



	return 0;
}
*/



/*
#include <bits/stdc++.h>
using namespace std;

int N, x, y = 1000000;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;
		x = max(x, a);
		y = min(y, b);	//본인은 index 1일때 최댓값 최솟값을 초기화 하고 그 다음부터 비교를 시작했지만 해당 코드에서는 최솟값을 비교할 때는 주어진 maximum값을 활용하고 최댓값을 구할 때는 디폴트인 0을 활용한다.
	}

	cout << max(0, x-y) << '\n'; // 본인은 삼항 연산자를 활용하여 답안을 구분했지만 해당 코드에서는 단지 두 크기만 비교한다.
}
*/