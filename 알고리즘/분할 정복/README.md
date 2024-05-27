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
----
# 카라츠바의 빠른 정수 곱셈 알고리즘 (Karatsuba Algorithm)
카라츠바 알고리즘(Karatsuba Algorithm)은 큰 정수 곱셈을 효율적으로 수행하기 위한 분할 정복 알고리즘이다. 이 알고리즘은 곱셈의 계산 횟수를 줄여, 기존의 일반적인 곱셈 알고리즘보다 더 빠르게 계산할 수 있다.\

## Algorithm
카라츠바 알고리즘은 두 큰 수를 작은 부분으로 나누어 처리하고, 이를 통해 곱셈의 계산 횟수를 줄이는 분할 정복 알고리즘을 사용한다. 주어진 두 수 X와 Y를 각각 두 개의 부분으로 나눈 다음, 이 부분들의 곱을 재귀적으로 계산한다.

1. 두 수 X와 Y를 각각 다음과 같이 $X_1, X_2$와 $Y_1,Y_0$로 분할한다. 여기서 m은 수의 절반 길이를 나타낸다:
   
    + $X=X_1\cdot 10^m+X_0$
    + $Y=Y_1\cdot 10^m+Y_0$

    곱셈 $X\times Y$는 다음과 같이 계산된다:
    + $X \times Y = (X_1\cdot 10^m+X_0) \times (Y=Y_1\cdot 10^m+Y_0) = X_1X_0\cdot10^{2m}+(X_1Y_0 + X_0+Y_1)\cdot10^m + X_0Y_0$
  
   
2. $X_1Y_1$, $X_0Y_0$, 그리고 $(X_1+X_0)(Y_1+Y_0)$ 이 세 가지 곱셈을, 재귀적으로 계산하여 전체적인 계산을 최적화한다.
     + $Z_0=X_0 \times Y_0$
     + $Z_2=X_1\times Y_1$
     + $Z_1=(X_0+X_1)\times (Y_0+Y_1)-Z_0 -Z_2$
       
3. 최종 곱셈 결과를 조합한다.
     + X\times Y = Z_2\cdot10^2m+Z_1\cdot 10^m+Z_0
  
## 시간 복잡도
카라츠바 알고리즘의 시간 복잡도는 $O(n^{\log{3}})$이다. 이는 일반적인 곱셈 알고리즘의 시간 복잡도 $O(n^{2})$보다 효율적이다.

## Implementation
+ C++
  ```cpp
  // ***** 코드 출처: 프로그래밍 대회에서 배우는 알고리즘 문제해결전략 책 *****
  // a += b *(10^k) 구현
  void addTo(vector<int>& a, const vector<int>& b, int k);
  // a -= b 구현
  void subFrom(vector<int>& a, const vector<int>& b);
  // 카라츠바 알고리즘
  vector<int> karasuba(const vector<int>& a, const vector<int>& b)
  {
      int an = a.size(), bn = b.size();
      // a가 b보다 짧을 경우 둘을 바꿈
      if (an < bn) return karasuba(b, a);
      // 기저 사례: a나 b가 비어 있는 경우
      if (an == 0 || bn == 0) return vector<int>();
      // 기저 사례: a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경
      if (an <= 50) return multiply(a, b);
      int half = an / 2;
      // a와 b를 밑에서 half자리와 나머지로 분리
      vector<int> a0(a.begin(), a.begin() + half);
      vector<int> a1(a.begin() + half, a.end());
      vector<int> b0(b.begin(), b.begin() + half);
      vector<int> b1(b.begin() + half, b.end());
      // z2 = a1*b1
      vector<int> z2 = karasuba(a1, b1);
      // z0 = a0*b0
      vector<int> z0 = karasuba(a0, b0);
      // a0=a0+a1; b0=b0+b1
      addTo(a0, a1, 0); addTo(b0, b1, 0);
      // z1 = (a0*b0) - z0 - z2
      vector<int> z1 = karasuba(a0, b0);
      subFrom(z1, z0);
      subFrom(z1, z2);
      //ret=z0+z1*10^half+z2*10^(half*2)
      vector<int> ret;
      addTo(ret, z0, 0);
      addTo(ret, z1, half);
      addTo(ret, z2, half + half);
  
      return ret;
  }
  ```  
