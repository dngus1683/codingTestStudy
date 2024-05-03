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











# 답안 예시 - https://www.acmicpc.net/source/37428472
import sys
input = sys.stdin.readline
X = input().rstrip()
Y = input().rstrip()

def answer(X, Y) :
	DP = [0] * 1000

	for i, x in enumerate(X):
		cnt = 0
		for j, y in enumerate(Y):
			if cnt < DP[j]:
				cnt = DP[j]
			elif x == y:
				DP[j] = cnt + 1
	
	return max(DP)

print(answer(X, Y))
