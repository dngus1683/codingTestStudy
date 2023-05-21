# 점프
# N x N 칸에 각각 숫자가 적혀있다. (0,0)에서 출발하여 (N-1,N-1)까지 가는데 각 타일의 숫자만큼 오른쪽 또는 아래로 이동할 수 있다.
# 이때 도착점에 도착하는 경우의 수를 구하라.


# 내 답안1
import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
mat = [list(map(int, input().split())) for _ in range(N)]


dxdy = [(1,0), (0,1)]

def bfs(x,y):
    queue = deque()
    queue.append((x,y))
    visited = []
    ans = 0

    while queue:
        x, y = queue.popleft()
        for dx, dy in dxdy:
            if mat[x][y] == 0:
                continue
            nx = x + dx * mat[x][y]
            ny = y + dy * mat[x][y]
            if (nx == N - 1 and ny == N - 1) or (nx,ny) in visited:
                if (x,y) not in visited:
                    visited.append((x,y))
                ans += 1
                continue
            if nx >= N or ny >= N or nx < 0 or ny < 0:
                continue
            queue.append((nx,ny))
    return ans

print(bfs(0,0))




# 내 답안2
# import sys
#
# input = sys.stdin.readline
# N = int(input())
# mat = [list(map(int, input().split())) for _ in range(N)]
# d = [[0 for _ in range(N)] for _ in range(N)]
# d[0][0] = 1
#
#
# i = 0
# j = 0
# while N-i > 0:
#     while N-j > 0:
#         if (i,j) == (N-1,N-1):
#             break
#         if i + mat[i][j] < N:
#             d[i+mat[i][j]][j] += d[i][j]
#         if j + mat[i][j] < N:
#             d[i][j+mat[i][j]] += d[i][j]
#         j += 1
#     j = 0
#     i += 1
#
# print(d[N-1][N-1])



# 내 답안3
# import sys
#
# input = sys.stdin.readline
# N = int(input())
# mat = [list(map(int, input().split())) for _ in range(N)]
# d = [[0 for _ in range(N)] for _ in range(N)]
# d[0][0] = 1
#
#
# for i in range(N):
#     for j in range(N):
#         if (i,j) == (N-1,N-1):
#             continue
#         if i + mat[i][j] < N:
#             d[i+mat[i][j]][j] += d[i][j]
#         if j + mat[i][j] < N:
#             d[i][j+mat[i][j]] += d[i][j]
#
# print(d[N-1][N-1])


