// 미로만들기
// n x n 크기의 맵이 있다. (0, 0)에서 출발하여 (n-1, n-1)까지 도달해야 한다. 맵의 각 위치에는 하얀 방과 검은 방이 존재하는데,
// 검은 방은 지나갈 수 없다. 도착지점까지 도달하는데 검은 방을 흰 방으로 바꿔야하는 최소한의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 987654321
#define MAX_N 51

using namespace std;

typedef struct Node
{
    int x;
    int y;
    int dist;
}Node;

bool operator < (Node a, Node b)
{
    return a.dist > b.dist;
}

char map[MAX_N][MAX_N];
int d[MAX_N*MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }
    fill(d, d+MAX_N*MAX_N, INF);

    priority_queue<Node> pq;
    pq.push({0, 0, 0});
    d[0] = 0;

    while(!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int dist = pq.top().dist;
        int idx = x*n+y;
        pq.pop();

        if(d[idx] < dist) continue;
        for(int i=0; i<4; i++)
        {
            if(x+dx[i] < 0 || x+dx[i] >= n || y+dy[i] < 0 || y+dy[i] >= n) continue;

            int cost = d[idx] + !(map[x+dx[i]][y+dy[i]] - '0');
            int nextIdx = (x+dx[i])*n+(y+dy[i]);
            if(d[nextIdx] > cost)
            {
                d[nextIdx] = cost;
                pq.push({x+dx[i], y+dy[i], cost});
            }
        }
    }

    cout << d[(n-1)*n+n-1] << '\n';
}