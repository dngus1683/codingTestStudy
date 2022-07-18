/* 그리디 알고리즘 92367 이장님 초대 (실버5)
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int t[100000];
int mx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	sort(t, t + N, greater<int>());

	for (int i = 0; i < N; i++) {
		mx = max(mx, t[i] + i);
	}

	cout << mx + 2  << '\n';


	return 0;
}
*/

