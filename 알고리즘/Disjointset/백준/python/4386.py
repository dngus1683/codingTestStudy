# 별자리 만들기
# n개의 별이 간,직접적으로 모두 이어져 있어야 한다. 각 별의 좌표값이 주어질 때, 거리만큼의 비용이 든다고 할 때 최소 비용을 구하라.

# 내 답안1
import sys
import math

input = sys.stdin.readline
n = int(input())

parent = [i for i in range(n)]
graph = []
edge = []

def cal_dist(l1, l2):
    return math.sqrt((l1[0]-l2[0])**2 + (l1[1]-l2[1])**2)


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


for i in range(n):
    a, b = map(float, input().split())
    graph.append([a, b])

for i in range(n):
    for j in range(i+1,n):
        c = cal_dist(graph[i], graph[j])
        edge.append((c, i, j))

edge.sort()
ans = 0

for c, a, b in edge:
    ans += union_parent(a, b, c)
print(round(ans,2))
