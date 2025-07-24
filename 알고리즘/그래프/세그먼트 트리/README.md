# 세그먼트 트리 (Segment Tree)

세그먼트 트리는 구간 합, 구간 최솟값/최댓값 등 구간 쿼리를 빠르게 처리하기 위한 자료구조이다. 배열의 특정 구간에 대한 쿼리를 O(log N)의 시간 복잡도로 처리할 수 있으며, 배열 원소의 값이 변경되더라도 빠르게 반영할 수 있도록 설계되어 있다.

주로 **펜윅 트리(Binary Indexed Tree)** 보다 복잡한 쿼리 처리(예: 최솟값, 최댓값, 최소공배수 등)에 사용된다.

## Algorithm

세그먼트 트리는 이진 트리 형태로 구성되며, 각 노드는 특정 구간을 나타낸다.

1. 트리의 리프 노드들은 원본 배열의 원소를 나타낸다.
2. 내부 노드들은 자식 노드들이 표현하는 구간을 바탕으로 쿼리에 필요한 정보를 저장한다 (예: 합, 최소값 등).
3. 쿼리 시, 해당 구간을 포함하는 최소한의 노드들을 탐색하여 결과를 계산한다.
4. 값 갱신 시, 해당 원소가 포함된 노드를 갱신하고, 상위 노드로 전파한다.

<img width="500" height="380" alt="image" src="https://github.com/user-attachments/assets/f2696c57-1b13-43bc-9806-c8b2cb89a3ee" />

## Pseudocode

```python
# 초기 세그먼트 트리 구성
function build(node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        mid = (start + end) / 2
        build(2*node, start, mid)
        build(2*node+1, mid+1, end)
        tree[node] = tree[2*node] + tree[2*node+1] # 예: 구간 합

# 구간 쿼리
function query(node, start, end, left, right):
    if right < start or end < left:
        return 0  # 예: 합을 위한 항등원
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) / 2
    l_query = query(2*node, start, mid, left, right)
    r_query = query(2*node+1, mid+1, end, left, right)
    return l_query + r_query

# 값 갱신
function update(node, start, end, index, value):
    if start == end:
        arr[index] = value
        tree[node] = value
    else:
        mid = (start + end) / 2
        if index <= mid:
            update(2*node, start, mid, index, value)
        else:
            update(2*node+1, mid+1, end, index, value)
        tree[node] = tree[2*node] + tree[2*node+1]
```

## Complexity

* **시간 복잡도**

  * 빌드: O(N)
  * 쿼리: O(log N)
  * 갱신: O(log N)
* **공간 복잡도**

  * O(4N) (트리 크기는 배열 크기의 약 4배 필요)

## Implementation

* C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, segTree;

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        segTree[node] = segTree[2*node] + segTree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return segTree[node];
    int mid = (start + end) / 2;
    int leftSum = query(2*node, start, mid, l, r);
    int rightSum = query(2*node+1, mid+1, end, l, r);
    return leftSum + rightSum;
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        segTree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        segTree[node] = segTree[2*node] + segTree[2*node+1];
    }
}
```

## 참고 이미지

이미지 출처: [Wikipedia - Segment Tree](https://en.wikipedia.org/wiki/Segment_tree)

---
