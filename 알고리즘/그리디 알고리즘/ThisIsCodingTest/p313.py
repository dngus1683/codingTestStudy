# 문자열 뒤집기
# 0과 1로 구성되어있는 문자열 s가 있을 때, 연속된 하나 이상의 숫자를 뒤집어서 모두 같은 숫자로 만드는 최소 행동 수를 구하라.

# 내 답안1
# 연속된 0집합의 갯수와 1집합의 갯수를 계산해서 비교하여 답을 도출하는 방법으로 시도함. 하지만 n-1, n번째가 서로 다를 때, n번째가 카운팅이 되지 않는 문제를 해결하지 못함.
# 답안 예시와 비교하면 사실 다른 방법 자체는 다르지 않음. 집합 갯수를 비교하는 것과 전부 하나로 바꾼 후 그 두 값을 비교하는 것은 같은 방법임.
# 차이점은, for문에서 전항과 비교했는지 후항과 비교했는지이며, 본인은 마지막 원소에 대해서 처리를 하지 않아서 문제가 발생했음.
# s = input()
#
# count0 = 0
# count1 = 0
#
# for i in range(1, len(s)):
#     if s[i-1] == s[i]:
#         continue
#     else:
#         if s[i-1] == '0':
#             count0 += 1
#         else:
#             count1 += 1
#
# if count0 < count1:
#     print(count0)
# else:
#     print(count1)




























# 답안 예시
# 아예 전부 0으로 바꿔보고, 1로 바꿔보고 난 후 두 횟수를 비교한다.
s = input()
count0 = 0  # 전부 0으로 바꾸는 경우
count1 = 0  # 전부 1로 바꾸는 경우

if s[0] == '1':
    count0 += 1
else:
    count1 += 1

for i in range(len(s)-1):
    if s[i] != s[i+1]:
        if s[i+1] == '1':
            count0 += 1
        else:
            count1 += 1

print(min(count0, count1))



