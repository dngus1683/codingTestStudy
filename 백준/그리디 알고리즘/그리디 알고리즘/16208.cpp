/* �׸��� �˰��� 16208 ������ (�ǹ�5)
#include <iostream>

using namespace std;

int n;
long long sum = 0;
long long ans = 0;
int a[500000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		sum -= a[i];
		ans += a[i] * sum;
	}


	cout << ans << '\n';
	return 0;
}
*/


/*
* sum, ans �� int�� �������� ����Ƿ� long long���� �� ũ�⸦ �ø���.
* �ش� ������ �ϳ��� ���븦 ���ӵ� 2������� a�� ũ��� n���� ���� ��, ��е� �� ������ ���� �յ��� ���� ���� ��츦 ����ϴ� ���̴�.
* �̴�, ���� ������� �Ѱ� �� ���� �׻� ���� ��, �ּڰ��� ���´�.
*/