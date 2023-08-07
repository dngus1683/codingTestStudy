# 2017741009 장우현 과제07
# 쉘 정렬을 파이썬으로 구현하여 제출
# 간격 h는 57, 23, 10, 4, 1로 줄여 가면서 정렬합니다.
# 숫자 100개를 임의로 생성하여 리스트에 넣고 구현한 쉘 정렬에 입력하여 정렬된 결과를 화면에 출력합니다.


import random

def shell_sort(arr, h):
    n = len(arr)

    for gap in h:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp

    return arr

h = [57, 23, 10, 4, 1]
numbers = [random.randint(1, 1000) for _ in range(100)]

sorted_numbers = shell_sort(numbers, h)

print(sorted_numbers)
