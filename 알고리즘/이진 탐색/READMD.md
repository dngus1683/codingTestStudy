# 이진 탐색 (Binary Search)
이진 탐색(Binary Search)은 정렬된 배열에서 특정한 값을 찾는 탐색 알고리즘이다. 이진 탐색은 배열을 반으로 나누어 탐색 범위를 절반씩 줄여가면서 찾고자 하는 값을 찾아내는 방법이다. 이 알고리즘은 탐색 범위를 반으로 줄여가기 때문에 매우 효율적으로 동작한다.

## Algorithm
1. 배열의 중간 원소를 선택한다.
2. 중간 원소와 찾고자 하는 값을 비교한다.
3. 중간 원소보다 작은 부분에 대해 다시 탐색을 수행한다. (왼쪽 부분 배열)
4. 중간 원소보다 큰 부분에 대해 다시 탐색을 수행한다. (오른쪽 부분 배열)
5. 찾고자 하는 값이 나올 때까지 반복한다.

![Binary_search_tree](https://github.com/dngus1683/codingTestStudy/assets/71319694/eb10a8ce-7e99-4224-98d8-6ba166aaa4aa)

이는 반복문과 재귀함수를 통해 구현이 가능하다. 
## Pseudocode
+ 재귀적 방법
  ```
  recursiveBinarySearch(arr, left, right, target):
    if left is greater than right:
        return -1 // Not found
    
    Calculate the middle index: mid = (left + right) / 2
    
    if arr[mid] is equal to target:
        return mid // Found
    
    if arr[mid] is less than target:
        return recursiveBinarySearch(arr, mid + 1, right, target) // Search right half
    
    else:
        return recursiveBinarySearch(arr, left, mid - 1, target) // Search left half
  ```
+ 반복문 방법
  ```
  iterativeBinarySearch(arr, target):
      left = 0
      right = arr.size() - 1
      
      while left is less than or equal to right:
          Calculate the middle index: mid = (left + right) / 2
          
          if arr[mid] is equal to target:
              return mid // Found
          
          if arr[mid] is less than target:
              left = mid + 1 // Search right half
          
          else:
              right = mid - 1 // Search left half
      
      return -1 // Not found
  ```

## Complexity
+ 시간 복잡도: O(long n)
+ 공간 복잡도:
  + 재귀문: O(long n) (재귀 호출이 이루어질 때마다 스택 프레임이 쌓이게 되는데, 이는 최대 재귀 깊이가 배열의 크기에 비례하므로 로그 시간 복잡도와 동일)
  + 반복문: O(1)

## Implementation
+ C++
    ```c++
    #include <iostream>
    #include <vector>
    using namespace std;
    
    // 이진 탐색 함수
    int binarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid; // 찾은 경우 인덱스 반환
            } else if (arr[mid] < target) {
                left = mid + 1; // 오른쪽 부분 배열 탐색
            } else {
                right = mid - 1; // 왼쪽 부분 배열 탐색
            }
        }
        return -1; // 찾지 못한 경우 -1 반환
    }

    
    // 반복문을 사용한 이진 탐색 함수
    int iterativeBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            // 중간 인덱스를 계산
            int mid = left + (right - left) / 2;
            
            // 중간 값과 타겟 비교
            if (arr[mid] == target) {
                return mid; // 찾은 경우 인덱스 반환
            } else if (arr[mid] < target) {
                left = mid + 1; // 오른쪽 부분 배열 탐색
            } else {
                right = mid - 1; // 왼쪽 부분 배열 탐색
            }
        }
        
        return -1; // 찾지 못한 경우
    }
    ```



## Reference
+ 이미지 출처 : [Binary Search - Wikipedia](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%ED%83%90%EC%83%89_%ED%8A%B8%EB%A6%AC)
