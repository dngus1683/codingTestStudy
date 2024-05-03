# 배
# 항구에는 N개의 크레인이 있고 무게 제한이 있으며 1분에 박스 하나씩 배에 실을 수 있으며 모든 크레인은 동시에 움직임.
# 모든 박스 M개를 배로 옮기는데 드는 시간의 최솟값을 구하라.


# 내 답안1 - 시간초과 실패
# import sys
#
# input = sys.stdin.readline
#
# N = int(input())
# Nli = list(map(int, input().split()))
# M = int(input())
# Mli = list(map(int, input().split()))
#
# Nli.sort(reverse=True)
# Mli.sort(reverse=True)
# cnt = 0
#
# if Nli[0] < Mli[0]:
#     print(-1)
# else:
#     while Mli:
#         for i, n in enumerate(Nli):
#             for j, m in enumerate(Mli):
#                 if n >= m:
#                     del Mli[j]
#                     break
#         cnt += 1
#     print(cnt)


# 내 답안2 - 6%, 각 pivot마다 개수를 세어 그 배열을 활용하여 문제를 해결하려 함.
# import sys
# import math
#
# input = sys.stdin.readline
#
# N = int(input())
# Nli = list(map(int, input().split()))
# M = int(input())
# Mli = list(map(int, input().split()))
#
# li = [0] * N
#
# Nli.sort()
# Mli.sort()
# cnt = 0
#
# if Nli[-1] < Mli[-1]:
#     print(-1)
# else:
#     for i, pivot in enumerate(Nli):
#         num = 0
#         for j in range(sum(li[:i]), M):
#             if pivot >= Mli[j]:
#                 num += 1
#             else:
#                 break
#         li[i] = num
#
#     li = li[N-1::-1]
#     li.append(0)
#
#     for i in range(N-1):
#         for j in range(i+1, N):
#             if (li[i] < li[j] and li[i] >= li[j+1]):
#                 s = sum(li[i:j+1])
#                 n = j-i+1
#                 for k in range(i, j+1):
#                     li[k] = math.ceil(s/n)
#                     s = s - li[k]
#                     n -= 1
#                 break
#     print(max(li))


# 내 답안3 - 내 답안1에서 Mli이 빈 배열인 경우와 이미 Nli 요소가 남아있는 Mli의 요소들보다 작을 경우 반복문을 나오게 하여 시간초과를 해결.
# 백준 답안 예시들은 평균적으로 40ms가 소요된 반면, 내 답안3은 1500ms가 소요됨.
# 정답처리는 되었지만 비효율적.
import sys

input = sys.stdin.readline

N = int(input())
Nli = list(map(int, input().split()))
M = int(input())
Mli = list(map(int, input().split()))

Nli.sort(reverse=True)
Mli.sort(reverse=True)
cnt = 0

if Nli[0] < Mli[0]:
    print(-1)
else:
    li = [0] * N
    while Mli:
        for i, n in enumerate(Nli):
            if not Mli or n < min(Mli):
                break
            for j in range(len(Mli)):
                if n >= Mli[j]:
                    del Mli[j]
                    li[i] = j
                    break
        cnt += 1
    print(cnt)





# 답안 예시 - https://www.acmicpc.net/source/54360331
# 내 답안2와 유사한 접근, 구현은 훨씬 간단하다.
# import math
#
# N = int(input())
# L = sorted(list(map(int, input().split())))
# M = int(input())
# W = sorted(list(map(int, input().split())))
# answer = M / N
#
# if L[-1] < W[-1]:
#     answer = -1
# else:
#     idx = 0
#     for i in range(N - 1):
#         for j in range(idx, M):
#             if W[j] > L[i]:
#                 idx = j
#                 l = (M - j) / (N - i - 1)
#                 answer = max(answer, l)
#                 break
# print(math.ceil(answer))
