/* 그리디 알고리즘 2891 카약과 강풍 (실버5)

#include <iostream>

using namespace std;

int N, S, R, input, cnt =0;
int team[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S >> R;

	for (int i = 0; i < S; i++) {
		cin >> input;
		team[input]--;
	}
	for (int i = 0; i < R; i++) {
		cin >> input;
		team[input]++;
	}
	for (int i = 1; i < N+1; i++) {
		if (team[i] == -1) {
			if (team[i - 1] == 1) {
				team[i - 1]--;
				team[i]++;
			}
			else if (team[i + 1] == 1) {
				team[i + 1]--;
				team[i]++;
			}
		}
	}
	for (int i = 1; i < N+1; i++) {
		if (team[i] == -1) cnt++;
	}

	cout << cnt << '\n';


	return 0;
}
*/
