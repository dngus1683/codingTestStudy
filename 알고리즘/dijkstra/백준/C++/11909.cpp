// 배열 탈출
// (1,1)에서 (n, n)으로 가야 한다. 벽에 부딪히면 벽을 따라서만 이동이 가능하며 그 외의 위치에서는 아래, 오른쪽으로만 이동이 가능하다.
// 각 위치에는 숫자가 있는데 넘어가려는 곳의 수가 더 크거나 같으면 넘어가지 못하기 때문에 1원을 소모하여 현재 위치의 수를 키워 가야 한다.
// 목적지까지 가는데 드는 최소 비용을 구하라.



// 내 답안1
// 메모리 초과: 256 MB 제한
// 각 노드와 정점, 가중치를 저장하는 graph vector와, 각 위치 정보를 저장하는 map 배열로 인해 많은 메모리를 잡고 있다.
// 이 둘을 모두 사용하지 않고도 같은 알고리즘을 구현할 수 있다.
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//#define INF 987654321
//#define MAX_N 2223
//
//using namespace std;
//
//vector<pair<int, int>> graph[MAX_N*MAX_N];
//int map[MAX_N][MAX_N];
//int d[MAX_N*MAX_N];
//int dx[2] = {1,0};
//int dy[2] = {0,1};
//
//void dijkstra(int start)
//{
//    priority_queue<pair<int, int>> pq;
//    pq.push({0, start});
//    d[start] = 0;
//
//    while(!pq.empty())
//    {
//        int dist = -pq.top().first;
//        int now = pq.top().second;
//        pq.pop();
//
//        if(d[now] < dist) continue;
//        for(int i=0; i<graph[now].size(); i++)
//        {
//            int cost = d[now] + graph[now][i].second;
//            if(d[graph[now][i].first] > cost)
//            {
//                d[graph[now][i].first] = cost;
//                pq.push({-cost, graph[now][i].first});
//            }
//        }
//    }
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n;
//
//    cin >> n;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=n; j++)
//        {
//            cin >> map[i][j];
//        }
//    }
//
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=n; j++)
//        {
//            int idx = (i-1)*n+(j-1);
//            for(int k=0; k<2; k++)
//            {
//                if(i+dy[k]<1 || i+dy[k]>n || j+dx[k]<1 || j+dx[k]>n) continue;
//                int nextIdx = (i+dy[k]-1)*n+(j+dx[k]-1);
//                int weight = (map[i][j] > map[i+dy[k]][j+dx[k]] ? 0 : map[i+dy[k]][j+dx[k]] - map[i][j] + 1);
//                graph[idx].push_back({nextIdx, weight});
//            }
//        }
//    }
//
//    fill(d, d+MAX_N, INF);
//    dijkstra(0);
//
//    cout << d[(n-1)*n+n-1] << '\n';
//}



// 내 답안2
// graph vector를 사용하지 않고 바로 알고리즘을 구현하였다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 2223

using namespace std;

typedef struct Point
{
    int x;
    int y;
    int dist;
}Point;

bool operator < (Point a, Point b)
{
    return a.dist > b.dist;
}

int map[MAX_N][MAX_N];
int d[MAX_N*MAX_N];
int dx[2] = {1,0};
int dy[2] = {0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
        }
    }

    fill(d, d+MAX_N*MAX_N, INF);

    priority_queue<Point> pq;
    pq.push({1, 1, 0});
    d[0] = 0;

    while(!pq.empty())
    {
        int dist = pq.top().dist;
        int x = pq.top().x;
        int y = pq.top().y;
        int NowIdx = (y-1)*n+(x-1);
        pq.pop();

        if(d[NowIdx] < dist) continue;
        for(int i=0; i<2; i++)
        {
            if(y+dy[i]<1 || y+dy[i]>n || x+dx[i]<1 || x+dx[i]>n) continue;
            int weight = (map[y][x] > map[y+dy[i]][x+dx[i]] ? 0 : map[y+dy[i]][x+dx[i]] - map[y][x] + 1);
            int cost = d[NowIdx] + weight;
            int NextIdx = (y+dy[i]-1)*n+(x+dx[i]-1);
            if(d[NextIdx] > cost)
            {
                d[NextIdx] = cost;
                pq.push({x+dx[i], y+dy[i], cost});
            }
        }
    }

    cout << d[(n-1)*n+n-1] << '\n';


}
