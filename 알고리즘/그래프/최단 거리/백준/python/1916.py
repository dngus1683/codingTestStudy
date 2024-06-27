# 최소비용 구하기
# N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다.
# 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라.
# 도시의 번호는 1부터 N까지이다.

# 내 답안1
import sys

INF = 987654321

input = sys.stdin.readline
n = int(input())
m = int(input())

graph = [[INF for _ in range(n+1)] for _ in range(n+1)]
v = set([i for i in range(1, n + 1)])
prev = [0 for i in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)

tarA, tarB = map(int, input().split())

def dijkstra(r, arv):
    s = set()
    d = [INF for _ in range(n+1)]
    d[r] = 0

    while s != v:
        u = extract_min(v-s, d)
        s = s | {u}
        for i in range(1, n+1):
            if graph[u][i] == 'x':
                continue
            if i in (v-s) and d[u] + graph[u][i] < d[i]:
                d[i] = d[u] + graph[u][i]
                prev[i] = u
    return d[arv]

def extract_min(q, d):
    min = INF
    idx = 0
    for i in q:
        if min >= d[i]:
            min = d[i]
            idx = i
    return idx


print(dijkstra(tarA, tarB))


# import sys
#
# INF = 987654321
#
# n = int(sys.stdin.readline().rstrip())
# m = int(sys.stdin.readline().rstrip())
#
# graph = [[INF for _ in range(n+1)] for _ in range(n+1)]
# for i in range(m):
#     a, b, c = map(int, sys.stdin.readline().rstrip().split())
#     graph[a][b] = min(graph[a][b], c)
#
# start, end = map(int, sys.stdin.readline().rstrip().split())
#
# def dijkstra(start, end):
#     dist = [INF for _ in range(n+1)]
#     dist[start] = 0
#     visited = [False for _ in range(n+1)]
#
#     for i in range(n):
#         min_dist = INF
#         now = -1
#         for j in range(1, n+1):
#             if not visited[j] and dist[j] < min_dist:
#                 min_dist = dist[j]
#                 now = j
#
#         if now == -1:
#             break
#
#         visited[now] = True
#         for j in range(1, n+1):
#             cost = graph[now][j]
#             if cost != INF:
#                 dist[j] = min(dist[j], dist[now]+cost)
#
#     return dist[end]
#
# print(dijkstra(start, end))
