# 주사위
#    D
# E  A  B  F
#    C
# 위는 주사위의 전개도이며 각 면 당 숫자가 주어진다.
# N^3 개의 주사위로 N x N x N 의 정육면체를 책상 위에 만든다.
# 밑면을 제외한 5면이 보일 때, 보이는 숫자들의 합의 최솟값을 구하라.


# 내 답안1
import sys

INF = 987654321
input = sys.stdin.readline

N = int(input())
A, B, C, D, E, F = map(int, input().split())
li = [A,B,C,D,E,F]

comb2 = [(A,B),(A,C),(A,D),(A,E),(B,C),(B,D),(B,F),(C,E),(C,F),(D,E),(D,F),(E,F)]
comb3 = [(A,B,C),(A,B,D),(A,C,E),(A,D,E),(B,C,F),(B,D,F),(C,E,F),(D,E,F)]

min2 = INF
min3 = INF

for tu in comb2:
    a, b = tu
    if min2 >= a+b:
        min2 = a+b

for tu in comb3:
    a, b, c = tu
    if min3 >= a+b+c:
        min3 = a+b+c

if N > 1:
    ans = ((N-2)**2 * 5 + (N-2) * 4) * min(li) + ((N-1) * 4 + (N-2) * 4) * min2 + 4 * min3
else:
    ans = sum(li) - max(li)


print(ans)








# 답안 예시1
# 각각 마주 보는 면 중 최솟값을 구하고, 오름차순으로 정렬하여, 선택된 세 면을 각각 따로 계산한다.
# n = int(input())
# a = list(map(int, input().split()))
# min = [min(a[0], a[5]), min(a[1], a[4]), min(a[2], a[3])]
# min.sort()
# if n >= 2:
#     print(min[2]*4+min[1]*8*(n-1)+min[0]*(5*(n**2)-8*n+4))
# else:
#     print(sum(a)-max(a))

