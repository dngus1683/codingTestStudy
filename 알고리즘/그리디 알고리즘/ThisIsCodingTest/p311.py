# 모험가 길드
# N명의 모험가들의 공포도가 주어졌을 때, 각 모험가들은 본인의 공포도만큼의 인원들과 같이 다녀야한다. 이때, 최대로 나올 수 있는 길드팟의 수를 구하시오


# 내 답안1
# n = int(input())
#
# data = list(map(int, input().split()))
# data1 = [0] * (n+1)
# count = 0
#
# for i in range(n):
#     data1[data[i]] += 1
#
# for i in range(n+1):
#     num = data1[i]
#     for j in range(num):
#         if i <= data1[i]:
#             count += 1
#             data1[i] -= i
#         else:
#             break
#
# print(count)
























# 답안 예시

n = int(input())
data = list(map(int, input().split()))
data.sort()

result = 0  # 총 그룹의 수
count = 0   # 현재 그룹에 포함된 모험가의 수

for i in data:
    count += 1
    if count >= i:
        result += 1
        count = 0

print(result)