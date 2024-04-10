# 친구 네트워크
# 친구 관계가 순서대로 주어질 때마다, 해당 친구 네트워크에 친구가 몇명이 있는지 출력하라.


# 내 답안1
import sys

input = sys.stdin.readline
T = int(input())

def find_parent(parent, x):
    while parent[x][0] != x:
        x = parent[x][0]
    return x

def union_parent(parent, a, b):
    ap = find_parent(parent, a)
    bp = find_parent(parent, b)
    if ap == bp:
        return 0
    elif ap > bp:
        parent[ap][0] = bp
        parent[bp][1] += parent[ap][1]
        return bp
    else:
        parent[bp][0] = ap
        parent[ap][1] += parent[bp][1]
        return ap
def solution(T):
    for _ in range(T):
        n = int(input())
        graph = []
        d = {}
        idx = 0
        for _ in range(n):
            a, b = input().split(" ")
            graph.append((a,b))
            if a not in d:
                d[a] = idx
                idx += 1
            if b not in d:
                d[b] = idx
                idx += 1
        parent = [[i, 1] for i in range(idx)]
        for a, b in graph:
            pIdx = union_parent(parent, d[a], d[b])
            print(parent[pIdx][1])

solution(T)













# 답안 예시
# Root node를 찾아주는 함수
# def find(x):
#     if x == parent[x]:
#         return x
#     else:
#         root_x = find(parent[x])
#         parent[x] = root_x
#         return parent[x]
#
#
# y의 Root 노드가 x의 Root 노드와 같지 않으면
# y의 Root 노드가 x의 Root 노드의 자식이 되도록 하는 함수
# def union(x, y):
#     root_x = find(x)
#     root_y = find(y)
#
#     if root_x != root_y:
#         parent[root_y] = root_x
#         number[root_x] += number[root_y]
#
#
# test_cases = int(input())
#
# for _ in range(test_cases):
#     parent = dict()
#     number = dict()
#
#     f = int(input())
#
#     for _ in range(f):
#         x, y = input().split(" ")
#
#         if x not in parent:
#             parent[x] = x
#             number[x] = 1
#         if y not in parent:
#             parent[y] = y
#             number[y] = 1
#
#         union(x, y)
#         print(number[find(x)])
