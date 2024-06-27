// 골목 대장 호석 - 기능성
// N개의 마을과 M개의 양방향 길이 주어진다. 각 길을 지나갈 때, 요금을 내야 하는데, 예산 내에서 한 길에서 수금되는 요금이 가장 적은 길로 가야한다.
// 예를 들어, 예산이 10일 때, 경로 1) 5 + 5, 경로 2) 1 + 6 + 1 이러한 경우라면, 총 비용은 경로 2가 덜 들지만 단일 요금은 6이 가장 크기 때문에 경로 1로 가아햔다.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 11
#define INF 987654321

using namespace std;

typedef struct Node
{
    int now;
    int dist;
    int MaxCost;
}Node;

bool operator < (Node a, Node b)
{
    return a.dist > b.dist;
}

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];
int ans[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, S, T, C;

    cin >> N >> M >> S >> T >> C;
    for(int i=0; i<M; i++)
    {
        int a, b, w;

        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    fill(d, d+MAX_N, INF);
    fill(ans, ans+MAX_N, INF);

    priority_queue<Node> pq;
    pq.push({S, 0, 0});

    d[S] = 0;
    ans[S] = 0;
    while(!pq.empty())
    {
        int now = pq.top().now;
        int MaxCost = pq.top().MaxCost;
        pq.pop();

        if((ans[now] < MaxCost) || d[now] > C) continue;
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = d[now] + graph[now][i].second;
            int mc = (ans[now] > graph[now][i].second ? ans[now] : graph[now][i].second);
            if((ans[graph[now][i].first] > mc) && (cost <= C))
            {
                ans[graph[now][i].first] = mc;
                d[graph[now][i].first] = cost;
                pq.push({graph[now][i].first, cost, mc});
            }
        }
    }

    cout << (ans[T] == INF ? -1 : ans[T]) << '\n';
}
