// 간선 이어가기 2
// 정점 n개와 무방향 간선의 정보가 m개 주어질 떄, 시작 점에서 도착점까지 가는데 드는 최소 가중치를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321
#define MAX_N 5001
#define MAX_M 100001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    d[start] = 0;

    while(!pq.empty())
    {
        int now = pq.top().second;
        int dist = -pq.top().first;
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

    int n, m, s, t;

    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> s >> t;

    fill(d, d+MAX_N, INF);
    dijkstra(s);

    cout << d[t] << '\n';

}
