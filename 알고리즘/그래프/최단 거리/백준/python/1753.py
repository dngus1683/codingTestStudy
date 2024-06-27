# 최단경로
# 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.


# 내 답안1
# import sys
#
# input = sys.stdin.readline
# INF = 987654321
#
# v, e = map(int, input().split())
# start = int(input())
# vl = set([i for i in range(1, v+1)])
# graph = [[] for _ in range(v+1)]
#
# for i in range(e):
#     a,b,c = map(int, input().split())
#     graph[a].append((b, c))
#
# def dijkstra(r):
#     s = set()
#     d = [INF for _ in range(v+1)]
#     d[r] = 0
#     while s != vl:
#         u = smallest(vl-s, d)
#         s = s | {u}
#         for b, c in graph[u]:
#             if b in (vl-s) and d[u] + c < d[b]:
#                 d[b] = d[u] + c
#     return d
#
# def smallest(q, d):
#     min_val = INF
#     idx = 0
#     for i in q:
#         if d[i] <= min_val:
#             min_val = d[i]
#             idx = i
#     return idx
#
# ans = dijkstra(start)
# for i in range(1, len(ans)):
#     if ans[i] == INF:
#         print('INF')
#     else:
#         print(ans[i])


# 내 답안2
import heapq
import sys

input = sys.stdin.readline

INF = 987654321

v, e = map(int, input().split())
start = int(input())
vl = set([i for i in range(1, v+1)])
graph = [[] for _ in range(v+1)]
d = [INF for _ in range(v+1)]

for i in range(e):
    a,b,c = map(int, input().split())
    graph[a].append((b, c))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if d[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < d[i[0]]:
                d[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)
for i in range(1, len(d)):
    if d[i] == INF:
        print('INF')
    else:
        print(d[i])
