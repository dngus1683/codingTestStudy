// 게임
// 501 x 501의 맵에는 지나갈 수 없는 곳, 지나가면 생명력을 1 잃는 곳, 마음껏 지나갈 수 있는 곳으로 이루어져 있다.
// (0,0)에서 출발해서 (500, 500)까지 가는데 생명을 가장 덜 소모하는 경우를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 51
#define MAX_M 51
#define DANGER 1
#define DEATH -1


using namespace std;

vector<pair<int, int>> graph[501*501];
int map[501][501] = {0};
int d[501*501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    d[start] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = d[now] + graph[now][i].second;
            if(d[graph[now][i].first] > cost)
            {
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        for(int x=min(x1, x2); x<=max(x1,x2); x++)
            for(int y=min(y1, y2); y<=max(y1,y2); y++)
                map[x][y] = DANGER;
    }
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        for(int x=min(x1, x2); x<=max(x1,x2); x++)
            for(int y=min(y1, y2); y<=max(y1,y2); y++)
                map[x][y] = DEATH;
    }

    for(int i=0; i<501; i++)
    {
        for(int j=0; j<501; j++)
        {
            int idx = i*501+j;
            for(int k=0; k<4; k++)
            {
                if(i+dy[k]<0 || i+dy[k]>500 || j+dx[k]<0 || j+dx[k]>500 ) continue;
                if(map[i+dy[k]][j+dx[k]] == DEATH) continue;
                int nextIdx = (i+dy[k])*501+(j+dx[k]);
                graph[idx].push_back({nextIdx, map[i+dy[k]][j+dx[k]]});
            }
        }
    }

    fill(d, d+501*501, INF);
    dijkstra(0);

    cout << (d[500*501+500] == INF ? -1 : d[500*501+500]) << '\n';
}
