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

































# 답안 예시 - https://www.acmicpc.net/source/52981210
# def pour(x, y):
#     if not visit[x][y]:
#         visit[x][y] = 1
#         q.append((x, y))

# A, B, C = map(int, input().split())
# q = [(0, 0)]
# visit = [[0] * (B + 1) for _ in range(A + 1)]
# visit[0][0] = 1
# ans = []
# while q:
#     a, b = q.pop(0)
#     c = C - (a + b)
#     if a == 0:
#         ans.append(c)
#     # A -> B
#     w = min(a, B - b)
#     pour(a - w, b + w)
#     # A -> C
#     w = min(a, C - c)
#     pour(a - w, b)
#     # B -> A
#     w = min(A - a, b)
#     pour(a + w, b - w)
#     # B -> C
#     w = min(b, C - c)
#     pour(a, b - w)
#     # C -> A
#     w = min(A - a, c)
#     pour(a + w, b)
#     # C -> B
#     w = min(B - b, c)
#     pour(a, b + w)
# ans.sort()
# print(*ans)
