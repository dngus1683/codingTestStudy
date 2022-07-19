/* 그리디 알고리즘 16208 귀찮음 (실버5)*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int flag = 0;
int es = 0;
int os = 0;
int multi = 0;
int a[5000], e[5000], o[5000];

void sep(int oo[], int ee[]) {
	int eco[5000] = { 0 };
	int oco[5000] = { 0 };

	os = es = 0;
	for (int i = 0; i < n+1; i++) {
		if (i % 2) oco[i / 2] = oo[i], os += oo[i];
		else eco[i / 2] = oo[i], es += oo[i];
		multi = multi + os * es;
	}
	for (int i = 0; i < n + 1; i++) {
		if (i % 2) oco[i / 2] = oo[i], os += oo[i];
		else eco[i / 2] = oo[i], es += oo[i];
		multi = multi + os * es;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	while (n) {
		if (!flag) sep(a), flag++;
		else sep(e), sep(o);
		n /= 2;
	}


	cout << multi << '\n';
	return 0;
}

