// 민준이와 마산 그리고 건우
// 민준이는 1번에 위치해 있고 N번에 있는 마산으로 귀향해야 한다. 최단 경로로 가는 중, 1 <= P <= N번에 위치해 있는 건우를 픽업할 수 있다면 픽업해야 한다. 최단 경로 중에 건우를 픽업할 수 있는지 구하라.


// 내 답안1
// 민준이의 최단 경로와, (건우 -> 민준 + 건우 -> 마산)이 같은 지 판단
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_V 5001
#define MAX_E 10001

using namespace std;

vector<pair<int, int>> graph[MAX_V];
int d[MAX_V];

void dijkstra(int start)
{
    fill(d, d+MAX_V, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty())
    {
        int dist = - pq.top().first;
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

    int v, e, p, mj, kw;

    cin >> v >> e >> p;
    for(int i=0; i<e; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(1);
    mj = d[v];
    dijkstra(p);
    kw = d[1] + d[v];

    cout << (mj == kw ? "SAVE HIM" : "GOOD BYE") << '\n';
}
















// 답안 예시1 - https://www.acmicpc.net/source/17953449
// 다익스트라 계산 중 건우를 지났는지 판단
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//#include <climits>
//#include <unordered_set>
//#include <unordered_map>
//#include <cassert>
//#include <iostream>
//#include <string>
//#include <ctime>
//#define ll long long
//#define pll pair<ll,ll>
//#define pii pair<int,int>
//#define pci pair<char,int>
//#define pdd pair<double,double>
//#define pli pair<ll,int>
//#define pil pair<int,ll>
//#define pdi pair<double,int>
//#define pdd pair<double,double>
//#define mod 1000000000
//#define mod1 1000000009
//#define mod2 1000000021
//#define INF 2000000001
//#define MAX 200001
//long double PI = 3.141592653589793238462643383279502884197;
//using namespace std;
//
///* 🐣🐥 */
//int dist[5001];
//bool can[5001];
//priority_queue<pii, vector<pii>, greater<pii>> pq;
//vector<pii> vec[5001];
//void dijk(int k) {
//    memset(dist, 0x3f, sizeof(dist));
//    dist[1] = 0;
//    pq.push({ 0,1 });
//    while (!pq.empty()) {
//        pii cur = pq.top();
//        pq.pop();
//        if (dist[cur.second] < cur.first) continue;
//        if (cur.second == k) can[cur.second] = true;
//        for (pii v : vec[cur.second]) {
//            int tmp = v.first + cur.first;
//            if (tmp < dist[v.second]) {
//                dist[v.second] = tmp;
//                can[v.second] = can[cur.second];
//                pq.push({ tmp,v.second });
//            }
//            else if(tmp == dist[v.second])
//                can[v.second] |= can[cur.second];
//        }
//    }
//}
//int main() {
//    int n, m, k, a, b, c;
//    scanf("%d %d %d", &n, &m, &k);
//    while (m--) {
//        scanf("%d %d %d", &a, &b, &c);
//        vec[a].push_back({ c,b });
//        vec[b].push_back({ c,a });
//    }
//    dijk(k);
//    printf("%s", can[n] ? "SAVE HIM" : "GOOD BYE");
//}
