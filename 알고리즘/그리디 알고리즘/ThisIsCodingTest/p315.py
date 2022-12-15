# 볼링공 고르기
# M이하의 무게를 가지는 볼링공 N개가 주어졌을 때, 서로 무게가 다른 볼링공 2개를 고르는 경우의 수를 구하라.


# 내 답안1
# n, m = map(int, input().split())
#
# data = list(map(int, input().split()))
#
# count = 0
#
# for i in range(len(data)):
#     for j in range(i+1, len(data)):
#         if data[i] != data[j]:
#             count += 1
#
# print(count)
#






















# 답안 예시
# 무게 m이 최댓값 10으로 정해져있다. 주어진 볼링공들을 무게 별로 갯수를 파악해서 정리한 다음, 낮은 무게부터 한꺼번에 조합 수를 구해나간다.
# 내 답안1은 코드 길이는 짧지만 시간복잡도가 O(N^2)인 반면, 예시는 O(N)이기 때문에 시간측면으로 예시가 더 효율적이다.

n, m = map(int, input().split())
data = list(map(int, input().split()))

array = [0] * 11

for x in data:
    array[x] += 1

result = 0

for i in range(1, m+1):
    n -= array[i]
    result += array[i] * n

print(result)