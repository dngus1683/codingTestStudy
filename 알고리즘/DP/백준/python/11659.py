# 구간 합 구하기 4
# 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.


# 내 답안1
N, m = map(int, input().split())
li = list(map(int, input().split()))

ans = [0] * m
d = [0] * (N + 1)
d[1] = li[0]

for i in range(1, N):
    d[i+1] = d[i] + li[i]

for idx in range(m):
    i, j = map(int, input().split())
    ans[idx] = d[j] - d[i-1]

for i in range(m):
    print(ans[i])








# 답안 예시 - https://www.acmicpc.net/source/56177204
# import sys
# from itertools import accumulate      # accumulate()함수는 리스트의 누적합 리스트를 추출해주는 함수. 일반 for문을 쓰는 것 보다 속도가 빠르다.
#
# lines = map(bytes.split, sys.stdin.buffer.read().splitlines())
# n, m = next(lines)
# sums = list(accumulate(map(int, next(lines)), initial=0))
# sys.stdout.write('\n'.join(str(sums[int(j)] - sums[int(i) - 1]) for i, j in lines))
#
