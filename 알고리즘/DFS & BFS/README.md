# DFS(Depth-First Search)

DFS(Depth-First Search)는 그래프 탐색 알고리즘 중 하나로, 깊이를 우선으로 탐색하는 알고리즘이다. 시작 정점에서 한 방향으로 최대한 깊이 탐색한 후, 더 이상 탐색할 수 없을 때 다른 방향의 정점을 탐색한다. 이러한 방식으로 그래프를 순회하며 정점을 방문한다.

## Algorithm
DFS 알고리즘은 재귀 호출을 이용하거나 스택 자료구조를 사용하여 구현할 수 있으며, 일반적으로는 재귀 호출을 사용하여 구현한다.

1. 시작 정점을 방문하고 방문한 정점으로 표시한다.
2. 현재 정점과 인접한 정점들을 탐색한다.
3. 방문하지 않은 정점이 있다면 해당 정점으로 이동하여 다시 DFS를 수행한다.
4. 모든 정점을 방문할 때까지 이 과정을 반복한다.

![Depth-First-Search](https://github.com/dngus1683/codingTestStudy/assets/71319694/2974d611-163c-4e68-8a9f-8d0ec5501fdd)

## Pseudocode
```
function DFS(graph, start, visited):
    if start is not visited:
        mark start as visited
        process(start)

        for each neighbor of start:
            if neighbor is not visited:
                DFS(graph, neighbor, visited)
```

## Complexity
+ 시간 복잡도: O(V + E) (V: 정점 수, E: 간선 수)
+ 공간 복잡도: O(V) (V: 방문된 노드를 저장하는 데 사용되는 공간)


## Implementation
+ C++
    ```c++
    #include <iostream>
    #include <vector>
    #include <stack>
    
    using namespace std;

    bool visited[];
    vector<vector<int>> graph = {
        {1, 2},     
        {0, 3, 4},  
        {0, 5},     
        {1},        
        {1},        
        {2}         
    };

    // 스택 활용
    void dfs(vector<vector<int>>& graph, int start) {
        vector<bool> visited(graph.size(), false);
        stack<int> stk;
        stk.push(start);
    
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
    
            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;
    
                for (int i = graph[node].size() - 1; i >= 0; --i) {
                    int neighbor = graph[node][i];
                    if (!visited[neighbor]) {
                        stk.push(neighbor);
                    }
                }
            }
        }
    }

    // 스택 사용(x)
    void dfs(int start)
    {
        visited[start] = true;
        for(int i=0; i<graph[start].size(); i<++)
        {
            if(!visited[graph[start][i]]) dfs(graph[start][i]);
        }
    }
    ```

## Reference
+ 이미지 출처 : [DFS - Wikipedia](https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# BFS(Breadth-First Search)

BFS(Breadth-First Search)는 그래프 탐색 알고리즘 중 하나로, 너비를 우선으로 탐색하는 알고리즘이다. 시작 정점에서 인접한 정점들을 먼저 모두 방문한 후에, 해당 정점들과 인접한 정점들을 탐색한다.

## Algorithm
BFS 알고리즘은 큐 자료구조를 사용하여 구현된다.

1. 시작 정점을 큐에 넣고 방문한 정점으로 표시한다.
2. 큐에서 정점을 하나 꺼내어 인접한 정점들을 탐색한다.
3. 인접한 정점들 중에서 방문하지 않은 정점이 있다면 큐에 넣고 방문한 정점으로 표시한다.
4. 큐가 빌 때까지 이 과정을 반복한다.

![Animated_BFS](https://github.com/dngus1683/codingTestStudy/assets/71319694/d2d86187-0bd1-4c1c-93dc-b11fc1257979)


## Pseudocode
```
function BFS(graph, start):
    initialize an empty queue
    enqueue start
    mark start as visited

    while queue is not empty:
        dequeue a vertex from queue
        process(vertex)

        for each neighbor of vertex:
            if neighbor is not visited:
                mark neighbor as visited
                enqueue neighbor
```

## Complexity
+ 시간 복잡도: O(V + E) (V: 정점 수, E: 간선 수)
+ 공간 복잡도: O(V) (V: 방문된 노드를 저장하는 데 사용되는 공간)


## Implementation
+ C++
    ```c++
    #include <iostream>
    #include <vector>
    #include <queue>
    
    using namespace std;

    vector<int> graph[MAX_V];
    bool visited[MAX_V];
    
    void bfs(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " "; // 방문한 노드 출력
    
            // 현재 노드와 연결된 모든 노드에 대해 탐색
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    ```



## Reference
+ 이미지 출처 : [BFS - Wikipedia](https://ko.wikipedia.org/wiki/%EB%84%88%EB%B9%84_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89)
