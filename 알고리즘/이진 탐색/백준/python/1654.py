# 랜선 자르기
# 길이가 제 각각인 랜선 K개가 있다. 이를 적절히 잘라서 N개 이상의 같은 길이의 랜선으로 만들 때, 최대 랜선 길이를 구하라.


# 내 답안1
import sys
import math

input = sys.stdin.readline

K, N = map(int, input().split())
li = [int(input()) for _ in range(K)]
ans = [0] * K

std = sum(li)//N

while True:
    ans = [li[i] // std for i in range(K)]
    if sum(ans) >= N and 0 not in ans:
        print(std)
        break
    mx = 0
    mn = -1
    idxx = 0
    idxn = 0
    for i in range(K):
        if mx <= (li[i] % std):
            mx = li[i] % std
            idxx = i
        if li[i] // std == 0 and mn <= li[i]:
            mn = li[i]
            idxn = i
    if mn == -1:
        std = math.floor(li[idxx] // (ans[idxx] + 1))
    else:
        std = mn



