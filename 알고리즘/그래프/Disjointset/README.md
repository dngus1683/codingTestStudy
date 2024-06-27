# Disjoint Set (서로소 집합)

Disjoint Set, 또는 Union-Find 알고리즘은 서로 중복되는 원소가 없는 집합들의 모임을 관리하는 자료구조다. 주로 합집합(Union)과 찾기(Find) 연산을 지원하여 원소들을 효율적으로 관리한다.

## Algorithm
Disjoint Set은 다음과 같은 두 가지 주요 연산을 지원합니다:

1. **합집합(Union)**: 두 개의 집합을 하나의 집합으로 합칩니다. 즉, 두 원소가 속한 집합을 하나로 만듭니다.
2. **찾기(Find)**: 특정 원소가 속한 집합(또는 대표 원소)을 찾습니다. 이 때, 두 원소의 집합이 같은지를 확인하기 위해 사용됩니다.


## Pseudocode
```
 function MakeSet(x)
     x.parent := x
```
```
 function Find(x)
     if x.parent == x
        return x
     else
        return Find(x.parent)
```
```
 function Union(x, y)
     xRoot := Find(x)
     yRoot := Find(y)
     xRoot.parent := yRoot
```

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# 최소 신장 트리 알고리즘 (Minimum Spanning Tree) 
 최소 신장 트리란, 주어진 그래프의 모든 정점을 연결하되 사이클이 없고 가중치의 합이 최소인 트리를 의미한다.
 
 **간선이 많을 경우 prim (O(ElogV)), 간선이 적을 경우 cruscal (O(ElogE))   (E:간선, V: 정점)**
 
+ # 크루스칼 알고리즘 (Kruskal's Algorithm)
  간선을 기준으로 최소 신장 트리를 구축하는 알고리즘이다.
  Disjoint Set을 사용하여 각 노드의 속한 집합을 관리하고, 사이클을 형성하지 않는 간선들을 선택하여 최소 신장 트리를 찾는다.

  ## Algorithm
  크루스칼 알고리즘은 간선을 기준으로 그래프를 탐색하여 최소 신장 트리를 구축한다. 간선들을 가중치의 오름차순으로 정렬한 뒤, 가장 작은 가중치의 간선부터 차례대로 추가하면서 사이클을 형성하지 않는지 검사한다.
  
  1. 모든 간선을 가중치의 오름차순으로 정렬한다.
  2. 가장 작은 가중치의 간선부터 선택한다.
  3. 선택한 간선을 추가할 때 사이클이 형성되지 않는지 검사한다.
  4. 사이클이 형성되지 않는 경우 해당 간선을 최소 신장 트리에 추가한다.
  5. 모든 간선을 처리할 때까지 2~4단계를 반복한다.
  
  ## Pseudocode
  ```
  function Kruskal(graph):
    sort edges of graph by weight in non-decreasing order
    initialize an empty set for the minimum spanning tree (MST)
    initialize a disjoint set data structure to keep track of connected components

    for each vertex v in graph:
        make_set(v)  // Create a disjoint set for each vertex

    for each edge (u, v) in sorted edges:
        if find(u) ≠ find(v):  // Check if u and v belong to different connected components
            add edge (u, v) to MST
            union(u, v)  // Merge the connected components to which u and v belong

    return MST
  ```
  
  ## Complexity
  + 시간 복잡도: O(E log E) (E: 간선 수)
  + 공간 복잡도: O(V + E) + O(V) (O(V + E): 그래프 표현에 필요한 공간, O(V): Disjoint Set 자료구조에 필요한 공간)
                일반적으로는 정점의 개수 V가 간선의 개수 E보다 작거나 같기 때문에 O(V + E)로 표현.

  ## Implementation
  + C++
      ```c++
      #include <iostream>
      #include <vector>
      #include <algorithm>
      
      #define MAX_V 10001
      #define MAX_E 100001
      
      using namespace std;
      
      typedef struct node
      {
      	int a;
      	int b;
      	int cost;
      };
      
      bool compare(node a, node b)
      {
      	return a.cost < b.cost;
      }
      
      vector<node> graph;
      int parent[MAX_V];
      int ans = 0;
      
      
      
      int find_parent(int x)
      {
      	if (parent[x] != x)
      		parent[x] = find_parent(parent[x]);
      	return parent[x];
      }
      
      void union_parent(int a, int b)
      {
      	a = find_parent(a);
      	b = find_parent(b);
      
      	if (a > b)
      		parent[a] = b;
      	else
      		parent[b] = a;
      }
      
      int main()
      {
      	ios_base::sync_with_stdio(false);
      	cin.tie(0);
      
      	int v, e;
      
      	cin >> v >> e;
      
      	for (int i = 0; i <= v; i++)
      	{
      		parent[i] = i;
      	}
      
      	for (int i = 0; i < e; i++)
      	{
      		int a, b, c;
      
      		cin >> a >> b >> c;
      		graph.push_back({ a, b, c });
      	}
      
      	sort(graph.begin(), graph.end(), compare);
      
      	for (node nd : graph)
      	{
      		if (find_parent(nd.a) != find_parent(nd.b))
      		{
      			union_parent(nd.a, nd.b);
      			ans += nd.cost;
      		}
      	}
      	
      
      	cout << ans << '\n';
      }
      ```

  # 프림 알고리즘 (Prim's Algorithm)
  정점을 기준으로 최소 신장 트리를 구축하는 알고리즘이다. 시작 정점에서 출발하여 가장 가까운 정점을 추가하면서 최소 신장 트리를 확장한다.
  
  [다익스트라(Dijkstra)알고리즘](https://github.com/dngus1683/codingTestStudy/tree/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/dijkstra)과 유사하다. (다익스트라는 계속해서 더해진 가중치로 비교하고, 프림은 해당 정점 간의 가중치만 비교한다는 차이점이 있다.)
  
  ## Algorithm
  프림 알고리즘은 정점을 기준으로 최소 신장 트리를 구축한다. 시작 정점에서 출발하여 방문하지 않은 정점 중에서 가장 가까운 정점을 선택하여 최소 신장 트리에 추가한다. 이후 추가한 정점에서 출발하여 새로운 정점을 선택하고, 이를 반복하여 모든 정점을 포함하는 최소 신장 트리를 구축한다.
  
  1. 임의의 시작 정점을 선택한다.
  2. 선택한 정점과 인접한 간선 중에서 가장 작은 가중치를 갖는 간선을 선택한다.
  3. 선택한 간선의 도착 정점을 최소 신장 트리에 추가한다.
  4. 최소 신장 트리에 포함된 정점 집합을 확장하여 방문하지 않은 정점 중에서 가장 가까운 정점을 선택하고, 이를 반복한다.
  
  ## Pseudocode
  ```
  function Prim(graph):
      initialize an empty set for the minimum spanning tree (MST)
      initialize a priority queue to keep track of the minimum edge weights
      select an arbitrary starting vertex
      add the starting vertex to the MST

  while MST does not contain all vertices:
      for each vertex v adjacent to vertices in MST:
          if v is not already in MST:
              add edge (u, v) to the priority queue
      select the edge with the minimum weight from the priority queue
      add the destination vertex of the selected edge to the MST
  
  return MST

  ```
    
  ## Complexity
  + 시간 복잡도: O(E log V) (E: 간선 수, V: 정점 수)
  + 공간 복잡도: O(V + E) (그래프 표현 및 우선순위 큐에 필요한 공간)
  
  ## Implementation
  + C++
  ```cpp
  #include <iostream>
  #include <vector>
  #include <queue>
  #include <algorithm>
  
  #define MAX_V 10001
  #define INF 987654321
  
  using namespace std;
  
  typedef pair<int, int> pii;
  
  vector<pii> graph[MAX_V]; // 그래프를 인접 리스트로 표현
  bool visited[MAX_V]; // 정점의 방문 여부를 저장하는 배열
  int dist[MAX_V]; // 시작 정점으로부터의 최소 거리를 저장하는 배열
  
  int primMST(int start) {
      priority_queue<pii, vector<pii>, greater<pii>> pq; // 최소 힙을 사용하는 우선순위 큐
  
      fill(dist, dist + MAX_V, INF); // 최소 거리를 무한대로 초기화
      pq.push({0, start}); // 시작 정점을 우선순위 큐에 추가
      dist[start] = 0; // 시작 정점의 최소 거리를 0으로 설정
  
      int total_weight = 0; // MST의 총 가중치
  
      while (!pq.empty()) {
          int u = pq.top().second; // 현재 정점
          int d = pq.top().first; // 현재 정점까지의 최소 거리
          pq.pop();
  
          if (visited[u]) continue; // 이미 방문한 정점은 무시
          visited[u] = true; // 정점을 방문 표시
          total_weight += d; // 현재 정점까지의 최소 거리를 총 가중치에 추가
  
          // 현재 정점과 연결된 간선을 탐색
          for (pii edge : graph[u]) {
              int v = edge.first; // 인접 정점
              int w = edge.second; // 가중치
  
              // 방문하지 않은 정점이면서 현재까지의 최소 거리보다 짧은 경로가 존재한다면
              if (!visited[v] && w < dist[v]) {
                  dist[v] = w; // 최소 거리 갱신
                  pq.push({dist[v], v}); // 우선순위 큐에 추가
              }
          }
      }
  
      return total_weight; // MST의 총 가중치 반환
  }
  
  int main() {
      int V, E;
      cin >> V >> E;
  
      for (int i = 0; i < E; ++i) {
          int u, v, w;
          cin >> u >> v >> w;
          // 무방향 그래프이므로 양방향으로 간선 추가
          graph[u].push_back({v, w});
          graph[v].push_back({u, w});
      }
  
      int start_vertex = 1; // 임의의 시작 정점
      int mst_weight = primMST(start_vertex); // 프림 알고리즘을 통해 MST의 총 가중치 계산
  
      cout << "Total weight of MST: " << mst_weight << endl;
  
      return 0;
  }
  ```
