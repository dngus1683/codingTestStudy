// 퇴사2
// 퇴사하기 전 최대한 많이 뽑아 먹으려 한다.
// 각 날 별로 상담 업무 시 걸리는 날짜와 수당이 주어진다.
// 가능한 한 최대한 많은 수입을 내려할 때, 총 수당을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> T(N + 1), P(N + 1), dp(N + 2, 0);

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; i--) {
        if (i + T[i] <= N + 1) {
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        }
        else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << "\n";
    return 0;
}
