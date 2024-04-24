// DFS와 BFS
// 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.


// 내 답안1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 1001
#define MAX_M 10001

using namespace std;

vector<int> graph[MAX_N];

void dfs(int start, int visited[])
{
    cout << start << ' ';
    for(int i=0; i<graph[start].size(); i++)
    {
        if(!visited[graph[start][i]])
        {
            visited[graph[start][i]] = 1;
            dfs(graph[start][i], visited);
        }
    }
}

void bfs(int start, int visited[])
{
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        cout << now << ' ';
        for(int i=0; i<graph[now].size(); i++)
        {
            if(visited[graph[now][i]] == 0)
            {
                visited[graph[now][i]] = 1;
                q.push(graph[now][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v;
    int visited[MAX_N];

    cin >> n >> m >> v;
    for(int i=0; i<m; i++)
    {
        int a, b;

        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());

    fill(visited, visited+MAX_N, 0);

    visited[v] = 1;

    dfs(v, visited);
    cout << '\n';

    fill(visited, visited+MAX_N, 0);
    visited[v] = 1;

    bfs(v, visited);
    cout << '\n';
}
