// 로봇 청소기
// N x M 크기의 방이, 벽과 청소되지 않은 지역으로 주어진다. 로봇 청소기는 바라보는 방향을 가지는데, 로봇 주변에 청소하지 않은 곳이 있다면, 해당 위치를 바라볼 때까지 반시계 방향으로 회전 후, 그 위치로 전진하고,
// 만약 주변에 청소하지 않은 곳이 없다면, 방향을 유지한 채로 후진하며, 만약 후진하려는 장소가 벽이라면 그 즉시 작동을 멈춘다.
// 이때, 로봇이 청소하는 영역의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 51

using namespace std;

int N = 0;
int M = 0;
int r = 0;
int c = 0;
int d = 0;
int answer = 0;
int room[MAX_N][MAX_N];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> room[i][j];
		}
	}

	int count = 4;
	while (true)
	{
		if (room[r][c] == 0)
		{
			room[r][c] = 2;
			answer++;
			continue;
		}
		else if(room[r][c] == 1)
		{
			break;
		}

		if (count == 0)
		{
			count = 4;
			
			r = r + di[(d + 2) % 4];
			c = c + dj[(d + 2) % 4];
			continue;
		}

		d = (d - 1 < 0 ? 3 : d - 1);
		int nextR = r + di[d];
		int nextC = c + dj[d];

		if (room[nextR][nextC] == 0)
		{
			r = nextR;
			c = nextC;
			count = 4;
		}
		else
		{
			count--;
		}
	}

	cout << answer << '\n';
}