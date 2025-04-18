# 자료 구조
+ [queue](#queue)
+ [stack](stack)
+ [map](#map)
+ [deque](#deque)
+ [hash](#hash)
+ [tree](https://github.com/dngus1683/codingTestStudy/tree/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EC%9E%90%EB%A3%8C%20%EA%B5%AC%EC%A1%B0/%ED%8A%B8%EB%A6%AC/%EB%B0%B1%EC%A4%80)

+ 공통
  
  + **size()와 empty():** 반복문의 조건으로 'STL 컨테이너의 원소 유무'를 사용할 때, size()를 사용한다면 해당 컨테이너의 원소 개수를 직접 세야 하므로 시간 복잡도가 O(n)이 되며, 이는 시간 초과가 날 수 있다. 반면 empty()는 O(1)의 시간 복잡도를 가지므로 empty()를 사용하는 것이 시간적으로 경제적이다.
  
## queue
큐(Queue)는 데이터를 일시적으로 저장하는 자료 구조로, 데이터의 삽입은 한쪽 끝(rear 또는 back)에서 이루어지고, 데이터의 삭제는 반대쪽 끝(front 또는 head)에서 이루어지는 선입선출(FIFO, First-In-First-Out) 형태를 가지고 있다.

### Implementation
+ C++
  
   C++ 표준 라이브러리(STL)에서는 <queue> 헤더를 통해 큐를 지원하고 있습니다. 이를 이용하여 큐를 구현하고 사용할 수 있습니다.

  **C++ STL Queue 기능**
  
  **1. push():** 큐의 뒷쪽(rear)에 요소를 추가한다.
  
  **2. pop():** 큐의 앞쪽(front)에서 요소를 제거한다.
  
  **3. front():** 큐의 맨 앞에 있는 요소를 반환한다.
  
  **4. back():** 큐의 맨 뒤에 있는 요소를 반환한다.
  
  **5. empty():** 큐가 비어 있는지 확인한다.
  
  **6. size():** 큐에 저장된 요소의 개수를 반환한다.




## stack
스택(Stack)은 후입선출(LIFO, Last-In-First-Out) 방식으로 데이터를 저장하는 자료 구조다.

### Implementation
+ C++
  
  C++ 표준 라이브러리(STL)에서는 <stack> 헤더를 통해 스택을 지원하고 있으며, 이를 이용하여 스택을 구현하고 사용할 수 있다.

  **C++ STL Stack 기능**
  
  **1. push():** 스택의 맨 위(top)에 요소를 추가한다.
  
  **2. pop():** 스택의 맨 위(top)에서 요소를 제거한다.
  
  **3. top():** 스택의 맨 위에 있는 요소를 반환한다.
  
  **5. empty():** 스택이 비어 있는지 확인한다.

  **6. size():** 스택에 저장된 요소의 개수를 반환한다.


## map
맵(map)은 키(key)와 값(value)을 연관시켜 저장하는 자료 구조로, 키를 기준으로 값에 접근할 수 있다. 맵은 키-값 쌍을 저장하며, 각 키는 유일해야 한다. 맵은 키에 대한 자동 정렬을 제공하며, 이진 탐색 트리(Binary Search Tree) 기반으로 구현되어 있어 검색, 삽입, 삭제 등의 연산이 빠르다. 따라서 검색과 같은 기능의 시간 복잡도는 O(logn)이다.

### Implementation
+ C++
  
  C++ 표준 라이브러리(STL)에서는 <map> 헤더를 통해 맵을 지원하고 있으며, 이를 이용하여 맵을 구현하고 사용할 수 있다.
  
  **C++ STL Map 기능**
  
  **1. insert():** 맵에 새로운 요소를 추가한다.
  
  **2. erase():** 맵에서 특정 키를 가진 요소를 제거한다.
  
  **3. find():** 맵에서 특정 키를 검색한다.
  
  **4. count():** 맵에서 특정 키의 존재 여부를 확인한다.
  
  **5. size():** 맵에 저장된 요소의 개수를 반환한다.
  
  **6. empty():** 맵이 비어 있는지 확인한다.
  
  **7. begin(), end():** 맵의 시작과 끝을 가리키는 반복자(iterator)를 반환한다.


  + **값에 접근**

    find()함수는 특정 키를 검색해 해당 하는 키-값 쌍의 반복자 즉, 주소값을 반환한다. 때문에 해당 주소에 arrow 연산자(->)를 통해 키, 값에 접근한다.
      ```c++
      map<string, int> m;
      
      int key = m.find("apple")->first;
      int value = m.find("apple")->second;
      ```
  + **키 존재 유무**

     해당 맵에 특정 키 값이 존재하는 지 확인하기 위해서 find()와 end() 함수를 사용한다. find()는 특정 키를 검색했을 때, 해당 키가 맵에 존재하지 않는다면 end() 반복자를 반환한다.
      ```c++
      if(m.find("apple") != m.end()) cout << "apple 키 존재" << endl;
      else cout << "apple 키 없음" << endl;
      ```


## deque
덱(deque)은 Double-Ended Queue의 약어로, 큐(Queue)와 스택(Stack)의 특성을 모두 가지고 있는 자료 구조다. 덱은 양쪽 끝에서 삽입과 삭제가 모두 가능하며, 중간에 요소를 삽입하거나 삭제하는 것도 가능하다.

### Implementation
  + C++
    
    C++ 표준 라이브러리(STL)에서는 <deque> 헤더를 통해 덱을 지원하고 있으며, 이를 이용하여 덱을 구현하고 사용할 수 있다.

    **C++ STL Deque 기능**
  
    **1. push_back():** 덱의 뒤쪽에 요소를 추가한다.
    
    **2. push_front():** 덱의 앞쪽에 요소를 추가한다.
    
    **3. pop_back():** 덱의 뒤쪽에서 요소를 제거한다.
    
    **4. pop_front():** 덱의 앞쪽에서 요소를 제거한다.
    
    **5. back():** 덱의 마지막 요소를 반환한다.
    
    **6. front():** 덱의 첫 번째 요소를 반환한다.
    
    **7. size():** 덱에 저장된 요소의 개수를 반환한다.
    
    **8. empty():** 덱이 비어 있는지 여부를 확인한다.

    **9. insert():** 덱의 임의의 위치에 요소를 추가한다.


    + **덱 중간에 요소 추가**
      
      insert() 함수를 사용하여 중간에 요소를 삽입할 수 있다.
      ```c++
      #include <iostream>
      #include <deque>
      
      int main() {
          std::deque<int> dq = {1, 2, 4, 5};
      
          // 덱의 3번째 위치에 요소 3 삽입
          dq.insert(dq.begin() + 2, 3);
      
          // 덱 출력
          for (int x : dq) {
              std::cout << x << " ";
          }
          std::cout << std::endl;
      
          return 0;
      }
      ```



## hash
해시(hash)는 데이터를 효율적으로 저장하고 검색하기 위한 자료 구조다. 해시 함수를 사용하여 데이터의 키(key)를 해시 값(hash value)으로 변환하고, 이 해시 값을 인덱스로 사용하여 데이터를 저장하거나 검색한다. 해시 함수는 입력으로 받은 데이터를 고정된 길이의 해시 값으로 매핑한다.

### 해시 함수 (Hash Function)
해시 함수는 다음과 같은 속성을 가져야 한다.

+ **일관성(Consistency):** 동일한 입력에 대해 항상 동일한 해시 값을 반환한다.
+ **고유성(Uniqueness):** 서로 다른 입력에 대해 고유한 해시 값을 반환한다.
+ **충돌 최소화(Minimized Collisions):** 서로 다른 입력이 같은 해시 값을 가질 확률을 최소화한다.

  #### 해시 함수 종류
  + **숫자**

    **1. 나머지 함수**
      
       
      + **알고리즘**

        입력값을 특정한 수로 나눈 나머지를 해시 값으로 선택한다.
      
        h(x) = x mod m  (m: 일반적으로 소수 사용)

      + **예시**
      
        입력값이 1234이고 나눌 수를 13으로 한다면, 해시 값은 1234를 13으로 나눈 나머지인 12가 된다.

    **2. 곱하기 함수**
       
       + **알고리즘**

         입력값에 특정 수(a)를 곱한 후 소수점 아래만 얻어, 그 결과에 특정 수(m)을 곱한 수 정수 부분만 선택한다.
        
         h(x) = floor(m * ((x * a) mod 1))  (a: 0<a<1)

       + **예시**
      
         입력값이 1,025,390, a는 0.6180339, m은 65,536일 때, x * a = @.871, 이 갑에서 소수점 아래만 얻어 m을 곱하면, 57,125.@ . 이 값에서 정수 부분만 얻으면 57,125가 된다.

    **3. Shift Folding Function**
     
      + **알고리즘**
       
        해시 테이블 크기를 정해, 입력값을 그 크기를 기준으로 여러 그룹으로 나누고 합산한 결과를 해시 값으로 선택한다.
    
      + **예시**
    
        해시 테이블 크기가 3이고 입력값이 1234512345 이라면, Shift Folding 함수는 다음과 같은 과정을 거친다.
        
        123 + 451 + 234 + 5 = 813
      
        만약, 결과값이 해시 테이블 크기를 벗어나서 자리 수를 넘어가면 해당 부분은 잘라낸다.

    **4. Boundary Folding Function**

      + **알고리즘**
    
        해시 테이블 크기를 정해, 입력값을 그 크기를 기준으로 여러 그룹으로 나누고 합산한 결과를 해시 값으로 선택한다. 이때, 해당 그룹들을 하나씩 건너뛰면서 해당 값들을 거꾸로 뒤집어 계산한다.
    
      + **예시**
    
        해시 테이블 크기가 3이고 입력값이 1234512345 이라면, Boundary Folding 함수는 다음과 같은 과정을 거친다.
      
        321 + 451 + 432 + 5 = 1209 -> (해시 테이블 크기가 3 이므로 1을 버린다)  -> 209

    **5. 중간제곱 함수**
      
      + **알고리즘**
    
        해시 테이블 크기를 정해, 입력값을 제곱한 후, 그 결과에서 중간에 위치한 해시 테이블 크기만큼을 해시 값으로 선택하는 방식이다.
      
    
      + **예시**
    
        해시 테이블 크기가 4이고 입력값이 9451이면, 다음과 같은 과정을 거친다.
      
        9451 * 9451 = 89321401 -> (중간 4자리 추출) -> 3214
          
  + **문자열**
 
    **1. 첫 번째 문자 이용**

       + **알고리즘**

         첫 번째 문자의 아스키 코드 값 활용
      
    
      + **예시**

        ABC -> 65 (A의 아스키 코드)

    **2. 문자열 코드 값 더하기**
  
      + **알고리즘**
      
        문자열의 모든 문자의 아스키 코드 값의 합 활용
        
      
      + **예시**
  
        ABC -> 65 + 66 + 67 = 198

    **3. 자리 수 곱하기**
  
      + **알고리즘**
      
        문자열의 모든 문자의 아스키 코드 값에 각 자리 수를 곱한 값의 합 활용
        
      + **예시**
  
        ABC -> (65 * 31 * 31) + (66 * 31) + 67 = 64,578
    

      

### 해시 테이블 (Hash Table)
해시 테이블은 해시 함수를 사용하여 데이터를 저장하는 자료 구조다. 보통 배열을 기반으로 하며, 각 요소는 해시 값에 따른 버킷(bucket)에 저장된다. 충돌(Collision)이 발생할 수 있으므로 충돌을 해결하기 위한 방법이 필요하다.

### 충돌 해결 (Collision Resolution)
충돌은 서로 다른 데이터가 같은 해시 값에 매핑되는 경우다. 충돌을 해결하는 방법에는 다음과 같은 것들이 있다.

+ **개방 주소법(Open Addressing):** 충돌이 발생한 경우, 다른 빈 버킷을 찾아 데이터를 삽입한다. 선형 탐색, 이차 탐색, 이중 해싱 등의 방법이 있다.
+ **체이닝(Chaining):** 각 버킷에 연결 리스트를 사용하여 충돌한 데이터들을 저장한다.

### Implementation
  + C++
    
    C++ 표준 라이브러리(STL)에서는 <unordered_map>, <unordered_set> 헤더를 통해 해시를 지원하고 있으며, 이를 이용하여 해시를 구현하고 사용할 수 있다. unordered_map<key, value>는 키 뿐만 아니라 값까지 저장할 수 있으며, unordered_set<key>는 키 값만 가지므로, 해당 키의 유무를 판단하는데 사용될 수 있다.

    **C++ STL unordered_map / unordered_set 기능**
  
    **1. insert({key, value}) or (key):** 새로운 값을 삽입한다. 맵에서 이미 존재하는 키라면 값을 업데이트한다.
    
    **2. erase():** 주어진 값을 제거한다.
    
    **3. find():** 주어진 값의 반복자(iter)를 반환한다. 존재하지 않는다면 end()를 반환한다.
    
    **4. count():** 주어진 키 값을 갖는 원소의 개수를 반환한다.
    
    **5. size():** 집합/맵에 저장된 요소의 개수를 반환한다
    
    **6. empty():** 집합/맵이 비어 있는지 여부를 확인한다.
    
    **7. clear():** 집합/맵의 모든 요소를 제거한다.
    
    **8. swap():** 두 컨테이너의 내용을 교환한다.

    **9. map(key):** 주어진 키 값의 원소를 참조한다. (속도: 빠름, 안전: X)

    **10. at(key):** 주어진 키 값의 원소를 참조한다. (속도: 느림, 안전: O)

    + **맵은 인덱싱이 가능하다.**
  
      ```c++
      #include <iostream>
      #include <unordered_map>
      
      int main() {
          // 해시 맵 생성
          std::unordered_map<std::string, int> hashMap;
      
          // 데이터 추가
          hashMap["apple"] = 3;
          hashMap["banana"] = 5;
          hashMap["orange"] = 2;
      
          // 데이터 검색
          std::cout << "Value of apple: " << hashMap["apple"] << std::endl;
      
          return 0;
      }
      ```


