/* �׸��� �˰��� 17262 �Ҵ��� �����귯 (�ǹ�5)
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
		y = min(y, b);	//������ index 1�϶� �ִ� �ּڰ��� �ʱ�ȭ �ϰ� �� �������� �񱳸� ���������� �ش� �ڵ忡���� �ּڰ��� ���� ���� �־��� maximum���� Ȱ���ϰ� �ִ��� ���� ���� ����Ʈ�� 0�� Ȱ���Ѵ�.
	}

	cout << max(0, x-y) << '\n'; // ������ ���� �����ڸ� Ȱ���Ͽ� ����� ���������� �ش� �ڵ忡���� ���� �� ũ�⸸ ���Ѵ�.
}
*/