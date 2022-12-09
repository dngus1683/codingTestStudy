# 1이 될 때까지
# n과 k를 입력 받았을 때, n에서 1을 빼거나 k로 나누어서 1이 되도록 하는 최소 계산 횟수를 구하라.


# 내 답안1
# n, k = map(int, input().split())
#
# count = 0
# num = 1
# while True:
#     if n >= (num * k):
#         num *= k
#         count += 1
#     else:
#         count += (n - num)
#         break
# print(count)























# 단순하게 빼고 나누면서 푸는 방법
# n, k =map(int, input().split())
# result = 0
#
# while n >= k:
#     while n % k != 0:
#         n -= 1
#         result += 1
#     n //= k
#     result += 1
#
# while n > 1:
#     n -= 1
#     result += 1
#
# print(result)


# 1을 일일히 빼지 않고 한번에 뺴는 방법
n, k = map(int, input().split())
result = 0

while True:
    target = (n // k) * k
    result += (n - target)
    n = target
    if n < k:
        break
    result += 1
    n //= k

result += (n-1)
print(result)
