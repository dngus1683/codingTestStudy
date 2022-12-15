# 큰 수의 법칙
# 반복 가능한 n개의 숫자 중에서 m번 더하기를 하는데, k번 같은 숫자를 연속해서 더할 수 있을 때, 최댓값 구하라.


# 내 답안1
# n, m, k = map(int, input().split())
#
# data = list(map(int, input().split()))
#
#
# data.sort()     # sort()는 오름차순
# first = data[n-1]
# second = data[n-2]
#
# result = 0
# ksub = k
#
# for i in range(m):
#     if k > 0:
#         result += first
#         k -= 1
#     elif k == 0:
#         result += second
#         k = ksub
#
# print(result)  # 답안 출력

































# 반복되는 수열을 파악해서 계산하는 예시

n, m, k = map(int, input().split())

data = list(map(int, input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

# first의 갯수 계산
count = int(m/(k+1))*k
count += m % (k+1)

result = 0
result += count * first
result += (m-count) * second

print(result)
