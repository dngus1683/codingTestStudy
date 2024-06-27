# Dijkstra (다익스트라)

다익스트라(Dijkstra) 알고리즘은 단일 출발점에서 다른 모든 정점까지의 최단 경로를 찾는 알고리즘이다. 이 알고리즘은 음의 가중치를 갖지 않는 그래프에서 사용된다

## Algorithm
1. 출발 노드를 설정하고, 출발 노드의 거리를 0으로 초기화하고, 나머지 노드들의 거리를 무한대로 초기화한다.
2. 아직 처리하지 않은 노드들 중에서 출발 노드와의 거리가 가장 짧은 노드를 선택한다.
3. 선택한 노드를 방문 처리하고, 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리를 갱신한다.
4. 방문하지 않은 노드 중에서 거리가 가장 짧은 노드를 선택하고 위의 과정을 반복한다.
5. 모든 노드를 방문할 때까지 위의 과정을 반복한다.

![Dijkstra_Animation](https://github.com/dngus1683/codingTestStudy/assets/71319694/c602d9be-2a3d-4644-b5b4-57533a721009)


## Pseudocode
```
function Dijkstra(Graph, source):
    dist[source] ← 0
    create vertex set Q

    for each vertex v in Graph:
        if v ≠ source
            dist[v] ← INFINITY
        add v to Q

    while Q is not empty:
        u ← vertex in Q with min dist[u]
        remove u from Q

        for each neighbor v of u:
            alt ← dist[u] + length(u, v)
            if alt < dist[v]
                dist[v] ← alt

    return dist
```
      


## Complexity
- 시간 복잡도: O((V + E) log V) (우선순위 큐를 사용할 경우)
- 공간 복잡도: O(V)


## Implementation
+ ### C++
   C++은 우선순위 큐인 priority_queue를 사용하여 거리가 짧은 노드부터 계산을 하도록 한다. 이때, priority_queue는 기본적으로 내림차순이므로, 일부러 거리를 음수화하여 짧은 거리가 큐에 top으로 오게 끔 한다. 
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAX_N 10001

using namespace std;

vector<pair<int, int>> graph[MAX_N]; // 그래프를 표현하는 인접 리스트
int d[MAX_N]; // 시작점으로부터의 최단 거리를 저장하는 배열

// 다익스트라 알고리즘 함수
void dijkstra(int start)
{
  priority_queue<pair<int, int>> pq; // 우선순위 큐를 사용하여 가장 짧은 거리의 노드 선택
  pq.push({0, start}); // 시작 노드부터 시작
  d[start] = 0; // 시작 노드의 최단 거리는 0으로 초기화

  while(!pq.empty())
  {
    int dist = -pq.top().first; // 현재 노드까지의 최단 거리
    int now = pq.top().second; // 현재 노드
    pq.pop();

    if(d[now] < dist) continue; // 이미 최단 거리를 갱신했을 경우 무시

    // 현재 노드와 연결된 모든 노드에 대해 최단 거리 갱신
    for(int i=0; i<graph[now].size(); i++)
    {
      int next = graph[now][i].first; // 다음 노드
      int cost = d[now] + graph[now][i].second; // 현재 노드를 거쳐서 다음 노드까지의 비용

      // 최단 거리 갱신
      if(d[next] > cost)
      {
        d[next] = cost;
        pq.push({-cost, next}); // 음수로 넣어서 거리가 짧은 순서대로 정렬되도록 함
      }
    }
  }
}
```

여기서, 그래프나 우선순위 큐에 넣을 데이터가 {int, int}가 아닌 다른 형태의 데이터라면(예를 들면 데이터가 3개 이상으로 이루어져 있는 등), 구조체와 연산자 오버로딩을 활용하여 해결한다.

```c++
#include <iostream>
...

typedef struct node
{
  int x;
  int y;
  int dist;
  int idx;
}node;

bool operator > (node a, node b)
{
  return a.dist < b.dist;
}

vector<node> graph[MAX_N];  // pair<int, int> 대신 node
int d[MAX_N];   

// 다익스트라 알고리즘 함수
void dijkstra(node start)
{
  priority_queue<node> pq; // 연산자 오버로딩을 통해 node의 dist 성분이 작을수록 우선순위를 매김. 때문에 거리 값을 따로 음수처리하지 않아도 됨.
  pq.push(start); 
  d[start.idx] = 0; 

  while(!pq.empty())
  {
    int x = pq.top().x; 
    int y = pq.top().y;
    int dist = pq.top().dist;
    int idx = pq.top().idx;
    pq.pop();
    ...
  }
}
```

## References
- 이미지 출처: [Dijkstra's algorithm - Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)



--------------------------


# Floyd-Warshall (플로이드-워셜)

플로이드-워셜(Floyd-Warshall) 알고리즘은 모든 쌍 최단 경로를 찾는 알고리즘으로, 모든 정점에서 모든 정점으로의 최단 경로를 찾는다. 음의 가중치를 허용하는 그래프에서도 사용할 수 있으며, 모든 정점에 대해 최단 거리를 찾아야 할 때는 다익스트라 알고리즘보다 적절할 수 있다.

## Algorithm
플로이드-워셜 알고리즘은 다음과 같은 점화식을 사용하여 최단 거리를 계산한다.

$`D[i][j] = w_{ij} `$  if $`k=0`$

$`D[i][j] = min(D[i][j], D[i][k] + D[k][j])`$  if $`k>=1`$

여기서 D[i][j]는 정점 i에서 정점 j로 가는 최단 거리를 나타낸다. 

i에서 j까지 가는데, 중간에 다른 정점을 k개 거쳐서 가는 거리를 모두 비교한다.

![600px-Floyd-Warshall_example svg](https://github.com/dngus1683/codingTestStudy/assets/71319694/830cf270-9ea3-4e5c-8041-a5e0f95df522)

![화면 캡처 2024-03-27 174519](https://github.com/dngus1683/codingTestStudy/assets/71319694/5157fdc7-c6ba-46e9-b0b0-4eaf06aea4c8)


## Pseudocode
```plaintext
  for k from 1 to |V|:
       for i from 1 to |V|:
           for j from 1 to |V|:
               d[i][j] = min(d[i][j], d[i][k] + d[k][j])

```


## Complexity
- 시간 복잡도: O(V^3)
- 공간 복잡도: O(V^2)


## Implementation
+ ### C++
```c++
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX_N 101

using namespace std;

int graph[MAX_N][MAX_N]; // 그래프를 표현하는 인접 행렬

void floydWarshall(int V) {
    // dist 배열을 초기화
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) graph[i][j] = 0; // 자기 자신으로의 경로는 0
            else if (graph[i][j] == 0) graph[i][j] = INF; // 경로가 없는 경우 무한대로 초기화
        }
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
```


## References
- 이미지 출처: [Floyd-Warshall algorithm - Wikipedia](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)


--------------------------


# 벨만-포드 알고리즘 (Bellman-Ford Algorithm)

벨만-포드 알고리즘(Bellman-Ford Algorithm)은 가중치가 있는 그래프에서 한 정점에서 다른 모든 정점으로의 최단 경로를 찾는 알고리즘으로, 다익스트라 알고리즘과의 차이점은 **가중치가 음수인 간선이 포함된 그래프에서도 동작**한다.

## Algorithm
벨만-포드 알고리즘:

1. 시작 정점의 거리를 0으로, 나머지 정점의 거리를 무한대로 설정한다.
2. 모든 간선에 대해 정점을 V-1번 반복하며 거리를 갱신한다.
3. 모든 간선을 다시 검사하여 거리가 더 줄어들 수 있다면 음수 사이클이 존재하는 것이다.

## Pseudocode
```plaintext
function BellmanFord(Graph, source):
    distance[source] = 0
    
    # 반복적으로 모든 간선을 확인하며 거리 갱신
    for i from 1 to size(Graph.V) - 1:
        for each edge (u, v) with weight w in Graph.E:
            if distance[u] + w < distance[v]:
                distance[v] = distance[u] + w
    
    # 음수 사이클 존재 여부 확인
    for each edge (u, v) with weight w in Graph.E:
        if distance[u] + w < distance[v]:
            return "Graph contains a negative-weight cycle"
    
    return distance
```


## Complexity
- 시간 복잡도: O(VE) (V는 정점의 수, E는 간선의 수)


## Implementation
+ ### C++
```c++
void BellmanFord(vector<Edge>& edges, int V, int E, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // 모든 정점을 V-1번 반복하여 최단 거리 계산
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // 한번 더 최단거리를 계산했을 때, 또 새 값이 갱신이 된다면, 해당 맵은 사이클이 존재한다.
    for (int i = 0; i < E; ++i) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative-weight cycle" << endl;
            return;
        }
    }
```
