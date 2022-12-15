# 곱하기 혹은 더하기
# 숫자로 이루어진 문자열 하나가 주어질 때, 맨 왼쪽부터 곱하기 또는 더하기를 하여 계산해나갔을 때, 가장 큰 수를 구하라.


# 내 답안1
# s = input()
# data = list(map(int, s))
#
# result = data[0]
#
# for i in range(1, len(data)):
#     if (data[i] * result) > (data[i] + result):
#         result *= data[i]
#     else:
#         result += data[i] + result
#
# print(result)























# 답안 예시
# 두수에 대하여 연산을 할 때, 두 수 중에서 하나라도 1 이하인 경우에는 더하며, 두수가 모두 2 이상인 경우에는 곱한다
data = input()

result = int(data[0])

for i in range(1, len(data)):
    num = int(data[i])
    if num <= 1 or result <= 1:
        result += num
    else:
        result *= num

print(result)