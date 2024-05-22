# 분할 정복
분할 정복(Divide and Conquer)은 재귀적인 방법을 통해 문제를 해결하는 알고리즘 설계 기법이다. 큰 문제를 작은 부분 문제로 나눈 다음, 각 부분 문제를 해결하여 전체 문제의 해를 구하는 방식이다. 주로 재귀 호출을 사용하여 구현된다.


## Algorithm
**1. 분할(Divide):** 주어진 문제를 더 작은 부분 문제로 나눈다. 보통 문제를 두 개 이상의 하위 문제로 분할한다.

**2. 정복(Conquer):** 각 부분 문제를 재귀적으로 해결한다. 부분 문제의 크기가 충분히 작아서 직접 해결할 수 있는 경우에는 재귀 호출을 멈춘다.

**3. 통합(Combine):** 각 부분 문제의 해를 통합하여 전체 문제의 해를 구한다. 이 단계에서 필요한 경우 부분 문제의 해를 결합하거나 수정한다.


## 시간 복잡도
+ 분할: O(1) (상수 시간)
+ 정복: O(log n) (재귀 호출의 깊이)
+ 병합: O(n) (배열 병합)
  
따라서 합병 정렬의 전체 시간 복잡도는 O(n log n).


## Implementation
+ C++
  
  + [예시 문제](https://github.com/dngus1683/codingTestStudy/blob/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EB%B6%84%ED%95%A0%20%EC%A0%95%EB%B3%B5/%EB%B0%B1%EC%A4%80/C%2B%2B/2630.cpp)
  
  + **분할 정복 거듭제곱**

    거듭제곱의 지수가 굉장히 크면 최악의 경우 시간 복잡도가 O(n)임에도 시간이 부족할 수 있다. 이를 방지하기 위해 분할 정복을 활용하여 거듭제곱의 계산 시간을 줄인다.

    + 수식
  
      > 짝수 지수 \( n \)에 대한 재귀 관계: $a^n = (a^{n/2})(a^{n/2}) \quad \text{(if \( n \) is even)}$      
      > 홀수 지수 \( n \)에 대한 재귀 관계: $a^n = (a^{(n-1)/2})(a^{(n-1)/2})a \quad \text{(if \( n \) is odd)}$

    + 코드
      ```c++
      int divide(int a, int n)
      {
      	if (x == 1 || x == 0)
      		return a;
      	else
      	{
      		ullint value = divide(n / 2);
      		if (a % 2 == 0)
      		{
      			return (value * value);
      		}
      		else
      		{
      			return ((value * value) * a);
      		}
      	}
      }
      ``` 
