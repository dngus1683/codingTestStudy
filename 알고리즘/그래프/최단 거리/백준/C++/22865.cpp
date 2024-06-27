// 가장 먼 곳
// N개의 땅 중 하나를 골라 이사를 하려 한다. 이미 그 마을에는 A, B, C 친구가 각자 1곳 씩 잡아 살고 있다. 세 친구들과 가장 먼 곳으로 이사하려 한다. 가장 먼 곳이란, 가장 가까운 친구와의 거리가 가장 먼 것을 의미한다. 이사갈 땅을 구하라.


// 내 답안1
// 다익스트라 - 시간초과
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 100001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int da[MAX_N], db[MAX_N], dc[MAX_N];

void dijkstra(int start, int d[])
{
    fill(d, d+MAX_N, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty())
    {
        int dist = - pq.top().first;
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

    int n, m, a, b, c, idx = 0, ans = 0;

    cin >> n;
    cin >> a >> b >> c;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int x, y, z;

        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    dijkstra(a, da);
    dijkstra(b, db);
    dijkstra(c, dc);

    for(int i=1; i<=n; i++)
    {
        int num = min(da[i], min(db[i], dc[i]));

        if(ans < num)
        {
            ans = num;
            idx = i;
        }
    }
    cout << idx << '\n';

}


// 내 답안2
// 플로이드 워셜 - 전역 변수로 d를 선언하면 Segfault 런타임 에러가 뜬다.(전역 변수로 배열을 선언할 때, 최대 길이는 100,000이다.)
//              때문에 main함수 안에서 동적할당으로 선언해봤지만 메모리 초과가 떴다.
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//#define MAX_N 100001
//#define INF 987654321
//
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n, m, a, b, c, idx = 0, ans = 0;
//
//    cin >> n;
//    cin >> a >> b >> c;
//    cin >> m;
//
//    int **d = new int *[MAX_N];
//    for(int i=0; i<MAX_N; i++)
//    {
//        d[i] = new int [MAX_N];
//    }
//
//    fill(&d[0][0], &d[n][n+1], INF);
//    for(int i=0; i<m; i++)
//    {
//        int x, y, z;
//
//        cin >> x >> y >> z;
//        d[x][y] = d[y][x] = z;
//    }
//    for(int i=1; i<=n; i++)
//    {
//        d[i][i] = 0;
//    }
//
//    for(int k=1; k<=n; k++)
//    {
//        for(int i=1; i<=n; i++)
//        {
//            if(d[i][k] == INF) continue;
//            for(int j=1; j<=n; j++)
//            {
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//            }
//        }
//    }
//
//    for(int i=1; i<=n; i++)
//    {
//        if(i==a || i==b || i==c) continue;
//        int num = min(d[i][a], min(d[i][b], d[i][c]));
//        if(ans < num)
//        {
//            ans = num;
//            idx = i;
//        }
//    }
//    cout << idx << '\n';
//
//    for(int i=0; i<MAX_N; i++)
//    {
//        delete [] d[i];
//    }
//    delete [] d;
//}
