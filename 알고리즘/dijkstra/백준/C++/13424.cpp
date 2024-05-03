// 비밀 모임
// N개의 방과, M개의 양방향 길, 비밀 모임 인원 K명, 그리고 각 사람들이 위치해 있는 장소의 번호가 주어진다. 모든 사람들이 이동거리 합이 최소가 되는 비밀 모임 장소를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 101
#define MAX_M ((MAX_N-1)*MAX_N)/2

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int room[MAX_N];
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

    int T;

    cin >> T;
    for(int TestCase=0; TestCase<T; TestCase++)
    {
        int n, m, k, idx, ans = INF;

        for(int i=0; i<MAX_N; i++) graph[i].clear();
        fill(room, room+MAX_N, 0);

        cin >> n >> m;
        for(int i=0; i<m; i++)
        {
            int a, b, c;

            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        cin >> k;
        for(int i=0; i<k; i++)
        {
            cin >> room[i];
        }
        for(int i=1; i<=n; i++)
        {
            int num = 0;

            fill(d,d+MAX_N, INF);
            dijkstra(i);
            for(int j=0; j<k; j++)
            {
                num += d[room[j]];
            }

            if(ans > num)
            {
                ans = num;
                idx = i;
            }
        }

        cout << idx << '\n';
    }
}







// 답안 예시1 - https://www.acmicpc.net/source/8837403
// 플루이드 워셜 알고리즘
//#pragma GCC optimize("O3")
//#pragma GCC target("arch=skylake")
//#include <bits/stdc++.h>
//using namespace std;
//
//int dist[105][105];
//int tar[105];
//
//int main()
//{
//    int T; scanf("%d",&T); while (T--)
//    {
//        memset(dist, 0x3F, sizeof(dist));
//        int n, m;
//        scanf("%d%d",&n,&m);
//
//        for (int i = 0; i < n; i++) dist[i][i] = 0;
//
//        for (int i = 0; i < m; i++)
//        {
//            int a, b, c;
//            scanf("%d%d%d",&a,&b,&c);
//            dist[a-1][b-1] = dist[b-1][a-1] = min(dist[b-1][a-1], c);
//        }
//
//        for (int k = 0; k < n; k++)
//        {
//            int z[105];
//            for (int i = 0; i < n; i++)
//            {
//                int X = dist[i][k];
//                for (int j = 0; j < n; j++)
//                {
//                    z[j] = X + dist[k][j];
//                }
//                for (int j = 0; j < n; j++)
//                {
//                    dist[i][j] = min(dist[i][j], z[j]);
//                }
//            }
//        }
//
//        int x;
//        scanf("%d",&x);
//        for (int i = 0; i < x; i++) scanf("%d",&tar[i]);
//
//        int ans = 0;
//        int ac = 1e9;
//        for (int i = 0; i < n; i++)
//        {
//            int sum = 0;
//            for (int j = 0; j < x; j++) sum += dist[i][tar[j] - 1];
//            if (ac > sum)
//            {
//                ac = sum;
//                ans = i;
//            }
//        }
//
//        printf("%d\n", ans + 1);
//    }
//}
//
