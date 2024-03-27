# Dynamic Programming

다이나믹 프로그래밍(Dynamic Programming)은 복잡한 문제를 간단한 여러 하위 문제로 나누어 푸는 알고리즘 기법이다. 주어진 문제가 여러 하위 문제로 나눌 수 있고, 이 하위 문제들이 서로 겹치는 부분 문제를 가질 때 다이나믹 프로그래밍을 적용할 수 있다. 
이 때 중복되는 하위 문제들을 한 번만 풀고 그 결과를 저장하여 중복 계산을 피한다.

## Algorithm
다이나믹 프로그래밍의 주요 아이디어는 주어진 문제를 작은 부분 문제로 나누고, 각 부분 문제의 최적해를 구하여 이를 조합하여 전체 문제의 최적해를 찾는 것이다. 
이를 위해 Top-down(메모이제이션(Memoization)) 또는 Bottom-UP 방식을 사용한다.

### Top-Down (메모이제이션)
1. 문제를 하위 문제들로 나눈다.
2. 각 하위 문제의 최적해를 구할 때 이전에 구한 값을 저장하고 재활용한다.

    재귀함수를 활용하여 구현한다.

### Bottom-Up
1. 작은 부분 문제부터 시작하여 큰 문제로 해결 방향을 진행한다.
2. 이전에 구한 값을 활용하여 현재 문제의 최적해를 계산한다.

     반복문을 활용하여 구현한다.


## Pseudocode

### Top-Down
```
function DP_TopDown(state):
    if state is in memo:
        return memo[state]
    if state is a base case:
        return base case value
    calculate state's value recursively
    memo[state] = state's value
    return state's value

```


### Botton-Up
```
function DP_BottomUp():
    initialize memo table
    for each subproblem size:
        for each subproblem state:
            calculate subproblem state's value using previously calculated values
    return memo table
```

## Complexity
+ 시간 복잡도: O(n) ~ O(n^3)
+ 공간 복잡도: O(n) ~ O(n^3)

## Implementation
+ ### C++
  
    #### Top-Down
    ```c++
    int fibonacci(int n) {
        vector<int> dp(n + 1);
    
        // 초기값 설정
        dp[0] = 0;
        dp[1] = 1;
    
        // 다이나믹 프로그래밍을 통해 피보나치 수열 계산
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    
        return dp[n];
    }
    ```


    #### Bottom-Up
    ```c++
    // 메모이제이션을 위한 배열 초기화
    vector<int> memo(n + 1, -1);
    
    int fibonacci(int n, vector<int>& memo) {
        // 기저 사례: n이 0 또는 1인 경우
        if (n <= 1) {
            return n;
        }
    
        // 이미 계산된 값이 있다면 그 값을 반환
        if (memo[n] != -1) {
            return memo[n];
        }
    
        // 탑다운 방식으로 피보나치 수열 계산
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    
        return memo[n];
    }
    ```
