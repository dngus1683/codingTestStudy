// 고속도로
// 총 예산과 각 도시 간의 통행료와 거리가 주어질 때, 예산 안의 경로 중 가장 짧은 경로의 길이를 구하라.


// 내 답안1
// 데이크스트라로 풀기
// 각 노드에 도착했을 때 남은 비용마다 distance 값을 따로 저장해두어서, 최종적으로 d[목표위치]에 존재하는 여러 값들 중 최솟값을 출력한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define MAXV 101
#define MAXK 10001
#define INF 987654321

using namespace std;

vector<tuple<int, int , int>> graph[MAXV];
int d[MAXV][MAXK];

void dijkstra(int start, int k, int v)
{
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, k, start});

    d[start][k] = 0;

    while(!pq.empty())
    {
        int dist = -get<0>(pq.top());
        int money = get<1>(pq.top());
        int now = get<2>(pq.top());
        pq.pop();

        if(d[now][money] < dist) continue;
        for(int i=0; i<graph[now].size(); i++)
        {
            if(money - get<2>(graph[now][i]) < 0) continue;
            int DistCost = d[now][money] + get<1>(graph[now][i]);
            if(DistCost < d[get<0>(graph[now][i])][money-get<2>(graph[now][i])])
            {
                d[get<0>(graph[now][i])][money-get<2>(graph[now][i])] = DistCost;
                pq.push({-DistCost, money - get<2>(graph[now][i]), get<0>(graph[now][i])});
            }
        }
    }
}

void FindAnswer(int v)
{
    int ans = INF;
    for(int i=0; i<sizeof(d[v])/sizeof(d[v][0]); i++)
    {
        ans = min(ans, d[v][i]);
    }
    if(ans == INF) ans = -1;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, v, e;
    cin >> k;
    cin >> v;
    cin >> e;
    for(int i=0; i<e; i++)
    {
        int start, end, l, t;
        cin >> start >> end >> l >> t;
        graph[start].push_back({end, l, t});
    }
//    for(int i=0; i<MAXV; i++)
//        fill(d[i], d[i]+MAXK, INF);

    fill(&d[0][0], &d[MAXV-1][MAXK], INF);
    dijkstra(1, k, v);

    FindAnswer(v);

}


// 내 답안2
// DFS로 풀기 (시간 초과)
//#include <iostream>
//#include <vector>
//#include <tuple>
//
//#define MAXV 101
//#define INF 987654321
//
//using namespace std;
//
//vector<tuple<int, int, int>> graph[MAXV];
//int k, v, e;
//int ans = INF;
//
//void dfs(int start, int dist, int money)
//{
//    for(int i=0; i<graph[start].size(); i++)
//    {
//        if(get<2>(graph[start][i])+money > k) continue;
//        if(get<0>(graph[start][i]) == v)
//        {
//            ans = min(ans, get<1>(graph[start][i])+dist);
//            continue;
//        }
//        dfs(get<0>(graph[start][i]), get<1>(graph[start][i])+dist, get<2>(graph[start][i])+money);
//    }
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    cin >> k;
//    cin >> v;
//    cin >> e;
//    for(int i=0; i<e; i++)
//    {
//        int start, end, l, t;
//        cin >> start >> end >> l >> t;
//        graph[start].push_back({end, l, t});
//    }
//    dfs(1, 0, 0);
//
//    if(ans == INF) ans = -1;
//    cout << ans << '\n';
//}