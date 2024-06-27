# 해킹
# 하나의 컴퓨터가 해킹되었을 때, 서로 연결되어 있는 컴퓨터끼리는 전염된다. 해킹된 컴퓨터의 수와 걸린 시간을 구하라


# 내 답안1
import sys
import heapq

INF = 987654321
input = sys.stdin.readline

T = int(input())


def solution(T):
    for _ in range(T):
        n, m, start = map(int, input().split())
        graph = [[] for _ in range(n+1)]
        for _ in range(m):
            a,b,c = map(int, input().split())
            graph[b].append((a,c))

        q = []
        heapq.heappush(q, (0, start))
        d = [INF for _ in range(n + 1)]
        d[start] = 0
        track = [i for i in range(n + 1)]

        while q:
            dist, now = heapq.heappop(q)
            if d[now] < dist:
                continue
            for b, c in graph[now]:
                cost = d[now] + c
                if cost < d[b]:
                    d[b] = cost
                    track[now] = b
                    heapq.heappush(q, (cost, b))

        cnt, time = 0, 0
        for i in range(n + 1):
            if d[i] != INF:
                cnt += 1
                if track[i] == i:
                    time = max(d[i], time)
        print(cnt, time)

solution(T)


