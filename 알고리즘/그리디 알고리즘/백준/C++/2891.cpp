// 카약과 강풍
// 2890번을 보면 알겠지만, 상근이는 카약 대회를 개최했다. 그런데, 갑자기 엄청난 강풍이 경기장에 불었고, 일부 카약이 부서졌다. 경기는 5분 안에 시작해야 하는 상황이다.
// 다행히 일부 팀은 혹시 모를 사태에 대비해서 카약을 하나 더 경기장에 들고 왔다. 카약은 매우 무겁고 운반하기 어렵다. 따라서, 자신의 바로 다음이나 전에 경기하는 팀에게만 카약을 빌려주려고 한다. 즉, 팀 4는 여분의 카약을 3이나 5에게만 빌려줄 수 있다. 다른 팀에게서 받은 카약은 또 다른 팀에게 빌려줄 수 없다. 또, 카약을 하나 더 가져온 팀의 카약이 손상되었다면, 여분의 카약으로 경기에 출전하게되고, 이 카약은 다른 팀에게 빌려줄 수 없다.
// 카약이 부서진 팀과 하나 더 가


// 내 답안1
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
