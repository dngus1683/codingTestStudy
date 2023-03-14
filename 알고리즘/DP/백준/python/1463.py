# 1로 만들기
# 정수 x에 대해 할 수 있는 계산은 세가지(1. 3으로 나누기, 2. 2로 나누기, 3. 1 빼기). 정수 N이 주어졌을 때, 1로 만드는 연산 횟수의 최솟값을 구하라.


# 내 답안1
import sys
input = sys.stdin.readline

N = int(input())

d = [0] * (N+1)

for i in range(2, N+1):
    d[i] = d[i-1] + 1 # 1 빼기
    if i % 2 == 0:
        d[i] = min(d[i],d[i//2]+1)  # 2 나누기
    if i % 3 == 0:
        d[i] = min(d[i],d[i//3]+1)  # 3 나누기

print(d[N])



