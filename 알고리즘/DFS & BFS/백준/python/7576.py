# 토마토
# M x N 상자에 토마토의 정보가 들어가 있다. (토마토가 없으면 -1, 토마토가 안익었으면 0, 토마토가 익었으면 1)
# 하루가 지나면 익은 토마토는 상하좌우에 인접해 있는 안익은 토마토에게 영향을 줘 익게 한다.
# 상자 안의 모든 토마토가 익을려면 며칠일 걸릴까?

# 내 답안1
from collections import deque

m, n = map(int, input().split())
graph = []
first = []      # 초기 익은 토마토 index 정보

for i in range(n):
        graph.append(list(map(int, input().split())))
        for j in range(m):
            if graph[i][j] == 1:
                first.append((i,j))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

day = 2


def bfs(li):
    global day    # why?
    queue = deque()
    for tu in li:
        queue.append(tu)
    while queue:
        x, y = queue.popleft()
        if graph[x][y] == day:
            day += 1            # queue에서 뺴는 토마토의 날짜가 다르면 올려주기
        for i in range(4):
            px, py = x + dx[i], y + dy[i]
            if px >= n or py >= m or px < 0 or py < 0: continue     # 배열 범위에서 벗어나는 경우
            if graph[px][py] == 0:
                graph[px][py] = day     # 각 토마토에는 본인이 몇일 차에 익었는지 저장됨
                queue.append((px, py))
bfs(first)

if any(0 in l for l in graph):
    day = -1
elif all(0 in l for l in graph):
    day = 0
else:
    day -= 2        # bfs()를 거쳐 최종적으로 나온 day값은 가장 마지막 일에 +1된 값이며 이 문제는 초기 상태를 1일차로 고려하지 않으므로
                    # 이 둘을 고려하여 -2를 뺀다.

print(day)













# 답안 예시 - https://www.acmicpc.net/source/59278126
# from sys import stdin

# def solution(N, M, tomato):
#     queue = []
#     direct = [(-1,0),(0,1),(1,0),(0,-1)]
#     dist = 0
#     for i in range(M):
#         for j in range(N):
#             if tomato[i][j] == 1:
#                 queue.append((i,j))

#     while queue:
#         dist += 1
#         tmp = []
#         for x, y in queue:
#             for dx, dy in direct:
#                 nx, ny = x + dx, y + dy
#                 if nx < 0 or nx >= M or ny < 0 or ny >= N:
#                     continue
#                 if not tomato[nx][ny]:
#                     tmp.append((nx,ny))
#                     tomato[nx][ny] = 1
#         queue = tmp

#     for i in tomato:
#         for j in i:
#             if not j:
#                 return -1
#     return dist - 1

# N, M = map(int, stdin.readline().split())
# tomato = [list(map(int, stdin.readline().split())) for _ in range(M)]
# print(solution(N, M, tomato))