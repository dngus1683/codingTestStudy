// 해킹
// 하나의 컴퓨터가 해킹되었을 때, 서로 연결되어 있는 컴퓨터끼리는 전염된다. 해킹된 컴퓨터의 수와 걸린 시간을 구하라


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAXN 10001

using namespace std;

vector<pair<int, int>> graph[MAXN];
int d[MAXN];

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

        if(d[now]< dist) continue;
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

void answer(int n)
{
    int M = 0, cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(d[i] == INF) continue;
        M = max(M, d[i]);
        cnt++;
    }
    cout << cnt << ' ' << M << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for(int TestCase=0; TestCase < T; TestCase++)
    {
        int v, e, k;
        cin >> v >> e >> k;
        for(int i=0; i<e; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            graph[b].push_back({a, c});
        }

        fill(d, d+MAXN, INF);

        dijkstra(k);

        answer(v);
        for(int i=1; i<v+1; i++)
        {
            graph[i].clear();
        }
    }
}