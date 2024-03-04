# 돌 게임 3
# 탁자 위에 돌이 N개 있다. 상근이와 창영이가 한 번에 1 or 3 or 4개의 돌을 번갈아 가져갈 때, 마지막 돌을 가져가는 사람이 이기는 게임을 한다.
# 상근이가 게임을 먼저 시작할 때, 승자를 출력하라.


# 내 답안1
import sys

input = sys.stdin.readline

N = int(input())

print("CY" if N%7==0 or N%7==2 else "SK")