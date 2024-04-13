# 수학
+ [소수(prime number)](#소수)
+ [반올림](#반올림)
+ [최소 공배수 최대 공약수](#최소-공배수-최대-공약수)


## 소수
소수는 1이상의 자연수 중, 1과 자기 자신만을 약수로 갖는 수다.
### Implementation
+ C++
  ```c++
  // 에라토스테넷스의 체 - 소수의 정수배들을 모두 걸러내어 소수만 남기는 방법.
  int arr[N] = {0, };
           for(int i=2; i<=N; i++){
                if(arr[i] == 0){
                      for(int j=i*2; j<=N; j +=i){
                           arr[j] = 1;
                      }
                }
           }
  ```

## 반올림
<cmath> 헤더에 포함되어 있는 ceil(올림), floor(내림) 함수를 통해 반올림을 구현한다.
### Implementation
+ C++
  ```c++
  #include <cmath>
  // 반올림은 0.5 기준이므로, 0.5를 더해 내림으로 반올림을 구현.
  floor(N + 0.5);
   ```

## 최소 공배수 최대 공약수
최대 공약수(gcl)는 유클리드 호제법과 일반 정의를 통해 구할 수 있으며, 최소 공배수(lcm)는 (두 수의 곱) = (gcl * lcm)을 통해 구할 수 있다.

**유클리드 호제법**

유클리드 호제법(Euclidean Algorithm)은 두 정수의 최대 공약수(GCD, Greatest Common Divisor)를 구하는 알고리즘 중 가장 유명하고 효율적인 방법 중 하나다.

알고리즘은 다음과 같은 원리에 기반합니다:

1. 두 수 a와 b의 최대 공약수는 b와 a를 b로 나눈 나머지의 최대 공약수와 동일.
2. 즉, gcd(a, b) = gcd(b, a % b) .

이를 통해, 두 수를 나눈 나머지와 두 수 중 작은 수의 나머지를 구하는 재귀계산을 진행하여, 나머지가 0이 될 때의 작은 수가 최대 공약수가 된다.

### Implementation
+ C++
  ```c++
  // 최대 공약수(GCD)를 구하는 함수
  int gcd(int a, int b) {
      // 유클리드 호제법
      if (b == 0)
          return a;
      return gcd(b, a % b);

      // 정의를 통한 방법
      for (int i = 2; i <=a; i++)
    	{
    		if (a % i == 0 && b % i ==0)
    		{
      			return i;
    		}
    	}
  
  }
    
  // 최소 공배수(LCM)를 구하는 함수
  int lcm(int a, int b) {
      return (a * b) / gcd(a, b);
  }
  ```
