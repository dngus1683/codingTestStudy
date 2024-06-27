# 최소 스패닝 트리
# 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
# 최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.


# 내 답안1
import sys

input = sys.stdin.readline

v, e = map(int, input().split())

parent = [i for i in range(v+1)]
graph = []
ans = 0

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



for _ in range(e):
    a, b, cost = map(int, input().split())
    graph.append((cost, a, b))

graph.sort()
for tu in graph:
    cost, a, b = tu
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        ans += cost

print(ans)
