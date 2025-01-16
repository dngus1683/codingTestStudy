// 기념품
// 1~N번의 사람이 원으로 둘러앉아 있다. 여러 단계로 게임을 시작하는데, t단계에서는 t^3번까지 시계방향으로 돌며, 마지막 t^3번째 사람은 게임에서 제외된다.
// 이를 반복했을 때, 몇 번의 사람이 최후의 승자가 되는지 구하라.


// 내 답안1
#include <iostream>
#include <queue>

#define MAX_N 5001
#define ull unsigned long long
using namespace std;

int answer = 0;
int N = 0;
ull t = 1;
queue<int> q1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		q1.push(i);
	}

	while (!q1.empty())
	{
		ull t3 = t * t * t;
		t3 = (t3 % N == 0 ? N : t3 % N);

		for (int i = 0; i < t3-1; i++)
		{
			q1.push(q1.front());
			q1.pop();
		}
		answer = q1.front();
		q1.pop();
		N--;
		t++;
	}
	cout << answer << '\n';
}

