# 벽 부수고 이동하기
# n x m 크기의 맵 중 (1,1)에서 시작을 해서 (n,m) 까지의 최단경로를 구하는데, 벽 하나까지만 부수는 것이 허용된다.

# 내 답안1
from collections import deque

n, m = map(int, input().split())
graph = []                          # (방문 여부, 이동 횟수) & 벽 뚫은 횟수  [이동, 벽]
block = [[0] * m for _ in range(n)] # 벽 위치. 이 정보는 수정하지 않음

for i in range(n):
    graph.append(input())
    graph[i] = list(map(list, graph[i]))
    for j in range(m):
        graph[i][j][0] = int(graph[i][j][0])
        graph[i][j].append(0)
        block[i][j] = graph[i][j][0]

dir = [(-1,0), (1,0), (0,-1), (0,1)]

def bfs(x,y):
    arrive = 0      # 도착 지점에 도달 여부 flag
    queue = deque()
    queue.append((x, y))
    while queue:
        x, y = queue.popleft()
        if x == n - 1 and y == m - 1:
            arrive = 1
            break
        for d in dir:
            px, py = x + d[0], y + d[1]
            if px < 0 or py < 0 or px >= n or py >= m: continue
            if block[px][py] == 0:
                if graph[px][py] == [0, 0]:     # 뚫린 길인데 처음 와보는 곳일 때
                    graph[px][py] = [graph[x][y][0] + 1, graph[x][y][1]]
                    queue.append((px, py))
                elif graph[px][py][1] == 1 and graph[x][y][1] == 0:     # 뚫린 길인데 한번 벽을 뚫고 와본 곳일 때
                    graph[px][py] = [graph[x][y][0] + 1, graph[x][y][1]]
                    queue.append((px, py))

            elif block[px][py] == 1 and graph[x][y][1] == 0:    # 벽인데 한번도 벽을 뚫어본 적이 없을 때
                graph[px][py] = [graph[x][y][0]+1, graph[x][y][1]+1]
                queue.append((px, py))
    if arrive:
        return graph[n-1][m-1][0] + 1
    else:
        return -1

print(bfs(0,0))











# 답안 예시 - https://www.acmicpc.net/source/56162226

# DFS ?
# import sys
# input = sys.stdin.readline
# N, M = map(int, input().split())
# A = [input().strip() for _ in range(N)]
#
# V = [[[True]*M for _ in range(N)],  [[True]*M for _ in range(N)]]
#
# def add(e):
#     r = []
#     x,y,tf = e
#     def F(nx, ny, tf):
#         if A[nx][ny] == "0":
#             if tf == 0 and not V[tf][nx][ny]: return
#             if tf == 1 and (not V[0][nx][ny] or not V[1][nx][ny]): return
#             r.append((nx,ny,tf))
#             V[tf][nx][ny] = False
#         elif A[nx][ny] == "1" and tf == 0 and V[1][nx][ny]:
#             r.append((nx,ny,1))
#             V[1][nx][ny] = False
#     if x > 0: F(x-1, y, tf)
#     if y > 0: F(x, y-1, tf)
#     if x < N-1: F(x+1, y, tf)
#     if y < M-1: F(x, y+1, tf)
#     return r
#
# def solve():
#     cnt = 1
#     S = [(0,0,0)]
#     while S:
#         T = []
#         for s in S:
#             if s[0] == N-1 and s[1] == M-1: return cnt
#             T += add(s)
#         cnt += 1
#         S = T
#     return -1
#
# print(solve())