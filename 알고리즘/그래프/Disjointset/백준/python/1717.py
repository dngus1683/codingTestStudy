# 집합의 표현
# {0}, ..., {N}의 집합이 있을 때, 합집합 연산과 두 원소가 같은 집합에 있는 지를 확인하는 연산, 이 두가지 연산이 가능한 프로그램을 만들어라.


# 내 답안1
import sys

sys.setrecursionlimit(1000000)      # ***** 파이썬에서 재귀함수 최대 깊이를 충분히 지정해주기. *****
input = sys.stdin.readline
n, m = map(int, input().split())

parent = [i for i in range(n+1)]
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

for i in range(m):
    f, a, b = map(int, input().split())
    if f == 0:
        union_parent(parent, a, b)
    else:
        if find_parent(parent, a) == find_parent(parent, b):
            print("YES")
        else:
            print("NO")











# 답안 예시 - https://www.acmicpc.net/source/55448622
# import io, os, sys
#
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
# print = sys.stdout.write
#
#
# def solve():
#     n, m = map(int, input().split())
#
#     parent = list(range(n + 1))
#     for _ in range(m):
#         tp, a, b = map(int, input().split())
#
#         while a != parent[a]:
#             parent[a] = parent[parent[a]]
#             a = parent[a]
#
#         while b != parent[b]:
#             parent[b] = parent[parent[b]]
#             b = parent[b]
#
#         if tp == 0:
#             if a != b:
#                 if a > b:
#                     a, b = b, a
#                 parent[b] = a
#         else:
#             print('YES\n') if a == b else print('NO\n')
#
#
# if __name__ == '__main__':
#     solve()
