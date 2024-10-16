# 수학
+ [소수(prime number)](#소수)
+ [반올림](#반올림)
+ [최소 공배수 최대 공약수](#최소-공배수-최대-공약수)
+ [분할 정복을 이용한 거듭제곱](#분할-정복을-이용한-거듭제곱)
+ [피보나치 수열](#피보나치-수열)
+ [모듈러(modular)](#모듈러)
+ [중국인의 나머지 정리](#중국인의-나머지-정리)


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
~~cmath 헤더에 포함되어 있는 ceil(올림), floor(내림) 함수를 통해 반올림을 구현한다.~~
### Implementation
+ C++
  ```c++
  #include <cmath>
  // 반올림은 0.5 기준이므로, 0.5를 더해 내림으로 반올림을 구현.
  floor(N + 0.5);
   ```
  확인 결과, <cmath> 해더에 round()함수가 포함되어 있다. 때문에 반올림 시 round() 함수를 사용하면 된다.
  

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



## 분할 정복을 이용한 거듭제곱
[분할 정복 페이지 참조](https://github.com/dngus1683/codingTestStudy/tree/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EB%B6%84%ED%95%A0%20%EC%A0%95%EB%B3%B5)



## 피보나치 수열
피보나치 수열(Fibonacci Sequence)은 각 항이 그 앞의 두 항의 합인 수열이다. 13세기 이탈리아의 수학자 레오나르도 피보나치(Leonardo Fibonacci)의 책, "Liber Abaci"에서 소개하였으며, 이로 인해 피보나치 수열이라고 불린다.

### Definition
+ $F(0)=0$
+ $F(1)=1$
+ $F(n)=F(n-1)+F(n-2)\  \text{for} \ n\geq 2$

### Implementation
1. **재귀적 계산**

   피보나치 수열의 정의를 활용한 방법
   ```c++
   int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
   }
   ```
2. **DP** 

   재귀적 방법으로 모든 피보나치 값을 계산하다보면 중복되는 계산이 생기며, 이로 인해 불필요한 계산시간이 소모된다. (ex. F(4) = F(3)+F(2), F(5)=F(4)+F(3) => 두 식 모두 F(3)을 계산한다.)
   때문에 한 번 계산한 값들을 메모이제이션하여 계산 시간을 줄인다.
   ```c++
   int fibonacci(int n) {
        if (n <= 1) return n;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
   }
   ```
3. **분할 정복을 이용한 거듭제곱**

   만약 F(n)에서 n의 값이 매우 크다면, 아무리 동적 계획법으로 계산을 해도 처음부터 n번까지의 계산으로는 시간이 너무 오래걸리며 메모리 소모 역시 심하다. 이를 해결할 수 있는 방법으로는 [분할 정복을 이용한 거듭제곱](#분할-정복을-이용한-거듭제곱)이 있다.

   피보나치 수열을 행렬 형태로 나타내면 다음과 같은 관계를 얻을 수 있다.


    $$C(i) =\begin{bmatrix} F(i-1) \\  F(i) \end{bmatrix}$$
    $$C(i+1) =\begin{bmatrix} F(i) \\ F(i+1) \end{bmatrix} =
    \begin{bmatrix} F(i) \\ F(i) + F(i-1) \end{bmatrix} =
    \begin{bmatrix} 0 & 1 \\ 1 & 1 \end{bmatrix} C(i)$$
    여기서, C(i)에 곱해지는 행렬을 W라 한다면,
    $$W =\begin{bmatrix}0 & 1 \\ 1 & 1 \end{bmatrix}$$
    따라서 C(i+1)과 C(i)사이의 관계식은 다음과 같이 정리할 수 있다. 이때 초기조건은 $C(1) =\begin{bmatrix} 0 \\ 1 \end{bmatrix}$이다.
    $$C(i+1) = W^i \cdot C(1)$$
    이를 통해 행렬 W의 거듭제곱을 계산해 C(1)에 곱하면 윈하는 피보나치 값이 포함된 행렬 C를 구할 수 있다.





## 모듈러
### 모듈러 곱셈의 역원

모듈러 곱셈의 역원은 주어진 수 a에 대해 다음 조건을 만족하는 수 b를 의미한다:

$$a \cdot b \equiv 1 \mod m$$

모듈러 곱셈의 역원은 페르마의 소정리와 확장 유클리드 알고리즘으로 구할 수 있다.

### 확장 유클리드 알고리즘 (Extended Euclidean Algorithm)

확장 유클리드 알고리즘은 두 정수 a와 b의 최대공약수(GCD)와, [선형 디오판토스 방정식](https://ko.wikipedia.org/wiki/%EB%94%94%EC%98%A4%ED%8C%90%ED%86%A0%EC%8A%A4_%EB%B0%A9%EC%A0%95%EC%8B%9D) $ax + by = \gcd(a, b)$의 해 $(x, y)$를 찾는 알고리즘이다.

#### Algorithm

유클리드 알고리즘은 다음과 같은 일련의 나눗셈을 통해 GCD를 구한다:

$$
\begin{align*}
a &= bq_1 + r_1 \\
b &= r_1q_2 + r_2 \\
r_1 &= r_2q_3 + r_3 \\
&\vdots \\
r_{n-2} &= r_{n-1}q_n + r_n \\
r_{n-1} &= r_nq_{n+1} + 0 \\
\end{align*}
$$

여기서 $r_n$이 0이 되는 순간의 $r_{n-1}$이 $\gcd(a, b)$가 되며, 확장 유클리드 알고리즘은 역추적을 통해 $(x, y)$를 구한다.

#### 예시

#### case 1) a = 56 , b = 15

1. 유클리드 알고리즘을 적용하여 GCD를 구한다:
   $$
   \begin{align*}
   56 &= 15 \cdot 3 + 11 \\
   15 &= 11 \cdot 1 + 4 \\
   11 &= 4 \cdot 2 + 3 \\
   4 &= 3 \cdot 1 + 1 \\
   3 &= 1 \cdot 3 + 0 \\
   \end{align*}
   $$
   따라서, $gcd(56, 15) = 1$.

2. 역추적을 통해 $(x, y)$를 구한다:
   $$
   \begin{align*}
   1 &= 4 - 3 \cdot 1 \\
     &= 4 - (11 - 4 \cdot 2) \\
     &= 4 \cdot 3 - 11 \\
     &= (15 - 11) \cdot 3 - 11 \\
     &= 15 \cdot 3 - 11 \cdot 4 \\
     &= 15 \cdot 3 - (56 - 15 \cdot 3) \cdot 4 \\
     &= 15 \cdot 15 - 56 \cdot 4 \\
   \end{align*}
   $$
   따라서, $(x, y) = (-4, 15)$.

#### 모듈러 곱셈의 역원 구하기

1. 두 정수 a와 b가 주어지면, a와 b의 최대공약수 $\gcd(a, b)$를 구한다.
2. a와 b의 최대공약수가 1이라면, 선형 디오판토스 방정식 $ax + by = 1$의 해를 구한다.
3. 나눗셈과 나머지 연산을 통해 $a = bq + r$의 형태로 줄여간다.
4. $r = 0$이 될 때까지 반복한다.
5. 역추적을 통해 x와 y를 구한다.


### 페르마의 소정리

페르마의 소정리는 다음과 같이 정의된다:

임의의 소수 p와 p의 배수가 아닌 정수 a에 대해,

$$a^{p-1} \equiv 1 \mod p$$

이를 변형하면, a의 모듈로 p에 대한 곱셈 역원을 구할 수 있다:

$$a^{p-2} \equiv a^{-1} \mod p$$

+ **모듈러 곱셈 역원 계산 예시**

  #### 예시: a = 3, m = 7
  
    1. p = 7은 소수.
    2. a = 3에 대해, $a^{p-2} = 3^{7-2} = 3^5$ 계산.
    3. $3^5$를 모듈로 7로 나눈 값을 계산.
    
    $$3^5 = 243 \implies 243 \mod 7 = 5$$
    
    따라서, 3의 모듈러 7에 대한 곱셈 역원은 5다.
    
## 중국인의 나머지 정리
중국인의 나머지 정리(Chinese Remainder Theorem, CRT)는 정수론에서 중요한 정리 중 하나로, 여러 mod 연립 일차 합동방정식을 해결하는 방법이다. 이 정리는 임의의 서로소인 계수 m1, m2, ..., mk를 가지고 있는 경우에 대해 일반적인 해를 찾을 수 있게 한다.

### Charateristic
+ 중국인의 나머지 정리는 서로소인 계수에 대한 일차 합동방정식을 해결할 때 유용하다.
+ 각 계수가 서로소일 때만 적용 가능하다.
+ 해가 존재하고 유일하다는 것을 보장한다.

### Definition
주어진 일차 합동방정식의 집합은 다음과 같은 형태를 가진다.

$$
\begin{aligned}
x &\equiv a_1 \ (mod\  m_1) \\ 
x &\equiv a_2 \ (mod\  m_2) \\
x &\equiv a_3 \ (mod\  m_3) \\
\vdots \\
x &\equiv a_k \ (mod\  m_k)
\end{aligned}
$$

여기서 x는 구하고자 하는 해, (a1, a2, ..., a_k)는 각 모듈로(법)에 대한 나머지 값이며, m1, m2, ..., m_k는 각 모듈로(법)의 값이다. 중국인의 나머지 정리는 이러한 일차 합동방정식 집합에 대한 해가 존재하고 유일하다는 것을 보여준다.

### Solution
중국인의 나머지 정리를 사용하여 해를 찾는 방법은 다음과 같다.
1. 각 모듈로 m1, m2, ..., m_k의 최소 공배수를 구하고, 이를 M이라 한다.
2. 모듈로 $m_i$에 대한 $M/m_i$ 값을 구하고, 이를 $t_i$라 한다.
3. 모듈로 $m_i$에 대한 역원 $t_i{^-1}$을 구한다.
4. 해 x는 다음과 같이 계산된다.
   
$$ x = (a_1 \cdot t_1 \cdot t^{-1}_1+a_2 \cdot t_2 \cdot t^{-1}_2+ \dots + a_k \cdot t_k \cdot t^{-1}_k)\ mod \ M $$

5. x가 M보다 큰 경우, 계수 M으로 나머지를 취한다.

### 예시
$$
\begin{aligned}
x &\equiv 2 \ (mod\  3) \\ 
x &\equiv 3 \ (mod\  5) \\
x &\equiv 2 \ (mod\  7) \\
\end{aligned}
$$

위 식에 대해서 일차 합동 방정식의 해를 구하는 경우,

$$
\begin{aligned}
&M = lcm(3,5,7) = 105\\
&t_1=M \div 3 = 35, \ t_2=M \div 5 = 21, \ t_3=M \div 7 = 15\\
&t^{-1}_1 \equiv 2 \ (mod \ 3), \ t^{-1}_2 \equiv 1 \ (mod \ 5), \ t^{-1}_3 \equiv 1 \ (mod \ 7)\\
&x = (2 \cdot 35 \cdot 2+ 3 \cdot 21 \cdot 1+ 2 \cdot 15 \cdot1) \ mod \ 105 = 23
\end{aligned}
$$


### Implementation
+ C++
  ```c++
  #include <iostream>
  #include <vector>
  
  using namespace std;
  
  // 계수 m에 대한 역원을 계산하는 함수
  int modInverse(int a, int m) {
      int m0 = m, tmp, q;
      int x0 = 0, x1 = 1;
  
      if (m == 1)
          return 0;
  
      while (a > 1) {
          // q는 몫, tmp는 임시 변수
          q = a / m;
          tmp = m;
          
          // mod 연산을 수행한다.
          m = a % m, a = tmp;
          tmp = x0;
  
          // 확장 유클리드 알고리즘을 통해 역원을 계산한다.
          x0 = x1 - q * x0;
          x1 = tmp;
      }
  
      // x1이 음수일 경우 m을 더해준다.
      if (x1 < 0)
          x1 += m0;
  
      return x1;
  }
  
  // 중국인의 나머지 정리를 이용하여 일차 합동방정식을 해결하는 함수
  int chineseRemainder(vector<int>& num, vector<int>& rem) {
      int prod = 1; // 계수 m1, m2, ..., mk의 곱을 저장한다.
      int result = 0;
  
      // 계수들의 곱을 계산한다.
      for (int i = 0; i < num.size(); i++)
          prod *= num[i];
  
      // 각 항목에 대한 결과를 계산한다.
      for (int i = 0; i < num.size(); i++) {
          int pp = prod / num[i]; // 모듈로 m/mi의 값
          result += rem[i] * modInverse(pp, num[i]) * pp;
      }
  
      // 결과가 음수일 경우 계수의 곱을 더해주어 양수로 만든다.
      result %= prod;
      if (result < 0)
          result += prod;
  
      return result;
  }
  
  int main() {
      vector<int> num = {3, 5, 7}; // 계수 m1, m2, m3
      vector<int> rem = {2, 3, 2}; // 나머지 a1, a2, a3
  
      int result = chineseRemainder(num, rem);
      cout << "Solution x is: " << result << endl;
  
      return 0;
  }

  ```