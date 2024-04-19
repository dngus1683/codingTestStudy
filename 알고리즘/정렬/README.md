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
1. 배열을 반으로 나눕니다.
2. 각 부분 배열을 재귀적으로 정렬합니다.
3. 정렬된 부분 배열을 병합하여 전체 배열을 정렬합니다.

### Pseudocode
```pseudo
mergeSort(arr, l, r):
    if l < r:
        mid = (l + r) / 2
        mergeSort(arr, l, mid)
        mergeSort(arr, mid + 1, r)
        merge(arr, l, mid, r)

merge(arr, l, mid, r):
    n1 = mid - l + 1
    n2 = r - mid
    Left[n1], Right[n2]

    for i from 0 to n1-1:
        Left[i] = arr[l + i]
    for j from 0 to n2-1:
        Right[j] = arr[mid + 1 + j]

    i = 0, j = 0, k = l
    while i < n1 and j < n2:
        if Left[i] <= Right[j]:
            arr[k] = Left[i]
            i = i + 1
        else:
            arr[k] = Right[j]
            j = j + 1
        k = k + 1

    while i < n1:
        arr[k] = Left[i]
        i = i + 1
        k = k + 1

    while j < n2:
        arr[k] = Right[j]
        j = j + 1
        k = k + 1
```

### Complexity
+ 시간 복잡도: O(n log n)
+ 공간 복잡도: O(n)

### Implementation 
+ C++
  ```c++
  void merge(std::vector<int>& arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        std::vector<int> Left(n1), Right(n2);
    
        for (int i = 0; i < n1; ++i) {
            Left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; ++j) {
            Right[j] = arr[mid + 1 + j];
        }
    
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (Left[i] <= Right[j]) {
                arr[k] = Left[i];
                ++i;
            } else {
                arr[k] = Right[j];
                ++j;
            }
            ++k;
        }
    
        while (i < n1) {
            arr[k] = Left[i];
            ++i;
            ++k;
        }
    
        while (j < n2) {
            arr[k] = Right[j];
            ++j;
            ++k;
        }
    }

    void mergeSort(std::vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    ```

## 퀵 정렬
### Algorithm
1. 배열에서 하나의 원소를 피벗(pivot)으로 선택합니다.
2. 피벗을 기준으로 작은 원소는 왼쪽, 큰 원소는 오른쪽으로 분할합니다.
3. 분할된 부분 배열에 대해 재귀적으로 퀵 정렬을 수행합니다.
   
### Pseudocode
```pseudo
quickSort(arr, low, high):
    if low < high:
        pivotIndex = partition(arr, low, high)
        quickSort(arr, low, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, high)

partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j from low to high-1:
        if arr[j] < pivot:
            i = i + 1
            swap arr[i] and arr[j]
    swap arr[i + 1] and arr[high]
    return i + 1
```

### Complexity
+ 시간 복잡도: O(n log n) (평균), O(n^2) (최악)
+ 공간 복잡도: O(log n) (재귀 호출 스택)

### Implementation 
+ C++
  ```c++
  int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

  ```

## 힙 정렬
### Algorithm
1. 주어진 배열을 최대 힙(Max Heap)으로 만듭니다.
2. 최대 힙에서 최댓값(루트)을 제거하고 배열의 마지막 원소와 교환합니다.
3. 배열의 크기를 줄이고 다시 최대 힙을 구성합니다.
4. 위 과정을 반복하여 전체 배열이 정렬될 때까지 진행합니다.
   
### Pseudocode
```pseudo
heapSort(arr):
    buildMaxHeap(arr)
    for i from n-1 to 1:
        swap arr[0] and arr[i]
        heapify(arr, 0, i)

buildMaxHeap(arr):
    n = arr.length
    for i from (n/2)-1 down to 0:
        heapify(arr, i, n)

heapify(arr, i, n):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        swap arr[i] and arr[largest]
        heapify(arr, largest, n)
```

### Complexity
+ 시간 복잡도: O(n log n)
+ 공간 복잡도: O(1)

### Implementation 
+ C++
  ```c++
  void heapify(std::vector<int>& arr, int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, largest, n);
        }
    }
    
    void buildMaxHeap(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(arr, i, n);
        }
    }
    
    void heapSort(std::vector<int>& arr) {
        int n = arr.size();
        buildMaxHeap(arr);
        for (int i = n - 1; i > 0; --i) {
            std::swap(arr[0], arr[i]);
            heapify(arr, 0, i);
        }
    }

  ```

## 기수 정렬
### Algorithm
1. 가장 작은 자리수부터 가장 큰 자리수까지 순서대로 정렬합니다.
2. 각 자리수에 대해 숫자를 세는 계수 정렬을 사용합니다.
   
### Pseudocode
```pseudo
radixSort(arr):
    max_num = findMax(arr)
    exp = 1
    while max_num / exp > 0:
        countingSort(arr, exp)
        exp *= 10

countingSort(arr, exp):
    n = arr.length
    output[n], count[10] = 0

    for i from 0 to n-1:
        count[(arr[i] / exp) % 10]++

    for i from 1 to 9:
        count[i] += count[i - 1]

    for i from n-1 down to 0:
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]
        count[(arr[i] / exp) % 10]--

    for i from 0 to n-1:
        arr[i] = output[i]
```

### Complexity
+ 시간 복잡도: O(nk) (n은 배열의 길이, k는 숫자의 최대 자릿수)
+ 공간 복잡도: O(n + k)

### Implementation 
+ C++
  ```c++
  int findMax(std::vector<int>& arr) {
        int max_num = arr[0];
        for (int x : arr) {
            max_num = std::max(max_num, x);
        }
        return max_num;
    }
    
    void countingSort(std::vector<int>& arr, int exp) {
        int n = arr.size();
        std::vector<int> output(n);
        std::vector<int> count(10, 0);
    
        for (int i = 0; i < n; ++i) {
            count[(arr[i] / exp) % 10]++;
        }
    
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }
    
        for (int i = n - 1; i >= 0; --i) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
    
        for (int i = 0; i < n; ++i) {
            arr[i] = output[i];
        }
    }
    
    void radixSort(std::vector<int>& arr) {
        int max_num = findMax(arr);
        for (int exp = 1; max_num / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }
  ```

## 계수 정렬
### Algorithm
1. 배열의 각 요소가 몇 번 등장하는지 세고, 해당 숫자의 등장 횟수를 기록합니다.
2. 등장 횟수를 바탕으로 정렬된 배열을 생성합니다.
   
### Pseudocode
```pseudo
countingSort(arr):
    n = arr.length
    output[n], count[max(arr) + 1] = 0

    for i from 0 to n-1:
        count[arr[i]]++

    for i from 1 to max(arr):
        count[i] += count[i - 1]

    for i from n-1 down to 0:
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]]--

    for i from 0 to n-1:
        arr[i] = output[i]
```

### Complexity
+ 시간 복잡도: O(n + k) (n은 배열의 길이, k는 숫자의 최대 값)
+ 공간 복잡도: O(n + k)

### Implementation 
+ C++
  ```c++
  void countingSort(std::vector<int>& arr) {
        int n = arr.size();
        int max_num = *std::max_element(arr.begin(), arr.end());
        std::vector<int> output(n);
        std::vector<int> count(max_num + 1, 0);
    
        for (int i = 0; i < n; ++i) {
            count[arr[i]]++;
        }
    
        for (int i = 1; i <= max_num; ++i) {
            count[i] += count[i - 1];
        }
    
        for (int i = n - 1; i >= 0; --i) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
    
        for (int i = 0; i < n; ++i) {
            arr[i] = output[i];
        }
    }

  ```

