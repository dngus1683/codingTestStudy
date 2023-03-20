# 계단 오르기
# 각 계단 별로 점수가 있는데, 끝까지 올랐을 때 밟았던 계단의 점수의 합이 가장 높은 경우를 구하라.
# 이때, 계단은 한칸, 두칸만 이동할 수 있고 연속으로 세 계단을 오를 수 없다.


#내 답안1
import sys

input = sys.stdin.readline
n = int(input())
step = [0]
for _ in range(n):
    step.append(int(input()))
d = [[0,0] for _ in range(n+1)]

d[1] = [step[1], step[1]]
for i in range(2,n+1):
    d[i][0] = step[i] + max(d[i-2])
    d[i][1] = step[i] + d[i-1][0]

print(max(d[n]))












# 답안 예시
# import sys
# input = sys.stdin.readline
# n = int(input())
# dp = [0]*301
# scores = [0]*301
#
# for i in range(n):
#     scores[i+1] = int(input())
#
# dp[1] = scores[1]
# dp[2] = dp[1] + scores[2]
#
# for i in range(3, n+1):
#     dp[i] = max(dp[i-2]+scores[i],dp[i-3]+scores[i-1]+scores[i])
#
# print(dp[n])