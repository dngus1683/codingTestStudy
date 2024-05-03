# 숨바꼭질 3
# N에서 K로 가는데 걸리는 최단 시간을 구하라.
# 이동은 총 두가지 방법이 있는데 1)1초 동안 X-1, X+1 로 이동. 2) 0초 동안 2*X로 이동


# 내 답안1
import sys
import heapq

INF = 987654321
input = sys.stdin.readline

N, K = map(int, input().split())

graph = [[]for _ in range(max(N,K)*2 + 1)]

for i in range(max(N,K)*2 + 1):
    if i == 0:
        graph[i].append((i+1, 1))
    else:
        graph[i].append((i-1, 1))
        graph[i].append((i+1, 1))
        graph[i].append((2*i, 0))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    d = [INF for _ in range(max(N,K)*2 + 1)]
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if dist > d[now]:
            continue
        for b,c in graph[now]:
            if b >= max(N,K)*2 + 1:
                continue
            cost = c + d[now]
            if cost < d[b]:
                d[b] = cost
                heapq.heappush(q, (cost, b))
    return d[K]

print(dijkstra(N))






# 답안 예시 - https://www.acmicpc.net/source/77104287
# import sys

# def search(N,K):
#     if K <= N: return N - K
#     elif N == 0: return 1 + search(N+1,K)
#     elif K%2 == 0: return min(K-N,search(N,K//2))
#     else: return 1 + min(search(N,K-1),search(N,K+1))

# N, K = map(int,sys.stdin.readline().split())
# print(search(N,K))