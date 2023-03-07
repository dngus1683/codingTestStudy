# 미친 로봇
# 로봇은 동서남북으로 이동할 각 확률을 가지고 있다. 이에 따라 N번 이동한다고 할 때, 한번 들린 곳은 다시 들리지 않게 끔 이동할 확률을 구하라.


# 내 답안1
import sys
input = sys.stdin.readline

num, E, W, S, N = map(int, input().split())

visited = []
li = []


def dfs(x,y,dir,cnt,ans):

    if (x,y) in visited:
        return False

    ans = ans * (dir / 100)

    if cnt + 1 > num:
        li.append(ans)
        return False

    visited.append((x, y))
    dfs(x + 1, y, E, cnt + 1, ans)
    dfs(x - 1, y, W, cnt + 1, ans)
    dfs(x, y + 1, N, cnt + 1, ans)
    dfs(x, y - 1, S, cnt + 1, ans)
    visited.pop()

    return False

dfs(0, 0, 100, 0, 1)

print(sum(li))












# 답안 예시
# d = [(-1, 0), (1, 0), (0, -1), (0, 1)] # 4방향 탐색
#
# def dfs(r, c, visited, total):
#     global answer
#     if len(visited) == N+1:
#         answer += total
#         return
#     for idx in range(4):
#         nr = r + d[idx][0]
#         nc = c + d[idx][1]
#         if (nr, nc) not in visited:
#             visited.append((nr, nc))
#             dfs(nr, nc, visited, total*probability[idx])
#             visited.pop()
#
# N, ep, wp, sp, np = map(int, input().split())
# probability = [ep, wp, sp, np]
# answer = 0
#
# dfs(0, 0, [(0, 0)], 1)
# print(answer * (0.01 ** N))