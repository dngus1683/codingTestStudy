// 아기 상어
// N x N의 맵에 빈 칸 0, 물고기 크기(1~6), 아기 상어의 위치 9가 주어진다. 아기 상어는 본인보다 작은 물고기만 먹을 수 있고, 본인의 크기만큼 물고기를 먹으면 본인의 크기가 1 증가한다. 또한 본인보다 큰 물고기가 있는 곳은 지나갈 수 없다.
// 아기 상어는 하나라도 먹을 수 있는 물고기가 있다면 먹으러 가며, 그 물고기가 여럿이라면, 가장 가까운 물고기를 먹는다.
// 한 번 이동할 때 1초가 걸린다고 할 때, 몇 초동안 물고기를 먹으러 다니는지 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define INF 987654321
#define MAX_N 21

using namespace std;

int flag = 0;
int N = 0;
int mess = 2;
int EatCnt = 0;
int graph[MAX_N][MAX_N];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int d[MAX_N][MAX_N];

typedef struct point
{
    int i = 0;
    int j = 0;
    int dist = 0;
}point;

point dfs(point now)
{
    if((graph[now.i][now.j] < mess) && (graph[now.i][now.j] > 0))
    {
        flag = 1;
        return now;
    }

    point ans;
    ans.dist = INF;
    for(int i=0; i<4; i++)
    {
        int NextI = now.i+di[i];
        int NextJ = now.j+dj[i];
        if(NextI < 0 || NextI >= N || NextJ < 0 || NextJ >= N || graph[NextI][NextJ] > mess || d[NextI][NextJ] == -1) continue;

        if(d[NextI][NextJ] == 0 || (d[NextI][NextJ] != 0 && d[NextI][NextJ] > now.dist + 1))
        {
            d[NextI][NextJ] = now.dist + 1;
            point next = dfs({NextI, NextJ, now.dist + 1});
            if(flag == 1)
            {
                if(next.dist < ans.dist)
                {
                    ans = next;
                }
                else if(next.dist == ans.dist)
                {
                    if(next.i < ans.i)
                    {
                        ans = next;
                    }
                    else if((next.i == ans.i) && (next.j < ans.j))
                    {
                        ans = next;
                    }
                }
            }
        }
    }
    return (flag ? ans : now);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    point shark;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 9)
            {
                shark.i = i;
                shark.j = j;
                graph[i][j] = 0;
            }
        }
    }
    while(true)
    {
        flag = 0;
        memset(d, 0, sizeof(d));
        d[shark.i][shark.j] = -1;
        shark = dfs(shark);

        if(flag == 1)
        {
            EatCnt ++;
            graph[shark.i][shark.j] = 0;
        }
        else
        {
            break;
        }
        if(EatCnt == mess)
        {
            EatCnt = 0;
            mess ++;
        }
    }
    cout << shark.dist << '\n';

}
