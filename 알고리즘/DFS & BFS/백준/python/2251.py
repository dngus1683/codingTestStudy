# 물통
# 부피가 각각 A, B, C인 물통이 있고 C에만 물이 가득 차있다. 물을 다른 통으로 옮길 수 있는데, 한 통이 가득 차거나 텅 빌 때까지 부을 수 있다.
# A에 물이 남아 있지 않을 때, C에 있을 물 양의 경우의 수를 모두 구하라.

# 내 답안1
from collections import deque
import sys
input = sys.stdin.readline
A, B, C = map(int, input().split())

A_b, B_b, C_b = [A,0,1], [B,0,2], [C,C,3]


def cal(x, y, z):         # x: 물 주는 병, y: 물 받는 병, z: 행동하지 않는 병
    ad = min(y[1] + x[1], y[0])
    st = y[1] + x[1] - ad
    y[1] = ad
    x[1] = st
    li = [x, y, z]
    li.sort(key=lambda x: x[2])
    return li

def bfs(a,b,c):
    queue = deque()
    queue.append([a, b, c])
    visited = []
    ans = []
    while queue:
        a, b, c = queue.popleft()

        if a[1] == 0 and c[1] not in ans:
            ans.append(c[1])

        nextLi = cal(a[:],b[:],c[:])
        if nextLi not in visited:
            queue.append(nextLi)
            visited.append(nextLi)
        nextLi = cal(a[:],c[:],b[:])
        if nextLi not in visited:
            queue.append(nextLi)
            visited.append(nextLi)
        nextLi = cal(b[:],a[:],c[:])
        if nextLi not in visited:
            queue.append(nextLi)
            visited.append(nextLi)
        nextLi = cal(b[:],c[:],a[:])
        if nextLi not in visited:
            queue.append(nextLi)
            visited.append(nextLi)
        nextLi = cal(c[:],b[:],a[:])
        if nextLi not in visited:
            queue.append(nextLi)
            visited.append(nextLi)
        nextLi = cal(c[:],a[:],b[:])
        if nextLi not in visited:
            queue.append(nextLi)
            visited.append(nextLi)
    return ans

dab = bfs(A_b, B_b, C_b)
dab.sort()
for i in range(len(dab)):
    print(dab[i], end=' ')

































# 답안 예시
# import sys
# from collections import deque
#
# # x, y의 경우의 수 저장
# def pour(x, y):
#     if not visited[x][y]:
#         visited[x][y] = True
#         q.append((x, y))
#
# def bfs():
#
#     while q:
#         # x : a물통의 물의 양, y : b물통의 물의 양, z : c물통의 물의 양
#         x, y = q.popleft()
#         z = c - x - y
#
#         # a 물통이 비어있는 경우 c 물통에 남아있는 양 저장
#         if x == 0:
#             answer.append(z)
#
#         # x -> y
#         water = min(x, b-y)
#         pour(x - water, y + water)
#         # x -> z
#         water = min(x, c-z)
#         pour(x - water, y)
#         # y -> x
#         water = min(y, a-x)
#         pour(x + water, y - water)
#         # y -> z
#         water = min(y, c-z)
#         pour(x, y - water)
#         # z -> x
#         water = min(z, a-x)
#         pour(x + water, y)
#         # z -> y
#         water = min(z, b-y)
#         pour(x, y + water)
#
#
# # 입력(리터 범위)
# a, b, c = map(int, sys.stdin.readline().split())
#
# # 경우의 수를 담을 큐
# q = deque()
# q.append((0, 0))
#
# # 방문 여부(visited[x][y])
# visited = [[False] * (b+1) for _ in range(a+1)]
# visited[0][0] = True
#
# # 답을 저장할 배열
# answer = []
#
# bfs()
#
# # 출력
# answer.sort()
# for i in answer:
#     print(i, end=" ")