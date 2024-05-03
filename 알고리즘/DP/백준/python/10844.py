# 쉬운 계단 수
# 45656이란 수를 보자.
# 이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
# N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.
# 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

# 내 답안1

import sys

input = sys.stdin.readline

n = int(input())

a = [[0] * 10] * (n+1)

a[1] = [0,1,1,1,1,1,1,1,1,1]

for i in range(2, n+1):
    li = a[i-1][:]
    a[i][0] = a[i-1][1]
    a[i][9] = a[i-1][8]
    for j in range(1, 9):
        a[i][j] = li[j-1]+li[j+1]

print(sum(a[n])%1000000000)


















# 답안 예시 - https://www.acmicpc.net/source/53935968
# 뭔자 모르겠음
# a=1
# b=c=d=e=2
#
# for _ in [0]*(int(input())-1):
#     a,b,c,d,e = b,a+c,b+d,c+e,d+e
# print((a+b+c+d+e)%10**9)