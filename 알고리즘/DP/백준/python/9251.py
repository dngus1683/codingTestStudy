# LCS
# LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
# 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

# 내 답안1
# import sys
#
# input = sys.stdin.readline
# str1 = input()
# str2 = input()
# d = [0, []]

# for i in range(len(str2)-2, -1, -1):
#     k = len(str1)-2
#     tmp = len(str1)-2
#     if str2[i] in d[1] and d[0] >= i+1:
#         continue
#     dtmp = [0, []]
#     for j in range(i, -1, -1):
#         if k != tmp:
#             k = tmp
#         while k >= 0:
#             if str2[j] == str1[k]:
#                 dtmp[0] += 1
#                 dtmp[1].append(str1[k])
#                 k -= 1
#                 tmp = k
#                 break
#             k -= 1
#     if dtmp[0] >= d[0]:
#         d = dtmp[:]
#     dtmp = [0, []]
#
# print(d)











# 답안 예시
import sys

input = sys.stdin.readline
str1 = input()
str2 = input()
d = [[0 for _ in range(len(str2) - 1)] for _ in range(len(str1) - 1)]

for i in range(0, len(str1) - 1):
    for j in range(0, len(str2) - 1):
        if str1[i] == str2[j]:
            d[i][j] += d[i-1][j-1]+1
        else:
            d[i][j] = max(d[i-1][j], d[i][j-1])

print(d[-1][-1])






#
# import sys
#
# string_a = ' ' + sys.stdin.readline().rstrip()
# string_b = ' ' + sys.stdin.readline().rstrip()
# dp = [[0] * len(string_b) for _ in range(len(string_a))]
#
# for i in range(1, len(string_a)):
#     for j in range(1, len(string_b)):
#         if string_a[i] == string_b[j]:
#             dp[i][j] = dp[i - 1][j - 1] + 1
#         else:
#             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
#
# print(dp[-1][-1])