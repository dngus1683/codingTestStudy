# 트리
# 트리가 주어졌을 때, 특정 노드를 삭제 시 남은 리프노드의 갯수를 구하라.


# 내 답안1
import sys

input = sys.stdin.readline

n = int(input())
li = list(map(int, input().split()))
graph = [[] for _ in range(n)]
value = int(input())

for i in range(n):
    if li[i] == -1:
        continue
    graph[li[i]].append(i)

def delete(l):
    if l != []:
        for i in l:
            delete(graph[i])
    l.clear()
    l.append(-1)

delete(graph[value])

cnt = 0
for i in range(n):
    if graph[i] == []:
        cnt += 1
    elif len(graph[i]) == 1 and graph[i] != [-1] and graph[graph[i][0]] == [-1]:
        cnt += 1

print(cnt)






# 답안 예시1
# def dfs(d):
#     arr[d] = -2
#     for i in range(n):
#         if d == arr[i]:
#             dfs(i)
#
# n = int(input())
# arr = list(map(int,input().split()))
# d = int(input())
# cnt = 0
# dfs(d)
#
# for i in range(n):
#     if arr[i] != -2 and i not in arr:
#         cnt+=1
# print(cnt)