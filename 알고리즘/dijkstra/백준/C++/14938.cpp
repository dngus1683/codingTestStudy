// 서강 그라운드
// N개의 지역은 R개의 길로 서로 연결되어 있으며, 각 지역에는 아이템이 다양한 개수로 존재해 있다. 플레이어의 수색 범위 M이 주어질 때, 최대로 먹을 수 있는 아이템 개수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 101
#define MAX_M 16
#define MAX_R 101

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];
int item[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r, ans = 0;

    cin >> n >> m >> r;
    for(int i=1; i<=n; i++)
    {
        cin >> item[i];
    }
    for(int i=0; i<r; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int start=1; start<=n; start++)
    {
        int num = 0;
        fill(d, d+MAX_N, INF);
        priority_queue<pair<int, int>> pq;
        pq.push({0, start});
        d[start] = 0;

        while(!pq.empty())
        {
            int dist = -pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if(d[now] < dist || dist > m) continue;
            for(int i=0; i<graph[now].size(); i++)
            {
                int cost = d[now] + graph[now][i].second;
                if(d[graph[now][i].first] > cost && cost <= m)
                {
                    d[graph[now][i].first] = cost;
                    pq.push({-cost, graph[now][i].first});
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(d[i] > m) continue;
            num += item[i];
        }
        ans = max(ans, num);
    }

    cout << ans << '\n';
}














// 답안 예시1
// 플로이드 워셜 알고리즘
// 모든 정점에서의 거리를 구해야 하는 문제에서는 다익스트라보다 플로이드 워셜이 더 효율적이다.
// 플로이드 워셜은 한 번에 모든 정점에서의 거리 계산을 진행하기 때문이다.

//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int MAX=100, INF=987654321;
//int main()
//{
//  int n, m, r;
//  int t[MAX];
//  int adj[MAX][MAX];
//  scanf("%d %d %d", &n, &m, &r);
//  fill(&adj[0][0], &adj[n-1][n], INF);
//  for(int i=0; i<n; i++) scanf("%d", t+i);
//  for(int i=0; i<r; i++){
//    int a, b, l;
//    scanf("%d %d %d", &a, &b, &l); a--; b--;
//    adj[a][b] = adj[b][a] = l;
//  }
//  for(int i=0; i<n; i++) adj[i][i]=0;
//  for(int k=0; k<n; k++)
//    for(int i=0; i<n; i++){
//      if(adj[i][k]==INF) continue;
//      for(int j=0; j<n; j++)
//        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
//    }
//  int maxItems=0;
//  for(int i=0; i<n; i++){
//    int items=0;
//    for(int j=0; j<n; j++)
//      if(adj[i][j]<=m) items+=t[j];
//    maxItems=max(maxItems, items);
//  }
//  printf("%d\n", maxItems);
//}
