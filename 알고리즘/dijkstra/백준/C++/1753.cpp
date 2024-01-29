// 최단경로
// 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[20001];
int d[20001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0,start});

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

    int V, E, K;

    cin >> V >> E;
    cin >> K;
    for(int i=0; i<E; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    fill(d, d+20001, INF);

    dijkstra(K);

    for(int i=1; i<=V; i++)
    {
        if(d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}