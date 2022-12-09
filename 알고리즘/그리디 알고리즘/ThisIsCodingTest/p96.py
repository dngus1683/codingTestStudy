# 숫자 카드 게임
# n행과 m열에 숫자가 있을 때, 특정 행을 선택한 후 그 행에서 가장 작은 숫자를 골랐을 때, 그 숫자가 가장 클 경우를 구하라.


# 내 답안1
# n, m = map(int, input().split())
#
# result = 0
# for i in range(n):
#     data = list(map(int, input().split()))
#     data.sort()
#     if result < data[0]:
#         result = data[0]
#     # 위와 같은 경우, result = max(result, data[0])로 max()함수를 활용해보자.
#     # data[0]는 sort() 대신, min(data)를 활용가능하다.
#
# print(result)
#


























# 2중 반복문 구조를 이용하는 답안
n, m = map(int, input().split())

result = 0

for i in range(n):
    data = list(map(int, input().split()))
    min_value = 10001
    for a in data:
        min_value = min(min_value, a)
    result = max (result, min_value)

print(result)