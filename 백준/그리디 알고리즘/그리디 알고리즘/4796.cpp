/* �׸��� �˰��� 4796 ķ�� (�ǹ�5)

#include <iostream>

using namespace std;

int P, L, V, cnt;
int i = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) return 0;
		cnt = L * (V / P) + (L > (V % P) ? V % P : L);
		cout << "Case " << i << ": " << cnt << '\n';
		cnt = 0; i++;
	}

	return 0;
}
*/

/*
V/P�� ó���� �� ���� �� ���� ����� ��, �� ���� L���� �������� Ȯ���ؾ��ߴ�.
*/


