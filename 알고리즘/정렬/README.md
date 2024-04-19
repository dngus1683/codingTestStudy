# 정렬
+ [선택 정렬 (Selection Sort)](#선택-정렬)
+ [버블 정렬 (Bubble Sort)](#버블-정렬)
+ [삽입 정렬 (Insertion Sort)](#삽입-정렬)
+ [병합 정렬 (Merge Sort)](#병합-정렬)
+ [퀵 정렬 (Quick Sort)](#퀵-정렬)
+ [힙 정렬 (Heap Sort)](#힙-정렬)
+ [기수 정렬 (Radix Sort)](#기수-정렬)
+ [계수 정렬 (Counting Sort)](#계수-정렬)

## 선택 정렬
### Algorithm
1. 주어진 배열에서 최소값을 찾는다.
2. 최소값을 현재 위치와 교환한다.
3. 다음 위치를 선택하여 위 과정을 반복한다.

### Pseudocode
```pseudo
for i from 0 to n-1:
    min_index = i
    for j from i+1 to n:
        if arr[j] < arr[min_index]:
            min_index = j
    swap arr[i] and arr[min_index]
```

### Complexity
+ 시간 복잡도: O(n^2)
+ 공간 복잡도: O(1)

### Implementation 
+ C++
  ```c++
  void selectionSort(std::vector<int>& arr) {
      int n = arr.size();
      for (int i = 0; i < n - 1; ++i) {
          int min_index = i;
          for (int j = i + 1; j < n; ++j) {
              if (arr[j] < arr[min_index]) {
                  min_index = j;
              }
          }
          std::swap(arr[i], arr[min_index]);
      }
  }
  ```

## 버블 정렬
### Algorithm
1. 인접한 두 원소를 비교하여 순서가 잘못되어 있다면 교환한다.
2. 배열의 끝까지 위 과정을 반복한다.
3. 위 과정을 모든 원소가 정렬될 때까지 반복한다.

### Pseudocode
```pseudo
for i from 0 to n-1:
    for j from 0 to n-i-1:
        if arr[j] > arr[j+1]:
            swap arr[j] and arr[j+1]
```

### Complexity
+ 시간 복잡도: O(n^2) (최선, 평균, 최악의 경우 동일)
+ 공간 복잡도: O(1)

### Implementation 
+ C++
  ```c++
  void bubbleSort(std::vector<int>& arr) {
      int n = arr.size();
      for (int i = 0; i < n - 1; ++i) {
          for (int j = 0; j < n - i - 1; ++j) {
              if (arr[j] > arr[j + 1]) {
                  std::swap(arr[j], arr[j + 1]);
              }
          }
      }
  }
  ```

## 삽입 정렬
### Algorithm
1. 배열을 정렬된 부분과 정렬되지 않은 부분으로 나눈다.
2. 정렬되지 않은 부분의 첫 번째 원소를 정렬된 부분에 삽입한다.
3. 정렬된 부분의 원소와 비교하여 올바른 위치에 삽입한다.
4. 위 과정을 반복하여 전체 배열이 정렬될 때까지 진행한다.
   
### Pseudocode
```pseudo
for i from 1 to n-1:
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > key:
        arr[j + 1] = arr[j]
        j = j - 1
    arr[j + 1] = key
```

### Complexity
+ 시간 복잡도: O(n^2) (최선: 이미 정렬된 경우), O(n^2) (평균, 최악의 경우)
+ 공간 복잡도: O(1)

### Implementation 
+ C++
  ```c++
  void insertionSort(std::vector<int>& arr) {
      int n = arr.size();
      for (int i = 1; i < n; ++i) {
          int key = arr[i];
          int j = i - 1;
          while (j >= 0 && arr[j] > key) {
              arr[j + 1] = arr[j];
              --j;
          }
          arr[j + 1] = key;
      }
  }
  ```

## 병합 정렬
### Algorithm

### Pseudocode
```pseudo

```

### Complexity


### Implementation 
+ C++
  ```c++
  
  ```

## 퀵 정렬
### Algorithm

### Pseudocode
```pseudo

```

### Complexity


### Implementation 
+ C++
  ```c++
  
  ```

## 힙 정렬
### Algorithm

### Pseudocode
```pseudo

```

### Complexity


### Implementation 
+ C++
  ```c++
  
  ```

## 기수 정렬
### Algorithm

### Pseudocode
```pseudo

```

### Complexity


### Implementation 
+ C++
  ```c++
  
  ```

## 계수 정렬
### Algorithm

### Pseudocode
```pseudo

```

### Complexity


### Implementation 
+ C++
  ```c++
  
  ```

