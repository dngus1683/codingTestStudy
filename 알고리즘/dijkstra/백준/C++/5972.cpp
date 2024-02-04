// 택배 배송
// 농부 A가 농부 B에게 택배 배달을 하는데, 가는 길에 보이는 모든 헛간들에 있는 소들에게 여물을 줘야 한다.
// 가장 덜 여물을 주면서 도착하는 경우를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 987654321
#define MAX_N 50001
#define MAX_M 50001

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

    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(d, d+MAX_N, INF);

    dijkstra(1);
    cout << d[N] << '\n';

}
