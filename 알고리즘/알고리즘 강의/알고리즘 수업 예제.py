#####                     03.13 (월)                    #####

# 버블 정렬
# import random
# from timeit import default_timer as timer
#
# def bubble_sort(x):
#     for last in range(len(x)-1,0,-1):
#         sort = True
#         for i in range(last):
#             if x[i] > x[i+1]:
#                 x[i], x[i+1] = x[i+1], x[i]
#                 sort = False
#         if sort:
#             break
# def test(x):
#     for i in range(1, len(x)):
#         if x[i-1] > x[i]:
#             return False
#     return True
#
# x = random.sample(range(1000), 100)
#
# start = timer()
# bubble_sort(x)
# print(timer() - start)
# print(x)
# print(test(x))

# 병합 정렬
# import random
# from timeit import default_timer as timer
#
# def merge_sort(A,p,r):
#     if p < r:
#         q = (p+r)//2
#         merge_sort(A,p,q)
#         merge_sort(A,q+1,r)
#
#         i,j,t = p,q+1,0
#         tmp = A[:]
#         while i <= q and j <= r:
#             if A[i] <= A[j]:
#                 tmp[t] = A[i]
#                 i += 1
#             else:
#                 tmp[t] = A[j]
#                 j += 1
#             t += 1
#         while i <= q:
#             tmp[t] = A[i]
#             i += 1
#             t += 1
#         while j <= r:
#             tmp[t] = A[j]
#             j += 1
#             t += 1
#         i, t = p, 0
#         while i <= r:
#             A[i] = tmp[t]
#             i += 1
#             t += 1
#
# def test(x):
#     for i in range(1, len(x)):
#         if x[i-1] > x[i]:
#             return False
#     return True
#
# x = random.sample(range(1000), 100)
#
# start = timer()
# merge_sort(x,0,len(x)-1)
# print(timer() - start)
# print(x)
# print(test(x))






#####                     03.15 (수)                    #####

# 퀵정렬
# import random
# from timeit import default_timer as timer
#
# def quick_sort(A):
#     if len(A) <= 1:
#         return A
#     x = A[len(A) // 2]
#     less = []
#     more = []
#     equal = []
#     for a in A:
#         if a < x:
#             less.append(a)
#         elif a > x:
#             more.append(a)
#         else:
#             equal.append(a)
#     return quick_sort(less) + equal + quick_sort(more)
#
# def test(A):
#     for i in range(1, len(A)):
#         if A[i-1] > A[i]:
#             return False
#         return True
#
# x = random.sample(range(10000), 100)
# start = timer()
# x = quick_sort(x)
# print(timer() - start)
# print(x)
# print(test(x))





#####                     03.10 (월)                    #####
# 기수 정렬
# import random
# from timeit import default_timer as timer
#
# def rsort(A, m):
#     buckets = [[]for _ in range(10)]
#     for v in A:
#         index = v // (10**m)
#         index %= 10
#         buckets[index].append(v)
#     res = []
#     for bucket in buckets:
#         res.extend(bucket)
#     return res
#
# def radix_sort(A, k):
#     for i in range(0, k):
#         A = rsort(A, i)
#     return A
#
# def test(A):
#     for i in range(1, len(A)):
#         if A[i-1] > A[i]:
#             return False
#         return True
#
# x = random.sample(range(10000), 100)
# start = timer()
# x = radix_sort(x, 4)
# print(timer() - start)
# print(x)
# print(test(x))


# 계수 정렬
# import random
# from timeit import default_timer as timer
#
# def counting_sort(A,k):
#     B = [0] * len(A)
#     C = [0] * (k+1)
#     for v in A:
#         C[v] += 1
#     for i in range(1, k+1):
#         C[i] += C[i-1]
#     for i in range(len(A)-1, -1, -1):
#         v = A[i]
#         C[v] -= 1
#         B[C[v]] = v
#     return B
#
# def test(A):
#     for i in range(1, len(A)):
#         if A[i-1] > A[i]:
#             return False
#         return True
#
# x = random.choices(range(50), k=100)   # 0 ~ 49 범위에서 중복 허용하여 100개
# start = timer()
# x = counting_sort(x, 49)
# print(timer() - start)
# print(x)
# print(test(x))




#####                     03.22 (수)                    #####

# 선형 탐색 (순차 탐색)
# import random
# from timeit import default_timer as timer
#
# def sequential_search(x, value):
#     n = len(x)
#     for i in range(n):
#         if x[i] == value:
#             return i
#     return -1
#
# x = random.sample(range(5000), 1000)
# value = x[800]
#
# start = timer()
# index = sequential_search(x, value)
# print(timer() - start)
#
# print('value', value, 'found', index)
# print(True if index >= 0 and x[index] == value else False)


# # 이진 탐색
# import random
# from timeit import default_timer as timer
#
# def binary_search(x,v):
#     start = 0
#     end = len(x) -1
#     while start <= end:
#         mid = (start+end) // 2
#         if x[mid] == v: return mid
#         elif x[mid] < v: start = mid + 1
#         else: end = mid - 1
#     return -1
#
# x = random.sample(range(5000), 1000)
# x.sort()
# value = x[800]
#
# start = timer()
# index = binary_search(x, value)
# print(timer() - start)
#
# print('value', value, 'found', index)
# print(True if index >= 0 and x[index] == value else False)



#####                     04.12 (수)                    #####
# 너비우선탐색(BFS) - 길 찾기

import collections

class Queue(object):
    def __init__(self):
        self.elements = collections.deque()
    def length(self):
        return len(self.elements)
    def push(self, x):
        self.elements.append(x)
    def pop(self):
        return self.elements.popleft()

grid = [[0,0,0,0,0,0,0,0,0,0],
        [0,1,1,1,1,1,1,1,1,0],
        [0,1,0,0,0,0,1,0,1,0],
        [0,1,1,1,1,0,1,0,1,0],
        [0,0,1,0,1,0,1,1,1,0],
        [0,1,1,0,1,1,1,0,1,0],
        [0,0,0,0,0,0,0,0,0,0]]

start = (1, 5)
goal = (8, 1)

queue = Queue()
queue.push(start)
came_from = {}

while queue.length() > 0:
    current = queue.pop()

    if current == goal:
        break
    (x, y) = current
    candidates = [(x+1,y), (x,y-1), (x-1,y), (x,y+1)]
    for next in [(h,v) for h,v in candidates if grid[v][h] != 0]:
        if next not in came_from:
            queue.push(next)
            came_from[next] = current

currrent = goal
path = []
while currrent is not start:
    path.append(currrent)
    currrent = came_from[currrent]
path.reverse()
print(path)
