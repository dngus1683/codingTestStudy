# 동물원
# 2 x N 크기의 동물원이 있다. 여기에 사자를 넣으려고 하는데 사자끼리 맞닿아 있으면 안된다. 사자를 배치하는 경우의 수를 구하여라


# 내 답안1
import sys

input = sys.stdin.readline
N = int(input())

d = [1 for _ in range(N+1)]

d[1] = 3
for i in range(2, N+1):
    d[i] = (2 * d[i-1] + d[i-2]) % 9901

print(d[N])