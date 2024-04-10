# 상근이의 여행
# 상근이가 N개국을 여행할 때 가장 적은 종류의 비행기를 타는 경우를 구하라. (같은 국가 재방문 허용)


# 내 답안1
# 크루스칼 알고리즘
import sys

input = sys.stdin.readline
T = int(input())


def find_parent(parent,x):
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

def solution(T):
    for _ in range(T):
        ans = 0
        N, M = map(int, input().split())

        parent = [i for i in range(N+1)]
        graph = []
        for _ in range(M):
            a, b = map(int, input().split())
            graph.append((a,b))

        for tu in graph:
            a, b = tu
            if find_parent(parent, a) != find_parent(parent, b):
                union_parent(parent, a, b)
                ans += 1
        print(ans)

solution(T)















# 답안 예시1
# import sys
# input = sys.stdin.readline
#
# t = int(input())
#
# for _ in range(t):
#     n, m = map(int, input().split())
#     for _ in range(m):
#         input() # 무조건 연결그래프이므로 입력 값을 무시한다.
#     print(n - 1)


# 답안 예시2
# input = open(0, 'rt').read().rstrip().split('\n')
#
# T = int(input[0])
# idx = 1
# for _ in range(T):
#     N, M = map(int, input[idx].split())
#     idx += M + 1
#     print(N-1)


