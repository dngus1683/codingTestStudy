# 시각
# 정수 N이 입력되면, N시 59분 59초까지의 시간 중 3이 하나라도 포함된 시각의 갯수를 구하라.


# 내 답안1
# n = int(input())
# count = 0
#
# for i in range(n+1):
#     if '3' in str(i):
#         count += 60 * 60
#
#         continue
#     for j in range(60):
#         if '3' in str(j):
#             count += 60
#             continue
#         for k in range(60):
#             if '3' in str(k):
#                 count += 1
#
# print(count)
#
























# 답안 예시
# 하루는 총 86400초로, 모두 세서 푸는 것도 시간적으로 여유롭기 때문에 모든 시각의 경우를 하나씩 모두 세서 푼다.(완전 탐색 유형)
# 완전 탐색 유형은 탐색할 전체 데이터의 개수가 100만 개 이하일 때 사용하면 적절하다.
# 아래 코드는 시, 분, 초 문자열을 한꺼번에 검사한다.

h = int(input())

count = 0

for i in range(h+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                count += 1

print(count)


