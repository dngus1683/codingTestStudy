# 평범한 배낭
# 가방의 최대 허용 무게는 K 이며, 각 물건들은 w의 무게와 v의 가치를 지닌다고 할 때, 가방에 넣을 수 있는 최대 가치는 얼마인지 구하라.


# 내 답안1
import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline
n, k = map(int, input().split())
li = [list(map(int, input().split())) for _ in range(n)]

li.sort()

dli = [0 for _ in range(10**7)]

def dp(d, idx, pre):
    d[pre + li[idx][0]] = max(d[pre + li[idx][0]], d[pre] + li[idx][1])
    for i in range(idx+1, n):
        dp(d, i, pre + li[idx][0])

for i in range(n):
    dp(dli, i, 0)

for i in range(k, -1, -1):
    if dli[i] != 0:
        print(dli[i])
        break

