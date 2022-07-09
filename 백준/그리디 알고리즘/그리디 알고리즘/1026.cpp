/* 그리디 알고리즘 1026 (S = A[0] × B[0] + ... + A[N-1] × B[N-1])
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, S = 0;
	int A[50] = {  };
	int B[50] = {  };

	scanf_s("%d\n", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &B[i]);
	}
	sort(A, A + N);
	sort(B, B + N, greater<int>());

	for (int i = 0; i < N; i++) {
		S = S + A[i] * B[i];
	}

	printf("%d\n", S);
	return 0;
}

*/