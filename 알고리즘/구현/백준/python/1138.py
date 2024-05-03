# 한 줄로 서기
# 1 ~ N 까지의 키를 가진 사람 N명이 가로로 줄을 선다.
# 각자는 왼쪽에 본인보다 키가 큰 사람이 몇명인지 안다.
# 해당 정보를 통해서 어떻게 줄을 서있는지 구하라.


# 내 답안1
# 메모리 초과 - permutations 결과를 list화 하지 않고 바로 for문에 사용하는 방법으로 해결.
# 시간: 668ms
# import sys
# from itertools import permutations
# input = sys.stdin.readline
#
# N = int(input())
# li = list(map(int, input().split()))
#
# flag = 0
#
# for tu in permutations(list(range(1, N+1)), N):
#     if li[tu[0]-1] != 0:
#         continue
#     for i in range(len(tu)):
#         cnt = 0
#         for j in range(i-1, -1, -1):
#             if tu[j] > tu[i]:
#                 cnt += 1
#         if li[tu[i]-1] != cnt:
#             flag = 0
#             break
#         else:
#             flag += 1
#     if flag == N:
#         print(*tu)          # *: args, **: kwargs
#         break


















# 답안 예시1 - https://www.acmicpc.net/source/52835413
# 나보다 큰 수가 왼쪽에 k개 있다. = 나는 k 번째에 위치해 있다.
# 시간: 36ms - 내 답안1보다 약 18배 빠름
N=int(input())
h=list(map(int,input().split()))[::-1]  # 입력 받은 숫자를 반대로 정렬
o=[]
for i in h:
    o.insert(i,N)   # insert(i,N): N을 i index 자리에 추가. 만약 그 자리에 이미 원소가 있다면 해당 원소를 오른쪽으로 옮기고 추가.
    N-=1
print(*o)