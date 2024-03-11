// 특정 거리의 도시 찾기
// N개의 도시와 M개의 도로가 주어질 때, K번 만에 도착하는 도시를 모두 출력하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX_N 300001
#define MAX_M 1000001
#define MAX_K 300001
#define MAX_X 300001
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, x;

    cin >> n >> m >> k >> x;
    for(int i=0; i<m; i++)
    {
        int a, b;

        cin >> a >> b;
        graph[a].push_back({b, 1});
    }

    fill(d, d+MAX_N, INF);

    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    d[x] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
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

    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(d[i] == k)
        {
            cout << i << '\n';
            cnt ++;
        }
    }

    if(!cnt) cout << -1 << '\n';
}
