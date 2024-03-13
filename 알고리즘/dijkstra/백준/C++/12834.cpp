// 주간 미팅
// N명의 사람이 KIST와 씨알 푸드로 최단 거리로 가야 한다. 도착하지 못할 때 거리를 -1이라 하면, 모든 사람의 최단 거리의 합을 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 101
#define MAX_V 1001
#define MAX_E 10001

using namespace std;

vector<pair<int, int>> graph[MAX_V];
int d1[MAX_V];
int d2[MAX_V];
int h[MAX_N];
int ans = 0;

void dijkstra(int start, int *a, int n)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    a[start] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(a[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = a[now] + graph[now][i].second;
            if(a[graph[now][i].first] > cost)
            {
                a[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(a[h[i]] == INF) a[h[i]] = -1;
        ans += a[h[i]];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, v, e, a, b;

    cin >> n >> v >> e;
    cin >> a >> b;
    for(int i=0; i<n; i++)
    {
        cin >> h[i];
    }
    for(int i=0; i<e; i++)
    {
        int x, y, z;

        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    fill(d1, d1+MAX_V, INF);
    fill(d2, d2+MAX_V, INF);
    dijkstra(a, d1, n);
    dijkstra(b, d2, n);

    cout << ans << '\n';
}
