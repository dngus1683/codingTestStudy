// 녹색 옷 입은 애가 젤다지?
// N x N 크기의 동굴에서 링크가 (0, 0)에서 출발하여 (N-1, N-1)까지 가는데, 동굴 모든 곳에 도둑 루피가 있다.
// 도둑 루피를 먹으면 루피를 잃게 되는데, 도착지점에 도달할 때 가장 적게 루피를 잃는 경우를 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 987654321
#define MAX_N 126

using namespace std;

vector<pair<int, int>> graph[MAX_N * MAX_N];
int map[MAX_N][MAX_N];
int d[MAX_N*MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({map[0][0], start});

    d[start] = map[0][0];

    while(!(pq.empty()))
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

    int cnt=1;
    while(true)
    {
        int N;
        cin >> N;
        if(N == 0) break;

        fill(d, d+MAX_N*MAX_N, INF);
        for(int i=0; i<N*N; i++)
            graph[i].clear();

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N ; j++)
            {
                int a;
                cin >> a;
                map[i][j] = a;
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N ; j++)
            {
                for(int k=0; k<4; k++)
                {
                    if(i+dx[k] < 0 || i+dx[k] >= N || j+dy[k] < 0 || j+dy[k] >= N)  continue;

                    int IdxNow = i*N + j;
                    int IdxNext = (i+dx[k])*N + j+dy[k];

                    graph[IdxNow].push_back({IdxNext, map[i+dx[k]][j+dy[k]]});
                }
            }
        }

        dijkstra(0);

        cout << "Problem " << cnt << ": " <<  d[N*N - 1] << '\n';
        cnt ++;
    }


}












// 답안 예시1
// BFS로 풀기
// 구조체 활용 검토 필요
//#include <cstdio>
//#define SIZE (125)
//
//struct Data
//{
//    int y;
//    int x;
//    int luppy;
//    bool operator < (const Data &r) const
//    {
//        return luppy <r.luppy;
//    }
//};
//
//template <typename T>
//struct Compare
//{
//    bool operator () (const T& lhs, const T &rhs) const
//    {
//        return lhs < rhs;
//    }
//};
//
//template <typename T, typename Cmp>
//class PriorityQueue
//{
//public:
//    PriorityQueue()
//    {
//        hn =0;
//    }
//    void clear()
//    {
//        hn =0;
//    }
//    void push(const T&data)
//    {
//        int c = ++hn;
//        for (; c > 1 && cmp(data , heap[c >> 1]); c >>= 1)
//            heap[c] = heap[c >> 1];  // 부모의 값을 child값(nd) 위치로 내리기
//        heap[c] = data;                // child값(nd)이 들어갈 위치를 찾음.
//    }
//    void pop()
//    {
//        Data nd = heap[hn];
//        int c = 2;
//        heap[hn--] = heap[1];
//        for (; c <= hn; c <<= 1) {
//            c += c < hn && cmp(heap[c + 1] , heap[c]); // 대표 child 선택하기
//            if (cmp(heap[c] , nd))                     // 부모의 값(nd)가 child의 값(heap[c])보다 작다면
//                heap[c >> 1] = heap[c];           // child의 값을 부모의 값으로 한다.
//            else break;                           // 그렇지 않은경우 heap이 완성된경우이므로 종료
//        }
//        heap[c >> 1] = nd;                        // nd가 들어갈 위치를 찾음.
//    }
//    T top() const
//    {
//        return heap[1];
//    }
//
//    bool empty() const
//    {
//        return hn==0;
//    }
//private:
//    T heap[325];
//    int hn;
//    Cmp cmp;
//};
//
//int dirx[]={0,0,-1,1};
//int diry[] = {-1,1,0,0};
//
//inline int get4thVal(const int& N)
//{
//    return N &(15);
//}
//int bfs(int N, short map[][SIZE])
//{
//    PriorityQueue<Data, Compare<Data>> pq;
//
//    pq.push({0,0,get4thVal(map[0][0])});
//
//    map[0][0] = (get4thVal(map[0][0]) << 4) | get4thVal(map[0][0]);
//
//    while(!pq.empty())
//    {
//        auto dat = pq.top();
//        pq.pop();
//
//        if(dat.y == N-1 && dat.x == N-1)
//        {
//            return dat.luppy;
//        }
//
//        for(int i=0; i<4; i++)
//        {
//            int ny = dat.y + diry[i];
//            int nx = dat.x + dirx[i];
//
//            if(0<=ny &&ny <N && 0<=nx && nx <N )
//            {
//                if((map[ny][nx] >> 4) > get4thVal(map[ny][nx]) + dat.luppy) {
//                    map[ny][nx] = (((get4thVal(map[ny][nx]) + dat.luppy)<<4)&map[ny][nx]) | get4thVal(map[ny][nx]);
//                    pq.push({ny,nx, map[ny][nx] >> 4});
//                }
//            }
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    int p = 0;
//    short map[SIZE][SIZE];
//    for(;;) {
//        int N;
//        scanf("%d", &N);
//        if(N==0) break;
//
//        for(int i=0; i<N; i++) {
//            for(int j=0; j<N; j++) {
//                int n;
//                scanf(" %d", &n);
//                map[i][j] = 0x7fff;
//                map[i][j] = ((map[i][j] >> 4)<< 4)|n;
//            }
//        }
//
//        printf("Problem %d: %d\n",++p, bfs(N, map));
//    }
//
//    return 0;
//}
//
//
