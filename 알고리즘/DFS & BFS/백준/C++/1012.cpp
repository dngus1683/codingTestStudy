// 유기농 배추
// N x M 크기의 배추 밭에 K개의 배추가 심어져 있다. 해충방지를 위해 배추흰지렁이를 배치하려 하는데, 이 지렁이는 상하좌우 인접한 배추에게도 영향을 준다. 필요한 배추흰지렁이 수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 51
#define MAX_K 2501

using namespace std;

int dn[4] = {-1, 1, 0, 0};
int dm[4] = {0, 0, -1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m, k;

    cin >> T;
    while(T--)
    {
        int ans = 0;
        vector<pair<int, int>> graph[MAX_N*MAX_N];
        bool visited[MAX_N][MAX_N];

        cin >> m >> n >> k;
        for(int i=0; i<k; i++)
        {
            int a, b;

            cin >> a >> b;
            for(int i=0; i<4; i++)
            {
                if(a+dm[i] > m-1 || a+dm[i] < 0 || b+dn[i] > n-1 || b+dn[i] < 0)
                    continue;
                graph[b*m + a].push_back({a+dm[i], b+dn[i]});
            }
        }
        fill(&visited[0][0], &visited[MAX_N-1][MAX_N], false);
//        for(int y=0; y<n; y++)
//            for(int x=0; x<m; x++)
//            {
//                cout << x << ' ' << y << ": ";
//                if(!graph[y*m+x].empty())
//                {
//                    for(int i=0; i<graph[y*m+x].size(); i++)
//                        cout << graph[y*m+x][i].first << ' ' << graph[y*m+x][i].second << ", ";
//                }
//                cout << endl;
//
//            }


        for(int y=0; y<n; y++)
            for(int x=0; x<m; x++)
            {
                if(visited[y][x] || graph[y*m+x].empty()) continue;

                queue<pair<int, int>> q;
                q.push({x, y});

                visited[y][x] = true;
                while(!q.empty())
                {
                    int nowA = q.front().first;
                    int nowB = q.front().second;
                    q.pop();

                    for(int i=0; i<graph[nowB*m+nowA].size();i++)
                    {
                        int nextA = graph[nowB*m+nowA][i].first;
                        int nextB = graph[nowB*m+nowA][i].second;
                        if(!visited[nextB][nextA] && !graph[nextB*m+nextA].empty())
                        {
                            visited[nextB][nextA] = true;
                            q.push({nextA, nextB});
                        }
                    }
                }
                ans++;
            }
        cout << ans << '\n';
    }
}











// 답안 예시1
//#include <stdio.h>
//char farm[52][52];
//void dfs(int x,int y){
//    if(!farm[x][y]) return;
//    farm[x][y]=0;
//    dfs(x,y+1),dfs(x,y-1),dfs(x+1,y),dfs(x-1,y);
//    return;
//}
//int solve(){
//    int m,n,k,cnt=0;
//    scanf("%d%d%d",&m,&n,&k);
//    for(int i=0,x,y;i<k;++i) scanf("%d%d",&x,&y), farm[y+1][x+1]=1;
//    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(farm[i][j]) ++cnt,dfs(i,j);
//    return cnt;
//}
//int main(){
//    int T;
//    scanf("%d",&T);
//    while(T--) printf("%d\n",solve());
//    return 0;
//}
