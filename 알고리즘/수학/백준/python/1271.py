# 엄청난 부자2
# n개의 돈을 m명에서 동등하게 나눠가질 때, 한사람 당 가져가는 돈과, 모두 나누고 남은 돈을 출력하라.


# 내 답안1
n,m = map(int, input().split())

print(n//m)
print(n%m)