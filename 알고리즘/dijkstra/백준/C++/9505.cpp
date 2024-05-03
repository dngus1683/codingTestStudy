// 엔터프라이즈호 탈출
// 상하좌우로 이동가능한 좌표 내에서 엔터프라이즈 호가 클링온 호를 무력화 시키며 맵의 가장자리까지 가야 한다.
// 각 클래스 별로 클링온 호를 무력화 시키는 데 필요한 수치가 주어질 때, 엔터프라이즈 호가 탈출하는 데 걸리는 최소 시간을 구하라.
// 엔터프라이즈 호의 위치는 'E'로 주어지고 탈출 지점은 어떤 곳이든 상관없이 가장자리다.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define INF 987654321
#define MAX_T 101
#define MAX_K 26
#define MAX_W 1001
#define MAX_H 1001

using namespace std;

vector<pair<int, int>> graph[MAX_H*MAX_W];
vector<int> EndPoint;
map<char, int> class_k;
char pl[MAX_H][MAX_W];
int d[MAX_H*MAX_W];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int StartPoint = 0;

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

    int T;
    cin >> T;
    for(int TestCase=0; TestCase < T; TestCase++)
    {
        int K, W, H;
        cin >> K >> W >> H;

        fill(d, d+MAX_H*MAX_W, INF);
        fill(&pl[0][0], &pl[MAX_H-1][MAX_W], 0);
        EndPoint.clear();
        class_k.clear();
        for(int i=0; i<MAX_H*MAX_W; i++)
            graph[i].clear();

        for(int i=0; i<K; i++)
        {
            char cl;
            int weight;
            cin >> cl >> weight;

            class_k.insert({cl, weight});
        }

        for(int i=0; i<H; i++)
        {
            cin >> pl[i];
        }

        for(int i=0; i<H; i++)
        {
            for(int j=0; j<W; j++)
            {
                int IdxNow = i*W + j;
                if(i == 0 || i == H-1 || j == 0 || j == W-1 ) EndPoint.push_back(IdxNow);
                if(pl[i][j] == 'E') StartPoint = IdxNow;
                for(int k=0; k<4; k++)
                {
                    if(i+dy[k] < 0 || i+dy[k] >= H || j+dx[k] < 0 || j+dx[k] >= W ) continue;

                    int IdxNext = (i+dy[k])*W + j+dx[k];
                    int ClassWeight = class_k.find(pl[i+dy[k]][j+dx[k]])->second;

                    if(pl[i+dy[k]][j+dx[k]] == 'E')
                    {
                        ClassWeight = 0;
                    }
                    graph[IdxNow].push_back({IdxNext, ClassWeight});
                }
            }
        }

        dijkstra(StartPoint);

        int minP = INF;
        for(int i=0; i<EndPoint.size(); i++)
        {
            if(minP > d[EndPoint[i]]) minP = d[EndPoint[i]];
        }

        cout << minP << '\n';

    }
}









// 답안 예시1 - https://www.acmicpc.net/source/26873462
// 똑같이 dijkstra로 구현하였지만, 입력을 구조체로 받고, 가장자리에 도착하는 것을, 우선순위 큐의 수의 크기 순으로 빼내는 특성을 활용하여 dijkstra 중 벽에 도착하면 정답을 출력하고 바로 해당 반복문을 종료시키는 방법으로 구현하여 내 답안1에 비해 메모리도 아끼고 시간도 절약하였다
//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//typedef struct node{
//    int y;
//    int x;
//    int d;
//}node;
//
//bool operator<(node t, node u) {
//    return t.d > u.d;
//}
//
//char MAP[1000][1000];
//int CLO[26];
//int MIN[1000][1000];
//int DIR[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
//int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int T, K, C, R, I;
//    char A;
//
//    cin >> T;
//    while (T--) {
//        priority_queue<node> Q;
//
//        cin >> K >> C >> R;
//        for (int i = 0; i < R; i++)
//            for (int j = 0; j < C; j++)
//                MIN[i][j] = 2100000000;
//
//        for (int i = 0; i < K; i++) {
//            cin >> A >> I;
//            CLO[A - 'A'] = I;
//        }
//
//        for (int i = 0; i < R; i++) {
//            for (int j = 0; j < C; j++) {
//                cin >> MAP[i][j];
//                if (MAP[i][j] == 'E') {
//                    Q.push({ i, j, 0 });
//                    MIN[i][j] = 0;
//
//                }
//            }
//        }
//
//        while (!Q.empty()) {
//            node cur = Q.top();
//            Q.pop();
//
//            if (!cur.y || cur.y == R - 1 || !cur.x || cur.x == C - 1) {
//                cout << MIN[cur.y][cur.x] << "\n";
//                break;
//            }
//
//            for (int d = 0; d < 4; d++) {
//                int NY = cur.y + DIR[d][0];
//                int NX = cur.x + DIR[d][1];
//
//                if (0 <= NY && NY <= R - 1 && 0 <= NX && NX <= C - 1 && MIN[NY][NX] > MIN[cur.y][cur.x] + CLO[MAP[NY][NX] - 'A']) {
//                    MIN[NY][NX] = MIN[cur.y][cur.x] + CLO[MAP[NY][NX] - 'A'];
//                    Q.push({ NY, NX, MIN[NY][NX] });
//                }
//            }
//        }
//
//    }
//
//    return 0;
//}
