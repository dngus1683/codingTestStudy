# 파티
# N개의 마을에 학생이 각 한 명씩 있음. 모두들 특정 마을로 모이기로 함.
# 학생들이 모였다가 다시 본인들의 마을로 돌아가야 한다고 할 때, 가장 많은 시간을 소비하는 학생을 구하라.


# 내 답안1
import sys
import heapq

input = sys.stdin.readline

INF = 987654321

N, M, X = map(int, input().split())
graph = [[]for _ in range(N+1)]
for i in range(M):
    a,b,c = map(int, input().split())
    graph[a].append((b, c))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    d = [INF for _ in range(N + 1)]
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if d[now] < dist:
            continue
        for b, c in graph[now]:
            cost = d[now] + c
            if cost < d[b]:
                d[b] = cost
                heapq.heappush(q, (cost, b))
    return d

ans = 0
for i in range(1, N+1):
    backward = dijkstra(X)
    forward = dijkstra(i)
    ans = max(ans, backward[i]+ forward[X])

print(ans)