# 2017741009 장우현 과제04
# 피보나치 수열과 행렬 경로 문제 파이썬으로 구현


#####                    피보나치 수열 코드                     ######
import random
from timeit import default_timer as timer

n = random.randrange(1, 100)
f1 = [0] * (n+1)
f2 = [0] * (n+1)

# for문을 활용한 bottom up 방식의 피보나치 수열 함수
def fib1(n):
    f1[1] = f1[2] = 1
    for i in range(3, n+1):
        f1[i] = f1[i-1] + f1[i-2]
    return f1[n]

# 재귀함수를 활용한 top down 방식의 피보나치 수열 함수
def fib2(n):
    if f2[n] != 0:
        return f2[n]
    if n == 1 or n == 2:
        f2[n] = 1
    else:
        f2[n] = fib2(n-1) + fib2(n-2)
    return f2[n]
print('***** 피보나치 수열 *****')
print('n:', n, 'fib1:', fib1(n), 'fib2:', fib2(n), '\n')
#####                    피보나치 수열 코드                     ######





#####                    행렬 경로 문제 코드                     ######
graph = [random.sample(range(100), n+1) for _ in range(n+1)]
c1 = [[0 for _ in range(n+1)] for _ in range(n+1)]
c2 = [[0 for _ in range(n+1)] for _ in range(n+1)]

# for문을 활용한 bottom-up 방식의 행렬 경로
def matrix_path1(n):
    for i in range(n+1):
        c1[i][0] = 0
    for j in range(n+1):
        c1[0][j] = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            c1[i][j] = graph[i][j] + max(c1[i-1][j], c1[i][j-1])
    return c1[n][n]

# 재귀함수를 활용한 top-down 방식의 행렬 경로
def matrix_path2(i, j):
    if c2[i][j] != 0:
        return c2[i][j]
    if i == 0 or j == 0:
        return 0
    else:
        c2[i][j] = graph[i][j] + max(matrix_path2(i-1,j), matrix_path2(i,j-1))
    return c2[i][j]

print('***** 행렬 경로 문제 *****')
print('graph size: (', n, 'x', n, ') path1:', matrix_path1(n), 'path2:', matrix_path2(n, n), '\n')

#####                    행렬 경로 문제 코드                     ######



