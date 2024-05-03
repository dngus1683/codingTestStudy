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












# 답안 예시 - https://www.acmicpc.net/source/75383477
# n, E, W, S, N = map(int, input().split())
# board = [[0] * (2 * n + 1) for _ in range(2 * n + 1)]

# def prob(x, y, cnt):
#     if board[x][y] == 1:
#         return 0
#     if cnt == 0:
#         return 1
#     board[x][y] = 1
#     ret = 0
#     ret += E * prob(x, y + 1, cnt - 1)
#     ret += W * prob(x, y - 1, cnt - 1)
#     ret += S * prob(x + 1, y, cnt - 1)
#     ret += N * prob(x - 1, y, cnt - 1)
#     board[x][y] = 0
#     return ret

# print(prob(n, n, n) / (100 ** n))