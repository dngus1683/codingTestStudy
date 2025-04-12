# 트리의 지름
# 트리는 사이클이 없는 무방향 그래프다. 임의의 두 노드를 양쪽으로 쫙 잡아당겼을 때 가장 긴 경우가 있을 것. 이 두 노드 사이의 경로의 길이를 트리의 지름이라 한다.
# 다시 말하자면 트리에 존재하는 가장 긴 경로다.
# 각 노드들 사이의 간선에 가중치가 있다고 가정할 때, 주어진 트리의 지름을 구하라.


# 내 답안1
# 크루스칼
# import sys
#
# input = sys.stdin.readline
#
# n = int(input())
#
# graph = []
# son = [[(0, 0)] for _ in range(n+1)]
#
# for _ in range(n-1):
#     a, b, c = map(int, input().split())
#     graph.append((a, b, c))
#
# def unioin(a, b, c):
#     if son[a] == [(0, 0)]:
#         son[a] = [((max(son[b])[0] + c), b)]
#     else:
#         son[a].append(((max(son[b])[0] + c), b))
#     son[a].sort(key=lambda x: x[1])
#
#
# graph.sort(key=lambda x: -x[1])
# print(graph)
# for a, b, c in graph:
#     unioin(a, b, c)
#
# m = 0
# for i in range(1, n+1):
#     m = max(sum(x[0] for x in son[i]), m)
# print(m)


# 내 답안2
# DFS
import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
graph = [[]for _ in range(n+1)]
son = [[0, 0] for _ in range(n+1)]

for _ in range(n-1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[a].sort()

visited = []
def dfs(x):
    visited.append(x)
    for b, c in graph[x]:
        if b not in visited:
            dfs(b)
    #         son[x].append(max(son[b])+c)
    # son[x].sort(reverse=True)
            if son[x][0] <= son[x][1]:
                son[x][0] = max(son[x][0], max(son[b]) + c)
            else:
                son[x][1] = max(son[x][1], max(son[b]) + c)

dfs(1)

m = 0
for i in range(1, n+1):
    if len(son[i]) > 1:
        m = max(son[i][0]+son[i][1], m)

print(m)