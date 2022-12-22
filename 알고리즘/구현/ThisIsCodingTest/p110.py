# 상하좌우
# N X N 크기의 정사각형 공간이 있다. (1,1)부터 시작해서 L, R, U, D의 문자를 통해 이동을 했을 때, 마지막에 도착하는 위치의 좌표를 구하라.

# 내 답안1
# n = int(input())
# array = list(input().split())
#
# x = 1
# y = 1
#
# for i in array:
#     if i == 'R' and y+1 <= n:
#         y += 1
#     elif i == 'L' and y-1 >= 1:
#         y -= 1
#     elif i == 'U' and x-1 >= 1:
#         x -= 1
#     elif i == 'D' and x+1 <= n:
#         x += 1
#
# print(x, y)

























# 답안 예시
# dx, dy를 활용하여 문제를 풀었다. 아래 코드를 보면 이중 for문이 있는데, 이를 보고 시간 복잡도가 O(N^2)이라고 착각할 수 있는데, 가장 안쪽 for문은 최악의 경우 4번이 최대이기 때문에,
# 4N 즉 O(N)의 시간 복잡도를 갖는다고 볼 수 있다.
n = int(input())
x, y = 1, 1
plans = input().split()

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_type = ['L', 'R', 'U', 'D']

for plan in plans:
    for i in range(len(move_type)):
        if plan == move_type[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    x, y = nx, ny

print(x, y)
