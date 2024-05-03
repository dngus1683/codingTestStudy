# 물병
# 무한대로 물이 들어가는 물병이 n개 있음. 물병에는 1리터 씩 물이 차있음.
# 주어진 물을 다른 장소로 옮기려는데 한번에 k개의 병을 옮길 수 있음. (n>=k)
# 때문에 주어진 물을 k개의 물병에 재분배 해야 함.
# 재분배는 두 물병의 물 양이 같아야 한 쪽으로 물을 몰아 담을 수 있음.
# 위 규칙에 의해 재분배가 불가능하여 총 물병 양이 k개 보다 많을 경우, 새 물병을 살 수 있고 이 역시 1리터의 물이 담겨 있음.
# 새로 사는 물병의 개수를 구하라. (안사면 -1)

# 내 답안1
import sys

input = sys.stdin.readline

n, k = map(int, input().split())
n1 = n
n2 = n

ans = 0

for i in range(k):
    j = 0
    while n2 > 1:
        n2 //= 2
        j += 1
    n2 = n1-2**j
    if n2 == 0:
        ans = 0
        break
    n1 = n2
    ans = 2**j - n2

print(ans)




# 답안 예시1 -  https://deok2kim.tistory.com/317
# 문제 접근법이 중요하다.
# 뭔가 2진법같이 생겼다.
# 2진법으로 풀어보자

# N을 이진법으로 바꾸면 (ex, 11 => 1011)
# 물병: 1,1,1,1,1,1,1,1,1,1,1
# 합치기: 2,2,2,2,2,1
# 합치기: 4,4,2,1
# 합치기: 8,2,1
# 뭔가 규칙이 보인다.
# 결론: N을 이진법으로 바꾼 수의 1의 개수가
# 물을 최대로 합친 후의 물병의 개수이다.

# N, K = map(int, input().split())
#
# purchased_water_bottle_cnt = 0
#
# while bin(N).count('1') > K:
#     idx = bin(N)[::-1].index('1')
#     purchased_water_bottle_cnt += 2**idx
#     N += 2**idx
#
# print(purchased_water_bottle_cnt)
