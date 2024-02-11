// 게임을 만든 동준이
// N개의 레벨을 깨서, 각 레벨 별 점수를 합산하는 게임이 있다. 이 게임은 레벨이 올라갈수록 점수가 높아져야 하는데 실수로 낮은 레벨 대에 점수를 높혀놨다.
// 계단식 점수로 수정하기 위해 기존 점수를 낮춰야 하는 최솟값을 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int N;
int level[100];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}
	for (int i = N - 2; i >= 0; i--) {
		while (level[i + 1] <= level[i]) {
			level[i]--;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
