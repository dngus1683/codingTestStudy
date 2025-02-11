// 점프 게임
// N개의 칸으로 이루어져 있는 두 개의 줄이 있다. 각 줄은 위험한 칸, 위험하지 않은 칸이 섞여 놓여있다. 
// 상근이는 왼쪽 1번 칸에서 시작하며, 1. 앞으로 한 칸, 2. 뒤로 한 칸, 3. 옆 줄로 K칸 앞으로 이동가능하다.
// 상근이가 한 번 이동할 때마다 두 줄의 제일 첫 칸이 사라진다.
// N번 칸보다 더 큰 칸으로 이동하는 경우에 게임을 클리어한 것으로 간주할 때, 게임을 클리어 할 수 있는지 여부를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 200'002

using namespace std;

int N = 0;
int K = 0;
int dx[3] = { 1, -1, 0 };
bool path[2][MAX_N];
int visited[2][MAX_N];

bool dfs(bool dir, int now, int cnt)
{
	visited[(int)dir][now] = cnt;

	for (int i = 0; i < 3; i++)
	{
		int next = now + dx[i];

		if (i == 2)
		{
			dir = !dir;
		}

		if (next > N && next > cnt)
		{
			return true;
		}
		if ((visited[(int)dir][next] == 0 || visited[(int)dir][next] > cnt) && path[(int)dir][next] == 1 && next > cnt)
		{
			if (dfs(dir, next, cnt + 1))
			{

				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	dx[2] = K;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char tile = ' ';

			cin >> tile;
			path[i][j] = tile - '0';
		}
	}
	cout << dfs(0, 1, 1) << '\n';


}



// 답안 예시1 - https://www.acmicpc.net/source/7896866
/*
#include <bitset>
#include <queue>
using namespace std;
using T = struct T { int t, p; bool m; };

int main()
{
	int n, k;
	queue<T> q;
	scanf("%d %d\n", &n, &k);

	char a[2][n--];
	scanf("%s\n%s", a[0], a[1]);

	q.push({0, 0, 0});
	while(!q.empty())
	{
		auto [t, p, m] = q.front(); q.pop();

		if(p > n)
			return!puts("1");

#define append(t, p, m) \
	if(p >= t && (p > n || a[m][p] == '1')) \
		q.push({t, p, m}), a[m][min(p, n)] = 0;

		append(t + 1, p + 1, m);
		append(t + 1, p - 1, m);
		append(t + 1, p + k, !m);
	}

	puts("0");
}
*/