# 행성 터널
# n개의 행성 3차원 좌표가 주어질 때, 모든 행성을 연결하는 다리를 만드는 최소 비용을 구하라.


# 내 답안1
# import sys
#
# input = sys.stdin.readline
# n = int(input())
# parent = [0] * n
# edge = []
# graph = []
#
# def dist(a, b):
#     flag = 0
#     mn = min(abs(a[0]-b[0]), abs(a[1]-b[1]), abs(a[2]-b[2]))
#     if abs(a[0]-b[0]) == mn:
#         flag = 0
#     elif abs(a[1]-b[1]) == mn:
#         flag = 1
#     else:
#         flag = 2
#     return (mn, flag)
# def find_parent(x):
#     while parent[x] != x:
#         x = parent[x]
#     return x
#
# def union_parent(a, b, c):
#     a = find_parent(a)
#     b = find_parent(b)
#     if a == b:
#         return 0
#     elif a > b:
#         parent[a] = b
#     else:
#         parent[b] = a
#     return c
#
# for i in range(n):
#     a, b, c = map(int, input().split())
#     graph.append((a,b,c))
#     parent[i] = i
#
#
# for i in range(n):
#     mx = [[987654321, 0, 0], [987654321, 0, 0], [987654321, 0, 0]]
#     for j in range(i+1, n):
#         c, flag = dist(graph[i], graph[j])
#         if mx[flag][0] >= c:
#             mx[flag] = [c,i,j]
#     edge.append(mx[0])
#     edge.append(mx[1])
#     edge.append(mx[2])
#
# edge.sort()
# ans = 0
# for c,a,b in edge:
#     ans += union_parent(a,b,c)
#
# print(ans)
#



# 내 답안2
import sys

input = sys.stdin.readline
n = int(input())
parent = [0] * n
edge = []
graph = []

def dist(a, b):
    flag = 0
    mn = min(abs(a[0]-b[0]), abs(a[1]-b[1]), abs(a[2]-b[2]))
    if abs(a[0]-b[0]) == mn:
        flag = 0
    elif abs(a[1]-b[1]) == mn:
        flag = 1
    else:
        flag = 2
    return (mn, flag)
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
    a, b, c = map(int, input().split())
    graph.append((a,b,c,i))
    parent[i] = i

graph.sort()
for i in range(n-1):
    edge.append((abs(graph[i][0]-graph[i+1][0]),graph[i][3],graph[i+1][3]))
graph.sort(key=lambda x:x[1])
for i in range(n-1):
    edge.append((abs(graph[i][1]-graph[i+1][1]),graph[i][3],graph[i+1][3]))
graph.sort(key=lambda x:x[2])
for i in range(n-1):
    edge.append((abs(graph[i][2]-graph[i+1][2]),graph[i][3],graph[i+1][3]))

edge.sort()
ans = 0
for c,a,b in edge:
    ans += union_parent(a,b,c)

print(ans)
