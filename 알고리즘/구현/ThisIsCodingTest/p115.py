# 왕실의 나이트
# 8 X 8 크기의 체스판이 있다. 나이트의 좌표위치가 주어질 때, 해당 말이 움직일 수 있는 경우의 수를 구하라.


# 내 답안1
# 예외처리 부분이 매우 비효율적이다.
# pos = input()
#
# r, c = 1, int(pos[1])
# row = 'abcdefgh'
# for i in range(len(row)):
#     if pos[0] == row[i]:
#         r = i+1
#
# dr1 = [-2, 2, 0, 0]
# dc1 = [0, 0, -2, 2]
# dr2 = [0, 0, -1, 1]
# dc2 = [-1, 1, 0, 0]
#
# count = 0
#
# for i in range(4):
#     for j in range(4):
#         nr = r + dr1[i] + dr2[j]
#         nc = c + dc1[i] + dc2[j]
#         if nr < 1 or nr > 8 or nc < 1 or nc > 8 or ((i == 0 or i == 1) and (j == 2 or j == 3)) or ((j == 0 or j == 1) and (i == 2 or i == 3)):
#             continue
#
#         count += 1
#
# print(count)


























# 답안 예시
# 예시에서는 이동에 대한 list를 각각의 튜플로 저장해서 사용하였다.

input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1    # ord() 함수는 ()안에 있는 문자를 아스키코드로 반환한다. 반대의 경우는 chr()가 있다.

steps = [(-2, -1), (-2, 1), (2, -1), (2, 1), (-1, 2), (-1, -2), (1, 2), (1, -2)]

result = 0
for step in steps:
    next_row = row + step[0]
    next_column = column + step[1]

    if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8:
        result += 1

print(result)