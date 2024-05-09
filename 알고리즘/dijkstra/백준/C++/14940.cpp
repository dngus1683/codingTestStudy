// 쉬운 최단거리
// 지도가 주어지고, 가로와 세로로만 움직일 수 있다고 할 때, 각 지점까지 가는 최단 거리를 모두 구하라.


// 내 답안1
#include <iostream>
#include <queue>

#define MAX_N 1001
#define INF 987654321

using namespace std;

typedef struct Point
{
    int x;
    int y;
    int dist;

    bool operator < (const Point& p) const
    {
        return dist > p.dist;
    }
}Point;

int graph[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

void dijkstra(int x, int y)
{
    priority_queue<Point> pq;
    pq.push({x, y, 0});

    d[y][x] = 0;

    while(!pq.empty())
    {
        int NowX = pq.top().x;
        int NowY = pq.top().y;
        int dist = pq.top().dist;
        pq.pop();

        if(d[NowY][NowX] < dist) continue;
        for(int i=0; i<4; i++)
        {
            if(NowX+dx[i] < 0 || NowX+dx[i] >= m || NowY+dy[i] < 0 || NowY+dy[i] >= n) continue;

            int cost = d[NowY][NowX] + 1;

            if(d[NowY+dy[i]][NowX+dx[i]] > cost)
            {
                if(graph[NowY+dy[i]][NowX+dx[i]])
                {
                    d[NowY+dy[i]][NowX+dx[i]] = cost;
                    pq.push({NowX+dx[i], NowY+dy[i], cost});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int StartX, StartY;

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 2)
            {
                StartX = j;
                StartY = i;
            }
        }
    }

    fill(&d[0][0], &d[MAX_N-1][MAX_N], INF);

    dijkstra(StartX, StartY);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(d[i][j] == INF) d[i][j] = -1;
            if(graph[i][j] == 0) d[i][j] = 0;
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }


}
