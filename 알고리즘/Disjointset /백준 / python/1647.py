# 도시 분할 계획
# n개의 집과 m개의 도로가 있는 마을이 있는데, 이 마을을 두개의 마을로 분할하고 도로를 최소 비용으로 설치할 경우를 구하라.


# 내 답안1
import sys

input = sys.stdin.readline
n, m = map(int, input().split())

graph = []
parent = [i for i in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph.append((c,a,b))
graph.sort()

def find_parent(x):
    while parent[x] != x:
        x = parent[x]
    return x

def union_parent(a, b, c):
    a = find_parent(a)
    b = find_parent(b)
    if a == b:
        return 0
    elif a > b:
        parent[a] = b
    else:
        parent[b] = a
    return c

ans = 0
last = 0
for c, a, b in graph:
    c = union_parent(a, b, c)
    if c != 0:
        last = c
    ans += c
print(ans - last)