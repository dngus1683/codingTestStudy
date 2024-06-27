// 파티
// N개의 마을에 학생이 각 한 명씩 있음. 모두들 특정 마을로 모이기로 함.
// 학생들이 모였다가 다시 본인들의 마을로 돌아가야 한다고 할 때, 가장 많은 시간을 소비하는 학생을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[10001];
int d[1001];
int bd[1001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    fill(d, d+1001, INF);
    d[start] = 0;
    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist)   continue;
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

    int N, M, X;

    cin >> N >> M >> X;
    for(int i = 0; i<M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int ans = 0;
    dijkstra(X);
    for(int i=0; i<1001; i++)
    {
        bd[i] = d[i];
    }

    for(int i=1; i<N+1;i++)
    {
        int backward = bd[i];
        dijkstra(i);
        ans = max(ans, backward + d[X]);

    }
    cout << ans << '\n';

}

