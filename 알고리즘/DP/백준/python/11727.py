# 2xn 타일링 2
# 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오. 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.


# 내 답안1
import sys

input = sys.stdin.readline
n = int(input())
d = [0] * 1001

d[1] = 1
d[2] = 3
d[3] = 5

# ak = a2 * ak-2 + 2*ak-3
for i in range(4, n+1):
    d[i] = d[2]*d[i-2]+2*d[i-3]

print(d[n]%10007)
