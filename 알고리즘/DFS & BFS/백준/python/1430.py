# 공격
# 도시를 방어하는 게임을 만든다
# 탑의 개수는 N, 탑의 사정거리는 R, 탑의 에너지는 D, 탑의 위치좌표는 X, Y 다.
# 탑끼리 에너지 공유 가능: 사정거리 내에 있어야 하며 에너지를 전송 시 손실 에너지가 발생, 절반만 전달된다.(에너지 10 전송 -> 에너지 5 도착)
# 적은 사정거리 내에 있을 경우 공격 가능. 공격 시 모든 에너지를 소모
# 적이 받을 수 있는 에너지의 최댓값을 구하라.


# 내 답안1
# bfs
import sys
import math
from collections import deque

input = sys.stdin.readline

N, R, D, EX, EY = map(int, input().split())
graph = [[] for _ in range(N+1)]
cost = [0 for _ in range(N+1)]
tower = [(EX,EY)]

for _ in range(N):
    x, y = map(int, input().split())
    tower.append((x, y))

def cal_dist(tu1, tu2):
    x1, y1 = tu1
    x2, y2 = tu2
    return math.sqrt(abs(x1 - x2)**2 + abs(y1 - y2)**2)

for i in range(N+1):
    for j in range(i+1, N+1):
        if cal_dist(tower[i], tower[j]) <= R:
            graph[i].append(j)
            graph[j].append(i)

def bfs(start):
    visited = [0 for _ in range(N+1)]
    queue = deque()
    queue.append((start, 0))
    while queue:
        x, c = queue.popleft()
        if visited[x] != 0:
            continue
        visited[x] = 1
        cost[c] += 1
        for nx in graph[x]:
            if visited[nx] == 0:
                queue.append((nx, c+1))

bfs(0)

ans = 0
for i in range(1, N+1):
    ans += D*cost[i]*(0.5)**(i-1)

print(ans)