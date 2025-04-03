// 피아노
// 200'000개의 흰 건반이 있는 피아노를 친다. K만큼의 건반을 손을 움직이지 않고 칠 수 있다. 악보(눌러야 하는 흰 건반)이 주어질 때, 손을 움직이는 최소 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 200'001
#define MAX_K 1'001
#define INF 987654321

using namespace std;

int N = 0;
int K = 0;
int mn = INF;
int mx = 0;
int now = 0;
int answer = 0;
vector<int> notes(MAX_N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> notes[i];
	}
	while (now != N)
	{
		mn = min(mn, notes[now]);
		mx = max(mx, notes[now]);

		if (mx - mn >= K)
		{
			answer++;
			mn = mx = notes[now];
		}

		now++;
	}

	cout << answer << '\n';
}