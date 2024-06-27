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













# 답안 예시 - https://www.acmicpc.net/source/61300079
# from sys import stdin
# input = stdin.readline

# def solve():
#     root = {}

#     def findroot(node):
#         if node not in root:
#             root[node] = 1
#             return node
#         elif type(root[node]) == int:
#             return node
#         else:
#             root[node] = findroot(root[node])
#             return root[node]

#     def union(r1, r2):
#         root[r1] += root[r2]
#         root[r2] = r1

#     for _ in range(int(input())):
#         name1, name2 = input().split()
#         root1, root2 = findroot(name1), findroot(name2)
#         if root1 != root2:
#             union(root1, root2)
#         print(root[root1])


# for t in range(int(input())):
#     solve()