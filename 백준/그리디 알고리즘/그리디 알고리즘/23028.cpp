/* �׸��� �˰��� 23028 5�г��� �ٴϱ� �Ⱦ�� (�ǹ�5)

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
ó������ �̹� output���ǿ� �����Ǵ��� 10���� x,y �Է��� �� �޵��� ®���µ� ����ó�� �ƾ���.
������ ��ó�� �ٷ� ����ϰԲ� �����Ͽ����� ����ó�� �ƴ�.
*/