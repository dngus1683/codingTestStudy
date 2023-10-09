# 팰린드롬 만들기
# 팰린드롬 - 좌우대칭 문자열(오름내림차순)
# 문자가 주어지면 팰린드롬으로 바꿔 출력하라. 이때 팰린드롬으로 만들지 못한다면 'I'm Sorry Hansoo'를 출력하라.


# 내 답안1
import sys

input = sys.stdin.readline

li = input().rstrip()
num = [0] * 26

for l in li:
    num[ord(l)-64] += 1

odd = 0
cnt = 0
for i, n in enumerate(num):
    if n % 2 == 1:
        cnt += 1
        odd = i

def array(num, cnt, odd):
    l = 0
    r = len(li)
    s = [0]*len(li)
    if cnt == 1:
        s[len(li)//2] = chr(odd+64)
        num[odd] -= 1
    for i, n in enumerate(num):
        c = n // 2
        s[l:l+c+1] = chr(i+64)*c
        s[r-c:r] = chr(i+64)*c
        l += c
        r -= c
    return s

if (len(li) % 2 == 1 and cnt != 1) or (len(li) % 2 == 0 and cnt > 0):
    print('Im Sorry Hansoo')
else:
    print(
        ''.join(array(num, cnt, odd))
    )


