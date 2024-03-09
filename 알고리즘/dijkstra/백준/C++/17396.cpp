// 백도어
// 0의 위치에서 N-1에 있는 상대 넥서스를 향해 백도어를 하러 가야한다.
// 1~ N-2를 거쳐서 가야 하는데, 상대 시야에 걸리는 곳은 지나갈 수 없고, 각 간선은 양방향이다.
// 적 팀 넥서스까지 가는 최소 시간을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 100001
#define MAX_M 300001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];
int visible[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >>  visible[i];
    }
    visible[n - 1] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        if (visible[a] || visible[b]) continue;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    fill(d, d + MAX_N, INF);

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 0 });
    d[0] = 0;

    while (!pq.empty())
    {
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (d[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = d[now] + graph[now][i].second;
            if (d[graph[now][i].first] > cost)
            {
                d[graph[now][i].first] = cost;
                pq.push({ -cost, graph[now][i].first });
            }
        }
    }
    cout << (d[n - 1] == INF ? -1 : d[n-1]) << '\n';
}