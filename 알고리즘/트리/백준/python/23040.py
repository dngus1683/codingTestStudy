# # 누텔라 트리
# # 누텔라 경로: 검은색 - 빨간색 - 빨간색 - ... 처럼 처음 시작이 검은색이고 이후 빨간색으로만 이어진 경로를 뜻함.
# # 한 그래프의 정보가 주어질 때, 누텔라 경로의 개수를 구하라.
#
#
# # 내 답안1
# # BFS
# import sys
# from collections import deque
#
# input = sys.stdin.readline
#
# N = int(input())
# graph = [[] for _ in range(N+1)]
# for _ in range(N-1):
#     a, b = map(int, input().split())
#     graph[a].append(b)
#     graph[b].append(a)
# status = input()
#
# def bfs(start):
#     cnt = 0
#     queue = deque()
#     queue.append(start)
#     visit = []
#     while queue:
#         v = queue.popleft()
#         visit.append(v)
#         if status[v-1] == 'R':
#             cnt += 1
#         for u in graph[v]:
#             if status[u-1] == 'R' and u not in visit:
#                 queue.append(u)
#     return cnt
#
# cnt = 0
# for i in range(len(status)):
#     if status[i] == 'B':
#         cnt += bfs(i+1)
#
# print(cnt)


# 내 답안2
# DFS
# import sys
#
# input = sys.stdin.readline
#
# N = int(input())
# graph = [[] for _ in range(N+1)]
# for _ in range(N-1):
#     a, b = map(int, input().split())
#     graph[a].append(b)
#     graph[b].append(a)
# status = input()
#
# visited = []
# point = [0 for _ in range(N+1)]
# def dfs(x):
#     visited.append(x)
#     cnt = 0
#     for u in graph[x]:
#         if status[u-1] == 'R' and u not in visited:
#             point[u] = dfs(u)
#         cnt += point[u]
#     return cnt + 1
#
# ans = 0
# for i in range(len(status)):
#     if status[i] == 'B':
#         ans += dfs(i+1) - 1 # 마지막 블랙으로 돌아왔을 때 1이 더해지는 것 보정
#
# print(ans)


# 내 답안3
# 크루스칼?
import sys

input = sys.stdin.readline

N = int(input())
tu = []
graph = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    tu.append((a, b))
    graph[a].append(b)
    graph[b].append(a)

status = input()
parent = [i for i in range(N+1)]
cnt = [1 for _ in range(N+1)]

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union(a, b):
    a_parent = find_parent(a)
    b_parent = find_parent(b)
    if a_parent != b_parent:
        parent[b] = a_parent
        cnt[a_parent] += cnt[b_parent]

for a,b in tu:
    if status[a-1] == 'R' and status[b-1] == 'R':
        union(a, b)

ans = 0
for i in range(1, N+1):
    if status[i-1] == 'R':
        continue
    for j in graph[i]:
        if status[j-1] == "R":
            ans += cnt[find_parent(j)]

print(ans)