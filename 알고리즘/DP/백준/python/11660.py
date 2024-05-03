# 구간 합 구하기 5
# N x N 크기의 표에 숫자가 있을 때, (x1, y1) ~ (x2, y2)에 해당하는 모든 숫자들의 합을 구하라.(M번)


# 내 답안1
import sys
from itertools import accumulate

input = sys.stdin.readline

N, M = map(int, input().split())
mat = [[0]*N for _ in range(N)]
mat_sum = mat[:]
ans = [0] * M

for i in range(N):
    mat[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(N):
        if i == 0 and j == 0:
            mat_sum[0][0] = mat[0][0]
        elif i == 0:
            mat_sum[i][j] = mat_sum[i][j-1] + mat[i][j]
        elif j == 0:
            mat_sum[i][j] = mat_sum[i-1][j] + mat[i][j]
        else:
            mat_sum[i][j] = mat_sum[i][j-1] + mat_sum[i-1][j] + mat[i][j] - mat_sum[i-1][j-1]

for i in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    if x1 == 1 and y1 == 1:
        ans[i] = mat_sum[x2 - 1][y2 - 1]
    elif x1 == 1:
        ans[i] = mat_sum[x2 - 1][y2 - 1] - mat_sum[x2 - 1][y1 - 2]
    elif y1 == 1:
        ans[i] = mat_sum[x2 - 1][y2 - 1] - mat_sum[x1 - 2][y2 - 1]
    else:
        ans[i] = mat_sum[x2 - 1][y2 - 1] - mat_sum[x1 - 2][y2 - 1] - mat_sum[x2 - 1][y1 - 2] + mat_sum[x1 - 2][y1 - 2]

for i in range(M):
    print(ans[i])








# 답안 예시 - https://www.acmicpc.net/source/44777449
# import sys; input = sys.stdin.readline
# from itertools import accumulate
# from operator import add
#
# n, m = map(int, input().split())
#
# sums = [[0 for _ in range(n+1)]]
#
# for i in range(1, n+1):
#     sums.append(list(map(add, [0] + list(accumulate(map(int, input().split()))), sums[i-1])))
#
# for _ in range(m):
#     x1, y1, x2, y2 = map(int, input().split())
#     print(sums[x2][y2] - sums[x1-1][y2] - sums[x2][y1-1] + sums[x1-1][y1-1])
