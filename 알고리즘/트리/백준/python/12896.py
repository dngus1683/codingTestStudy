# 스크루지 민호
# n개의 도시가 주어지고 모든 도시가 이어지도록 n-1개의 양방향 도로 정보가 주어진다.
# 소방서를 지으려고 할 때 소방서 위치에서 가장 먼 도시까지의 거리의 최솟값을 구하라.


# 내 답안1
import sys
import math

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n+1)]
son = [[0, 0] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * (n+1)
def dfs(x):
    visited[x] = True
    for b in graph[x]:
        if visited[b] == False:
            dfs(b)
            if son[x][0] <= son[x][1]:
                son[x][0] = max(son[x][0], max(son[b]) + 1)
            else:
                son[x][1] = max(son[x][1], max(son[b]) + 1)

dfs(1)

m = 0
idx = 0
for i in range(1, n+1):
    son[i].sort(reverse=True)
    if len(son[i]) > 1:
        if son[i][0]+son[i][1] >= m:
            idx = i
            m = son[i][0]+son[i][1]
print(math.ceil(m/2))


# 답안 예시 - https://www.acmicpc.net/source/61197948
# import sys
# import math
#
# def bfs(x):
#     visited = [-1] * (N+1)
#     visited[x] = 0
#     q = [x]
#     while q:
#         now = q.pop()
#         for i, cost in tree[now]:
#             if visited[i] == -1:
#                 visited[i] = visited[now] + cost
#                 q.append(i)
#     return visited
#
# def main():
#     global tree, N
#     I = sys.stdin.readline
#     N = int(I())
#     tree = [[] for _ in range(N+1)]
#     for _ in range(N-1):
#         a, b = map(int,I().split())
#         tree[a].append((b, 1))
#         tree[b].append((a, 1))
#     res1 = bfs(1)
#     idx = res1.index(max(res1))
#     print(math.ceil(max(bfs(idx))/2))
#
# if __name__ == "__main__":
#     main()