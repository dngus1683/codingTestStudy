# 세그먼트 트리 (Segment Tree)

세그먼트 트리(Segment Tree)는 배열의 구간에 대한 쿼리 및 업데이트를 효율적으로 처리하는 자료구조로, 주로 구간 합, 구간 최소값, 구간 최대값 등을 빠르게 구할 때 사용된다. 세그먼트 트리는 트리 구조를 기반으로 하며, 배열을 여러 구간으로 나누어 각 구간에 대한 정보를 저장한다.

## Algorithm
세그먼트 트리는 배열을 트리 형태로 나타내어, 각 노드가 특정 구간에 대한 정보를 저장한다. 트리의 리프 노드는 배열의 원소들을 저장하고, 내부 노드는 자식 노드들의 값을 결합하여 구간 정보를 저장한다.

1. 배열을 트리로 변환한다. 각 리프 노드는 배열의 원소를 저장하고, 비리프 노드는 자식 노드들의 값을 결합하여 저장한다.
2. 구간 쿼리나 업데이트 시, 해당 구간을 포함하는 트리 노드를 찾고, 그 값을 계산하거나 업데이트한다.

## Pseudocode
```
function build_tree(arr, seg_tree, node, start, end):
    if start == end:
        seg_tree[node] = arr[start]
    else:
        mid = (start + end) // 2
        build_tree(arr, seg_tree, 2 * node, start, mid)
        build_tree(arr, seg_tree, 2 * node + 1, mid + 1, end)
        seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1])

function query(seg_tree, node, start, end, L, R):
    if R < start or end < L:
        return default_value
    if L <= start and end <= R:
        return seg_tree[node]
    mid = (start + end) // 2
    left_result = query(seg_tree, 2 * node, start, mid, L, R)
    right_result = query(seg_tree, 2 * node + 1, mid + 1, end, L, R)
    return combine(left_result, right_result)

function update(seg_tree, node, start, end, idx, value):
    if start == end:
        arr[idx] = value
        seg_tree[node] = value
    else:
        mid = (start + end) // 2
        if start <= idx <= mid:
            update(seg_tree, 2 * node, start, mid, idx, value)
        else:
            update(seg_tree, 2 * node + 1, mid + 1, end, idx, value)
        seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1])
```

## Complexity
+ **시간 복잡도**:
  - **쿼리**: O(log N)
  - **업데이트**: O(log N)
+ **공간 복잡도**: O(N)

## Implementation
+ C++
    ```c++
    #include <iostream>
    #include <vector>
    
    using namespace std;

    vector<int> seg_tree;

    // 세그먼트 트리 빌드
    void build_tree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            seg_tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build_tree(arr, 2 * node, start, mid);
            build_tree(arr, 2 * node + 1, mid + 1, end);
            seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1]; // 합 구하기
        }
    }

    // 구간 합 쿼리
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;  // 기본값 (합 연산에서는 0)
        }
        if (L <= start && end <= R) {
            return seg_tree[node];
        }
        int mid = (start + end) / 2;
        int left_result = query(2 * node, start, mid, L, R);
        int right_result = query(2 * node + 1, mid + 1, end, L, R);
        return left_result + right_result;
    }

    // 업데이트
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            seg_tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1]; // 합 구하기
        }
    }

    int main() {
        vector<int> arr = {1, 3, 5, 7, 9, 11};
        int N = arr.size();
        seg_tree.resize(4 * N);
        
        build_tree(arr, 1, 0, N - 1);
        
        cout << query(1, 0, N - 1, 1, 3) << endl;  // 구간 [1, 3]의 합
        update(1, 0, N - 1, 1, 10);  // arr[1]을 10으로 업데이트
        cout << query(1, 0, N - 1, 1, 3) << endl;  // 구간 [1, 3]의 합
    }
    ```

세그먼트 트리는 구간 쿼리와 업데이트를 효율적으로 처리할 수 있는 자료구조로, 특히 큰 데이터에서 빠른 처리 속도를 자랑한다.
