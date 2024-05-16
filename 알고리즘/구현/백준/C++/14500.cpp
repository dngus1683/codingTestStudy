// 테트로미노
// 폴리오미노: 1x1 정사각형을 여러 개 이어 붙인 도형. 
// 테트로미노: 4개의 정사각형을 사용해 만든 폴리오미노. like 테트리스 블럭들 5가지
// N x M 의 각 칸에 정수가 주어져 있고, 해당 맵 위 임의의 위치에 테트로미노 하나를 올려놓을 때, 해당 위치의 정수들의 합의 최댓값을 구하라.


// 내 답안1
// bfs 사용
#include <iostream>
#include <queue>

#define MAX_N 501

using namespace std;

int N = 0;
int M = 0;
int graph[MAX_N][MAX_N];
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

typedef struct Point
{
	int PreI = 0;
	int PreJ = 0;
	int NowI = 0;
	int NowJ = 0;
	int cnt = 0;
	int sum = 0;
}Point;

inline int max(int a, int b)
{
	return (a > b ? a : b);
}
inline int min(int a, int b)
{
	return (a < b ? a : b);
}

int bfs(int NowI, int NowJ)
{
	int mx = 0;
	queue<Point> q;
	q.push({ NowI, NowJ, NowI, NowJ, 1, graph[NowI][NowJ]});

	while (!q.empty())
	{
		int PreI = q.front().PreI;
		int PreJ = q.front().PreJ;
		int NowI = q.front().NowI;
		int NowJ = q.front().NowJ;
		int cnt = q.front().cnt;
		int sum = q.front().sum;
		int mn = 987654321;
		int ExpSum = 0;
		int flag = 0;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (NowI + di[i] < 0 || NowI + di[i] >= N || NowJ + dj[i] < 0 || NowJ + dj[i] >= M)
			{
				flag = 1;
				continue;
			}
			if (NowI + di[i] == PreI && NowJ + dj[i] == PreJ)
				continue;

			if (cnt == 2)
			{
				mn = min(mn, graph[NowI + di[i]][NowJ + dj[i]]);
				ExpSum += graph[NowI + di[i]][NowJ + dj[i]];
			}

			if (cnt == 3)
			{
				mx = max(mx, sum + graph[NowI + di[i]][NowJ + dj[i]]);
				continue;
			}
			q.push({ NowI, NowJ, NowI + di[i], NowJ + dj[i], cnt+1, sum + graph[NowI + di[i]][NowJ + dj[i]]});
		}

		if (flag && cnt == 2)
		{
			mx = max(mx, sum + ExpSum);
		}
		else if (!flag && cnt == 2)
		{
			mx = max(mx, sum + ExpSum - mn);
		}
	}

	return mx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans = max(ans, bfs(i, j));
		}
	}

	cout << ans << '\n';

}














// 답안 예시1 - https://www.acmicpc.net/source/62638013
// 구현 - 완전 탐색
// 각 테트로미노를 먼저 정의 + 각 지점 별로 가능한 모든 테트로미노 경우 계산
// => 시작점을 기준으로 한 줄 먼저 그릴 때, 한 줄의 칸 수를 기준으로 나올 수 있는 테트로미노를 모두 확인.
/* 
#include <iostream>
#include <algorithm>

using namespace std;

short n, m, res, map[500][500];

short max(short, short);
short max(short, short, short);

void BT();
short BT14(short, short);
short BT41(short, short);
short BT23(short, short);
short BT32(short, short);
short BT22(short, short);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;

	for(short i = 0; i < n; i++)
		for(short j = 0; j < m; j++)
			cin>>map[i][j];

	BT();

	cout<<res;
}

short max(short a, short b)
{
	return (a > b) ? a : b;
}

short max(short a, short b, short c)
{
	if(a > b)
	{
		if(c > a) return c;
		else return a;
	}
	else
	{
		if(c > b) return c;
		else return b;
	}
}

void BT()
{
	for(short i = 0; i < n; i++)
		for(short j = 0; j < m - 3; j++)
			res = max(res, BT14(i, j));

	for(short i = 0; i < n - 3; i++)
		for(short j = 0; j < m; j++)
			res = max(res, BT41(i, j));

	for(short i = 0; i < n - 1; i++)
		for(short j = 0; j < m - 2; j++)
			res = max(res, BT23(i, j));

	for(short i = 0; i < n - 2; i++)
		for(short j = 0; j < m - 1; j++)
			res = max(res, BT32(i, j));

	for(short i = 0; i < n - 1; i++)
		for(short j = 0; j < m - 1; j++)
			res = max(res, BT22(i, j));
}

short BT14(short i, short j)
{
	return map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
}

short BT41(short i, short j)
{
	return map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
}

short BT23(short i, short j)
{
	short tres = 0;

	tres = max(tres, map[i][j] + map[i][j + 1] + map[i][j + 2] + max(map[i + 1][j], map[i + 1][j + 1], map[i + 1][j + 2]));
	tres = max(tres, map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + max(map[i][j], map[i][j + 1], map[i][j + 2]));
	tres = max(tres, map[i][j + 1] + map[i + 1][j + 1] + max(map[i][j] + map[i + 1][j + 2], map[i + 1][j] + map[i][j + 2]));

	return tres;
}

short BT32(short i, short j)
{
	short tres = 0;

	tres = max(tres, map[i][j] + map[i + 1][j] + map[i + 2][j] + max(map[i][j + 1], map[i + 1][j + 1], map[i + 2][j + 1]));
	tres = max(tres, map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + max(map[i][j], map[i + 1][j], map[i + 2][j]));
	tres = max(tres, map[i + 1][j] + map[i + 1][j + 1] + max(map[i][j] + map[i + 2][j + 1], map[i + 2][j] + map[i][j + 1]));

	return tres;
}

short BT22(short i, short j)
{
	return map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
}
*/




// 답안 예시2 - https://www.acmicpc.net/source/44181220
// 구현 - 완전 탐색
// 답안 예시1처럼 모든 테트로미노를 직접 정의. 대신 답안 예시2는 따로 함수를 사용하지 않고 naive하게 구현.
/*
#include <iostream>
using namespace std;

short arr[504][504];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> arr[i][j];
		}
	}


	int MM=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int M=0;
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i+0][j+3]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+3][j+0]);
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i+1][j+2]);
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i+1][j+0]);
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i-1][j+2]);
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i-1][j+0]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+2][j+1]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+0][j+1]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+2][j-1]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+0][j-1]);
			M = max(M,arr[i+1][j+0]+arr[i+1][j+1]+arr[i+2][j+1]);
			M = max(M,arr[i+1][j+0]+arr[i+1][j-1]+arr[i+2][j-1]);
			M = max(M,arr[i+0][j+1]+arr[i+1][j+1]+arr[i+1][j+2]);
			M = max(M,arr[i+0][j+1]+arr[i-1][j+1]+arr[i-1][j+2]);
			M = max(M,arr[i+0][j+1]+arr[i+1][j+0]+arr[i+1][j+1]);
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i+1][j+1]);
			M = max(M,arr[i+0][j+1]+arr[i+0][j+2]+arr[i-1][j+1]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+1][j+1]);
			M = max(M,arr[i+1][j+0]+arr[i+2][j+0]+arr[i+1][j-1]);
			MM = max(MM,M+arr[i][j]);
		}
	}

	cout << MM << '\n';

	return 0;
}

*/