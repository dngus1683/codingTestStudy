// 숨바꼭질 3
// N에서 K로 가는데 걸리는 최단 시간을 구하라.
// 이동은 총 두가지 방법이 있는데 1)1초 동안 X-1, X+1 로 이동. 2) 0초 동안 2*X로 이동


// 내 답안1
// 데이크스트라로 풀기
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//#define MAXN 100001
//#define INF 987654321
//
//using namespace std;
//
//vector<pair<int, int>> graph[MAXN];
//int d[MAXN];
//
//void dijkstra(int start)
//{
//    priority_queue<pair<int, int>> pq;
//    pq.push({0, start});
//
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
//            if(cost < d[graph[now][i].first])
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
//    int n, k;
//    cin >> n >> k;
//
//    if(n<=k)
//    {
//        for(int i=0; i<MAXN; i++)
//        {
//            if(i-1 >= 0) graph[i].push_back({i-1,1});
//            if(i+1 < MAXN) graph[i].push_back({i+1,1});
//            if(i*2 < MAXN) graph[i].push_back({i*2,0});
//        }
//
//        fill(d, d+MAXN, INF);
//
//        dijkstra(n);
//    }
//    else d[k] = n-k;
//
//    cout << d[k] << '\n';
//}


// 내 답안2
// 단순 점화식으로 풀기
// d[n] = min(d[n-1], d[n+1], d[n*2])
#include <iostream>

#define MAXN 100001
#define INF 987654321

using namespace std;

int d[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(d, d+MAXN, INF);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<=n; i++)
    {
        d[i] = n-i;
        if(i*2 < MAXN) d[i*2] = d[i];
    }
    for(int i=n+1; i<MAXN; i++)
    {
        if(i%2 == 0) d[i] = min(d[i], d[i/2]);
        if(i-1 >= 0) d[i] = min(d[i], d[i-1]+1);
        if(i+1 < MAXN) d[i] = min(d[i], d[i+1]+1);
        if(i*2 < MAXN) d[i*2] = d[i];
    }

    cout << d[k] << '\n';
}