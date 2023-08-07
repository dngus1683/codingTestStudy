# 팔
# L과 R이 주어진다. 이때, L보다 크거나 같고, R보다 작거나 같은 자연수 중에 8이 가장 적게 들어있는 수에 들어있는 8의 개수를 구하는 프로그램을 작성하시오.

# 내 답안1

import sys

input = sys.stdin.readline

L, R = input().split()
ans = 0
for i in range(len(R)):
    if len(L) != len(R):
        break
    if L[i] == R[i]:
        if R[i] == '8':
            ans += 1
    else:
        break


print(ans)






# 답안 예시1
# 두 배열에 대해서 동시에 for문을 돌리고 싶을 때, zip()함수를 사용할 수 있다.
# L, R = input().split()
# ans = 0
# if len(L) == len(R):
#     for v1, v2 in zip(L, R):
#         if v1 != v2:
#             break
#         if v1 == '8':
#             ans += 1
#
# print(ans)
