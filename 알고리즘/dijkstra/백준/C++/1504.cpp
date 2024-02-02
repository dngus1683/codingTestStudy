// 특정한 최단 경로
// 1번에서 N번 정점으로 이동하는 최단 거리를 구하는데, 임의로 주어지는 두 정점을 무조건 거쳐야 한다.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 801
#define MAX_E 200001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];
int dv1[MAX_N];
int dv2[MAX_N];

void dijkstra(int start, int dp[])
{
    fill(dp, dp+MAX_N, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    dp[start] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dp[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = dp[now] + graph[now][i].second;
            if(cost < dp[graph[now][i].first])
            {
                dp[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, E, v1, v2;
    cin >> N >> E;

    for(int i=0; i<E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    dijkstra(1, d);
    dijkstra(v1, dv1);
    dijkstra(v2, dv2);

    if(d[v1] + dv1[v2] + dv2[N] > d[v2] + dv2[v1] + dv1[N])
    {
        if(d[v2] == INF || dv2[v1] == INF || dv1[N] == INF) cout << -1 << '\n';
        else cout << d[v2] + dv2[v1] + dv1[N] << '\n';
    }
    else
    {
        if(d[v1] == INF || dv1[v2] == INF || dv2[N] == INF) cout << -1 << '\n';
        else cout << d[v1] + dv1[v2] + dv2[N] << '\n';
    }
}