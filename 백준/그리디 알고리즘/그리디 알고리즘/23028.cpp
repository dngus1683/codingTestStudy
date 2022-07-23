/* 그리디 알고리즘 23028 5학년은 다니기 싫어요 (실버5)

#include <iostream>

using namespace std;

int N, A, B, x[6], y[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A >> B;
	for (int i = 0; i < 10; i++) {
		int sum = 6;
		cin >> x[i] >> y[i];
		if ((B < 130) || (A < 66)) N++;
		else {
			cout << "Nice" << '\n';
			return 0;
		}
		if (N > 8) {
			cout << "Nae ga wae" << '\n';
			return 0;
		}
		A += x[i] * 3;
		sum -= x[i];
		B += x[i] * 3;
		B += ((y[i] > sum) ? sum : y[i]) * 3;
	}

	return 0;
}
*/

/*
처음에는 이미 output조건에 충족되더라도 10개의 x,y 입력을 다 받도록 짰었는데 오답처리 됐었다.
때문에 위처럼 바로 출력하게끔 변경하였더니 정답처리 됐다.
*/