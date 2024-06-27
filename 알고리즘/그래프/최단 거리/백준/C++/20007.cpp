// 떡 돌리기
// 하루에 X보다 먼 거리는 걷지 않으며 각 집에 들려 떡을 모두 나눠줘야 한다. 잠은 집에서 자야하므로 왕복할 수 없는 거리는 다음 날 가기로 할 때, 떡을 모두 돌리는데 최소 며칠이 소요되는지 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 1001
#define MAX_M 100001
#define MAX_X 10000001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int d[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;

    cin >> n >> m >> x >> y;
    for(int i=0; i<m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(d, d+MAX_N, INF);

    priority_queue<pair<int, int>> pq;
    pq.push({0, y});
    d[y] = 0;

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

    int days = 1, num = 0;
    sort(d, d+MAX_N);
    for(int i=1; i<n; i++)
    {
        if(d[i]*2 > x)
        {
            cout << -1 << '\n';
            return 0;
        }

        if(num+d[i]*2 <= x) num += d[i]*2;
        else
        {
            num = d[i]*2;
            days++;
        }

    }

    cout << days << '\n';
}