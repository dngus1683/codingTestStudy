# 알고스팟
# NxM크기의 미로가 있다. (1,1)부터 출발하여 (N,M)까지 가는데 최소 몇개의 벽을 부셔야 하는지 구하라.


# 내 답안1
import sys
import heapq

INF = 987654321
input = sys.stdin.readline

m, n = map(int, input().split())
maze = [list(input()) for _ in range(n)]
graph = [[[]for _ in range(m+1)] for _ in range(n+1)]

dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        for dx, dy in dxdy:
            nx, ny = i + dx, j + dy
            if nx <= 0 or ny <= 0 or nx > n or ny > m:
                continue
            graph[i][j].append(((nx, ny), maze[nx-1][ny-1]))

def dijkstra(x,y, endx, endy):
    q = []
    heapq.heappush(q, (0, x, y))
    d = [[INF for _ in range(m+1)] for _ in range(n+1)]
    d[x][y] = 0
    while q:
        dist, nowx, nowy = heapq.heappop(q)
        if d[nowx][nowy] < dist:
            continue
        for (nx, ny), c in graph[nowx][nowy]:
            cost = d[nowx][nowy] + int(c)
            if cost < d[nx][ny]:
                d[nx][ny] = cost
                heapq.heappush(q, (0, nx, ny))
    return d[endx][endy]

print(dijkstra(1,1,n,m))