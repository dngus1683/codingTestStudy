# 무지의 먹방 라이브
# 음식을 하나 먹는데 걸리는 시간이 N개 주어진다고 하자. 한 음식을 1초동안만 먹을 수 있고, 1초 뒤에는 다음 순번의 음식을 먹게 된다. k초 뒤, 먹는 것이 중단 되었다가
# 다시 먹기 시작할 때, 몇 번째 음식부터 다시 먹기 시작하면 되는지 구하라.
# https://school.programmers.co.kr/learn/courses/30/lessons/42891?language=python3 에서 실행 결과 확인 가능.


# 내 답안1
# 채점 결과
# 정확성: 20.1
# 효율성: 0.0
# 합계: 20.1 / 100.0

# def solution(food_times, k):
#     answer = 0
#     length = len(food_times)
#     i = length
#     while k > 0:
#         if food_times[i % length] >= 1:
#             food_times[i % length] -= 1
#             k -= 1
#             i += 1
#             answer = (i+1) % length
#         else:
#             food_times[i % length] = -1
#             i += 1
#         if sum(food_times) == -1 * length:
#             answer = -1
#             break
#
#
#
#     return answer
#





























# 답안 예시
# heapq를 활용한 답안. 자세한 풀이는 교제 참조

import heapq

def solution(food_times,k):
    # 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
    if sum(food_times) <= k:
        return -1

    # 시간이 작은 음식부터 빼야 하므로 우선순위 큐를 이용
    q = []
    for i in range(len(food_times)):
        # (음식 시간, 음식 번호) 형태로 우선순위 큐에 삽입
        heapq.heappush(q, (food_times[i], i + 1))

    sum_value = 0  # 먹기 위해 사용한 시간
    previous = 0  # 직전에 다 먹은 음식 시간

    length = len(food_times)  # 남은 음식의 개수

    # sum_value + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
    while sum_value + ((q[0][0] - previous) * length) <= k:
        now = heapq.heappop(q)[0]
        sum_value += (now -previous) * length
        length -= 1  # 다 먹은 음식 제외
        previous = now  # 이전 음식 시간 재설정

    # 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
    result = sorted(q, key= lambda x: x[1])  # 음식의 번호 기준으로 정렬
    return result[(k - sum_value) % length]

