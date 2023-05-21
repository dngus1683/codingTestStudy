# LCS 2
# 최대 부분수열을 구하고 그 길이도 출력하라.


# 내 답안1
import sys

input = sys.stdin.readline
A = input()
B = input()

d = [[0 for _ in range(len(A))] for _ in range(len(B))]
LCS = ['' for _ in range(max(len(A), len(B)))]

for i in range(0, len(B)-1):
    for j in range(0, len(A)-1):
        if A[j] == B[i]:
            d[i+1][j+1] = d[i][j] + 1
        else:
            d[i+1][j+1] = max(d[i][j+1], d[i+1][j])

A_l = len(A)-2
for i in range(len(B)-1, -1, -1):
    for j in range(A_l, -1, -1):
        if d[i][j] == d[i][j+1] - 1:
            LCS[d[i][j+1]] = A[j]
            A_l = j
            break


print(d[-1][-1])
print(''.join(LCS[1:d[-1][-1]+1]))


















# 답안 예시1
# s1 = input()
# s2 = input()
#
# dp = []
# for c in s2:
#     prv = '', -1
#     for i, cur in enumerate(dp):
#         for j in range(prv[1]+1, cur[1]):
#             if s1[j] == c:
#                 dp[i] = (prv[0]+c, j)
#                 break
#         prv = cur
#     for j in range(prv[1] + 1, len(s1)):
#         if s1[j] == c:
#             dp.append((prv[0]+c, j))
#             break
#
# if dp:
#     print(len(dp))
#     print(dp[-1][0])
# else:
#     print(0)