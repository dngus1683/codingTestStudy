# 2017741009 장우현 과제05
# 위상 정렬 2 파이선 구현


# 수업 자료에 있는 예시 입력

# 0: 냄비에 물 붓기
# 1: 점화
# 2: 라면 넣기
# 3: 계란 넣기
# 4: 라면 봉지 뜯기
# 5: 수프 넣기
"""
6
0 1 0 0 0 0
0 0 1 1 0 1
0 0 0 1 0 0
0 0 0 0 0 0
0 0 1 0 0 1
0 0 0 0 0 1
"""
# 유향 그래프 정점 갯수 입력
n = int(input())
# 유향 그래프 정보 입력
graph = [list(map(int, input().split())) for _ in range(n)]


visited = []
ans = [0 for _ in range(n)]
cnt = n-1

def topological_sort(g):
    for i in range(n):
        visited.append(False)
    for v in range(n):
        if visited[v] is False:
            DFS(v)

def DFS(v):
    global cnt
    visited[v] = True
    for x in range(n):
        if graph[v][x] == 1 and visited[x] is False:
            DFS(x)
    ans[cnt] = v
    cnt -= 1


topological_sort(graph)
print(ans)
