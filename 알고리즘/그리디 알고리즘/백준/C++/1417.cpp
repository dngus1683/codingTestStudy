// 국회의원 선거
// 사람의 속을 읽을 줄 아는 다솜이가 국회의원 선거에 나가 본인의 능력으로 다른 후보를 지지하는 사람들을 미리 매수하려 한다.
// 각 후보의 지지자 수가 주어질 때, 다솜이가 매수해야 하는 사람의 최솟값을 구하라.


// 내 답안1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int per[50] = {};
int cnt = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &per[i]);
	}

	sort(per+1, per + n , greater <int>());

	while (per[1] >= per[0]) {
		cnt++;
		per[0] += 1;
		per[1] -= 1;
		sort(per + 1, per + n, greater <int>());
	}

	printf("%d\n", cnt);

	return 0;
}
