# 알파벳 다이아몬드
# N이 주어질 때, 알파벳 소문자로 다이아몬드를 만든다. 아래 얘시 참조
# N=3 일 때)
# ..c..
# .cbc.
# cbabc
# .cbc.
# ..c..
# 해당 다이아몬드가 상하좌우로 무한히 연결되어 있다. 이때, 두 좌표 (R1,C1), (R2,C2)가 주어질 때, 해당 좌표에 대한 직사각형 내에 다이아몬드 정보를 구하라.


# 내 답안1
# N이 26 초과인 값일 경우를 고려해야 함.
# N이 27인 경우, N=1인 경우와 같은 출력을 내서는 안되고, N=26 즉 z인 경우에서 추가로 a가 붙는 결과를 출력해야 한다.
import sys

input = sys.stdin.readline
ascNum = 97

N, R1, C1, R2, C2 = map(int, input().split())

for r in range(R1+1, R2+2):
    for c in range(C1+1, C2+2):
        Rnum = r % ((N-1)*2+1)
        Cnum = c % ((N-1)*2+1)

        if Rnum == 0:
            Rnum = ((N-1)*2+1)
        if Cnum == 0:
            Cnum = ((N-1)*2+1)

        if Rnum < N:
            Rnum = Rnum % N
        elif Rnum > N:
            Rnum = N - Rnum % N
        if Cnum < N:
            Cnum = Cnum % N
        elif Cnum > N:
            Cnum = N - Cnum % N

        num = N*2-Rnum-Cnum

        if num >= N:
            print('.', end='')
        elif num >= 26:
            print(chr(ascNum + num % 26), end='')
        else:
            print(chr(ascNum+num), end='')
    if r == R2+1:
        break
    print(' ')











# 답안 예시1 - https://www.acmicpc.net/source/54530193
# 내 답안1과 같은 계산으로 다이아몬드를 만들지만 코드가 훨씬 간결하다.
# 또한, 다이아몬드를 하나 미리 만들고, 좌표를 입력하면서 출력하는 방식으로 코드가 구현되어 있다.
# n, r1, c1, r2, c2 = map(int, input().split())
# grid, n1 = 2 * n - 1, n - 1
#
#
# def diamond(x, y):
#     diff = abs(x % grid - n1) + abs(y % grid - n1)
#     return chr(diff % 26 + 97) if diff < n else "."
#
#
# print(
#     "\n".join(
#         "".join(diamond(i, j) for j in range(c1, c2 + 1)) for i in range(r1, r2 + 1)
#     )
# )

