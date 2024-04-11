# 수학
+ [소수(prime number)](#소수)



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
