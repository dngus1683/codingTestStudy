# LCS 3
# 문자열 3개의 LCS 길이를 구하라.


# 내 답안1
import sys

input = sys.stdin.readline
A = input()
B = input()
C = input()

d = [[[0 for _ in range(len(A))] for _ in range(len(B))] for _ in range(len(C))]

for i in range(0, len(C)-1):
    for j in range(0, len(B)-1):
        for k in range(0, len(A)-1):
            if A[k] == B[j] == C[i]:
                d[i+1][j+1][k+1] = d[i][j][k] + 1
            else:
                d[i+1][j+1][k+1] = max(d[i][j+1][k+1], d[i+1][j][k+1], d[i+1][j+1][k])

print(d[-1][-1][-1])

'''
afbscgdgeg
abfgregrf
fgrabrefecdef
'''