# 노드사이의 거리
# N개의 노드로 이루어진 트리가 주어지고 M개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.


# 내 답안1
# bfs
# import sys
# from collections import deque
#
# INF = 987654321
# input = sys.stdin.readline
#
# N, M = map(int, input().split())
# graph = [[] for _ in range(N+1)]
# q = []
#
# for i in range(N-1):
#     a, b, c = map(int, input().split())
#     graph[a].append((b, c))
#     graph[b].append((a, c))
#
# for i in range(M):
#     a, b = map(int, input().split())
#     q.append((a,b))
#
# def bfs(start, end):
#     queue = deque()
#     queue.append((start, 0))
#     visited = [0 for _ in range(N+1)]
#     while queue:
#         x, d = queue.popleft()
#         if x == end:
#             return d
#         visited[x] = 1
#         for nx, cost in graph[x]:
#             if visited[nx] != 1:
#                 queue.append((nx, cost + d))
#
# for s, e in q:
#     print(bfs(s,e))


# 내 답안2
# dfs

import sys

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[]for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
q = []

for _ in range(N-1):
    a,b,c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

for _ in range(M):
    a, b = map(int, input().split())
    q.append((a,b))

def dfs(x, end, c):
    if x == end:
        print(c)
        return
    visited[x] = 1
    for nx, cost in graph[x]:
       if visited[nx] == 0:
           dfs(nx, end, c + cost)

for a, b in q:
    visited = [0 for _ in range(N + 1)]
    dfs(a,b,0)