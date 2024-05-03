// 알고스팟
// NxM크기의 미로가 있다. (1,1)부터 출발하여 (N,M)까지 가는데 최소 몇개의 벽을 부셔야 하는지 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

char map[101][101];
vector<pair<int, int>> graph[10001];
int d[10001];
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
            if(cost < d[graph[now][i].first])
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

    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        cin >> map[i];
    }

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<4; k++)
            {
                if(i+dy[k]>=0 && i+dy[k]<M && j+dx[k]>=0 && j+dx[k]<N)
                {
                    graph[i*N+j].push_back({(i+dy[k])*N + j+dx[k], map[i+dy[k]][j+dx[k]] - '0'});
                }
            }
        }
    }

    fill(d, d+10001, INF);
    dijkstra(0);

    cout << d[N*M-1] << '\n';
}











// 답안 예시1 - https://www.acmicpc.net/source/11387049
//#include <cstdio>
//#include <queue>
//#define X first
//#define Y second
//using namespace std;
//
//const int dx[] = { -1, 0, 0, 1 };
//const int dy[] = { 0, -1, 1, 0 };
//
//int main() {
//    int n, m;
//    scanf("%d %d", &m, &n);
//
//    char bo[100][101];
//    for (int i = 0; i < n; ++i) scanf("%s", bo[i]);
//
//    priority_queue<pair<int, pair<int, int>>> pq;
//    pq.push({ 0, {0, 0} });
//
//    while (!pq.empty()) {
//        int cnt = pq.top().X;
//        int x = pq.top().Y.X;
//        int y = pq.top().Y.Y;
//        pq.pop();
//
//        if (x == n - 1 && y == m - 1)
//            return !printf("%d", -cnt);
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            if (nx < 0 || nx >= n || ny < 0 || ny >= m || bo[nx][ny] == '@') continue;
//
//            pq.push({ cnt - (bo[nx][ny] == '1'), { nx, ny} });
//            bo[nx][ny] = '@';
//        }
//    }
//
//    return 0;
//}
