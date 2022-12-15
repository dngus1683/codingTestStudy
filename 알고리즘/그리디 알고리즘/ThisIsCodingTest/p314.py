# 만들 수 없는 금액
# N개의 동전이 주어졌을 때, 그 동전들로 만들 수 없는 가장 작은 금액을 구하라.

# 내 답안1
# 알고리즘을 생각해내지 못함.
# n = int(input())
#
# data = list(map(int, input().split()))
#
# data.sort()
#
# for i in range(1, sum(data)+1):
#     for j in range(len(data)):
#
#     if i in data:
#         continue
#     else:



















# 답안 예시
# 동전을 오름차순으로 정리했을 때, 1원이 존재한다면 첫번 째 항부터 하나씩 더한 숫자의 이하로는 모두 표현이 가능하다. 예를 들어 1원, 2원, 3원이 있다고 한다면 (1+2+3=)6원 이하로는 표현이 가능하다.
# 이 점을 활용하여 코드를 짠다.
n = int(input())

data = list(map(int, input().split()))
data.sort()

target = 1

for i in data:
    if target >= i:
        target += i
    else:
        break

print(target)


