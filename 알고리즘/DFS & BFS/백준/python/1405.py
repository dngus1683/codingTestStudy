# 미친 로봇
#


# 내 답안1
import sys
input = sys.stdin.readline

num, E, W, S, N = map(int, input().split())

ans = 1
visited = []
li = []
def dfs(x,y,dir,cnt):
    global ans
    if cnt > num:
        li.append(ans)
        return 'over'
    if dir == 'E':
        ans = ans * (E/100)
    elif dir == 'W':
        ans = ans * (W/100)
    elif dir == 'S':
        ans = ans * (S/100)
    elif dir == 'N':
        ans = ans * (N/100)
    if (x,y) in visited:
        return 'v'
    else:
        d = dfs(x+1, y, 'E', cnt + 1)
        if d == 'v':
            ans = 1
            visited.clear()
        d = dfs(x-1, y, 'W', cnt + 1)
        if d == 'v':
            ans = 1
            visited.clear()
        d = dfs(x, y+1, 'N', cnt + 1)
        if d == 'v':
            ans = 1
            visited.clear()
        d = dfs(x, y-1, 'S', cnt + 1)
        if d == 'v':
            ans = 1
            visited.clear()
    visited.append((x,y))
dfs(0,0,0,0)

print(sum(li))