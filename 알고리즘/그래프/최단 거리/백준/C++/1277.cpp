// 발전소 설치
// 1번 발전소부터 N번 발전소까지 연결하라.
// 이미 연결되어 있는 발전소들도 있으며, M의 전선 제한 길이에 따라 최소한의 전선을 추가로 사용하여 연결시켜라.
// 이때, 각 발전소의 위치는 2차원 좌표로 입력된다.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 1001
#define MAX_W 10001
#define MAX_M 200000.0
#define INF 987654321.0

using namespace std;

pair<double, double> coor[MAX_N];
vector<pair<int, double>> graph[MAX_N];
double d[MAX_N];

double CalDistance(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(a.first-b.first, 2) + pow(a.second - b.second, 2));
}

void dijkstra(int start)
{
    priority_queue<pair<double, int>> pq;
    pq.push({0.0, start});

    d[start] = 0.0;

    while(!pq.empty())
    {
        double dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[start] < dist) continue;
        for(int i=0; i<graph[now].size(); i++)
        {
            double cost = d[now] + graph[now][i].second;
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

    int N, W;
    double M;

    cin >> N >> W;
    cin >> M;
    for(int i=1; i<=N; i++)
    {
        double a,b;
        cin >> a >> b;
        coor[i] = {a, b};
    }
    for(int i=1; i<N; i++)
    {
        for(int j=i+1; j<=N; j++ )
        {
            double dist = CalDistance(coor[i], coor[j]);
            if(dist<=M)
            {
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }
    }
    for(int i=1; i<=W; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 0});
    }

    fill(d, d+MAX_N, INF);

    dijkstra(1);

    cout << int(d[N]*1000)  << '\n';
//    cout << graph[1][1].first << ' ' <<  graph[1][1].second << endl;
//    cout << CalDistance(coor[1], coor[3]) << endl;
//    cout << "==============" << endl;
    int kkk = 9;
    for(int i=0; i<graph[kkk].size(); i++)
    {
        cout << graph[kkk][i].first << ' ' << graph[kkk][i].second << endl;
    }
//    cout << "==============" << endl;
//    for(int i=0; i<=N; i++)
//        cout << d[i] << endl;
}

