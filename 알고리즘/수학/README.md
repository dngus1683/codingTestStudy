# 수학
+ [소수(prime number)](#소수(prime number))



## 소수(prime number)
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
