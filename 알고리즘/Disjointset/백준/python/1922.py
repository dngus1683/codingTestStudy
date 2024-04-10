# 네트워크 연결
# 모든 컴퓨터를 연결하고자 할 때, 최소비용을 구하라.


# 내 답안1
import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n = int(input())
m = int(input())

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
        return c
    else:
        parent[b] = a
        return c

ans = 0
for c, a, b in graph:
    ans += union_parent(a, b, c)

print(ans)
