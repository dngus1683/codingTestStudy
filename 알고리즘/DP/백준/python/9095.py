# 1, 2, 3 더하기
# 정수 N이 주어졌을 때, 순서 고려하여 1,2,3의 합으로 표현하는 경우의 수를 구하라.


# 내 답안1

import sys

input = sys.stdin.readline
T = int(input())
N = []
for _ in range(T):
    N.append(int(input()))

d = [0] * (max(N)+1)
d[0] = 1
d[1] = 1
d[2] = 2
for i in range(3, max(N)+1):
    d[i] = d[i-1] + d[i-2] + d[i-3]

for i in N:
    print(d[i])










# 답안 예시 - https://www.acmicpc.net/source/52744356
# T = int(input())
# a = [int(input()) for _ in range(T)]
# c = [0]*(11)
# c[1] = 1
# c[2] = 2
# c[3] = 4
# for i in range(4, 11):
#     c[i] = c[i-1] + c[i-2] + c[i-3]
# for b in a:
#     print(c[b])