# 사이클 게임
# 임의의 점 n개가 주어질 때, 두 플레이어는 번갈아가면서 두 점을 잇는 선분을 그린다. 사이클이 발생하는 선분을 그리는 순간 게임은 종료된다.
# 이때, 사이클이 발생했을 때가 몇 번째인지 구하라.


# 내 답안1
# import sys
#
# sys.setrecursionlimit(1000000)
# input = sys.stdin.readline
# n, m = map(int, input().split())
#
# parent = [i for i in range(n)]
# def find_parent(parent, x):
#     if parent[x] != x:
#         parent[x] = find_parent(parent, parent[x])
#     return parent[x]
#
# def union_parent(parent, a, b):
#     a = find_parent(parent, a)
#     b = find_parent(parent, b)
#     if a > b:
#         parent[a] = b
#     else:
#         parent[b] = a
#
# ans = 0
#
# for i in range(m):
#     a, b = map(int, input().split())
#     if find_parent(parent, a) != find_parent(parent, b):
#         union_parent(parent, a, b)
#     elif ans == 0:
#         ans = i+1
#
# print(ans)






# 내 답안2
# 재귀함수를 반복문으로 바꾸고 불필요한 find_parent 호출을 줄였으며 parent list 복사를 줄였다.
import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline
n, m = map(int, input().split())

parent = [i for i in range(n)]
def find_parent(x):
    while parent[x] != x:
        x = parent[x]
    return x

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a == b:
        return 0
    elif a > b:
        parent[a] = b
    else:
        parent[b] = a
    return 1

ans = 0

for i in range(m):
    a, b = map(int, input().split())
    if not union_parent(a, b):
        ans = i+1
        break

print(ans)
