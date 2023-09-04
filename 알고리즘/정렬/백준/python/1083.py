# 소트
# 크기가 N인 배열 A가 있다. 배열에 있는 모든 수는 서로 다르다.
# 이 배열을 소트할 때, 연속된 두 개의 원소만 교환할 수 있다.
# 교환은 많아봐야 S번 할 수 있다. 이때, 소트한 결과가 사전순으로 가장 뒷서는 것을 출력한다. (= 내림차순)


# 내 답안1
import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
Goal = sorted(A, reverse=True)
S = int(input())

cnt = S
for i in range(N):
    mx = 0
    idx = 0
    if cnt == 0:
        break
    if A[i] == Goal[i]:
        continue
    else:
        for j in range(1, cnt+1):
            if i+j == N:
                break
            elif A[i+j] > A[i] and A[i+j] > mx:
                mx = A[i+j]
                idx = j
        if mx != 0:
            A.remove(mx)
            A.insert(i, mx)
        cnt -= idx
print(*A)

