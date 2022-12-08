/* 그리디 알고리즘 16208 귀찮음 (실버5)
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
* sum, ans 은 int의 범위에서 벗어나므로 long long으로 그 크기를 늘린다.
* 해당 문제는 하나의 막대를 연속된 2등분으로 a의 크기로 n개를 만들 때, 등분된 두 막대의 곱의 합들이 가장 작은 경우를 출력하는 것이다.
* 이는, 순서 상관없이 한개 씩 때면 항상 같은 값, 최솟값을 갖는다.
*/