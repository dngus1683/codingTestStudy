# 개미굴
# 이진 트리 형태로 문자가 주어진다. 이를 시각화 하라


# 내 답안1
import sys

input = sys.stdin.readline

n = int(input())
graph = []
d = [[] for _ in range(16)]

for _ in range(n):
    li = list(input().split())
    graph.append(li[1:])

graph.sort()

for l in graph:
    for i in range(len(l)):
        if l[:i+1] + ['end'] in d[i+1]:
            break
        elif l[:i+1] not in d[i]:
            if i >= 1:
                for j in range(i*2):
                    print('-', end='')
            print(l[i])
            d[i].append((l[:i+1]))
    l.append('end')
    d[len(l)-1].append(l)







# 답안 예시1
# import sys
# input = sys.stdin.readline
# sys.setrecursionlimit(10**6)
#
# class Trie:
#     def __init__(self):
#         self.root = {}
#
#     def add(self, foods):
#         cur = self.root
#
#         for food in foods:
#             if food not in cur:
#                 cur[food] = {}  # 자식 노드
#             cur = cur[food]
#         cur[0] = True  # 리프 노드 표시
#
#     def travel(self, level, cur):
#         if 0 in cur:
#             return
#         cur_child = sorted(cur)
#
#         for ch in cur_child:
#             print("--" * level + ch)
#             self.travel(level + 1, cur[ch])
#
# N = int(input())
# trie = Trie()
# for i in range(N):
#     data = list(input().split())
#     trie.add(data[1:])
#
# trie.travel(0, trie.root)
