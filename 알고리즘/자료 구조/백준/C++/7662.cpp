// 이중 우선순위 큐
// 최대 우선순위와 최소 우선순위를 동시에 기능하는 큐를 만들어라.


// 내 답안1 - 1%
// min-max heap 직접 구현

#include <iostream>
#include <algorithm>

#define MAX_K 1'000'000

using namespace std;

class MinMaxHeap
{
public:
	int heap[MAX_K];
	bool IsMin[MAX_K];
	int size = 0;

	inline int parent(int idx);
	inline int left(int idx);
	inline int right(int idx);
	void calMin(int idx);
	void insert(int value);
	int extractMin();
	int extractMax();
	void HeapifyUp(int idx);
	void HeapifyUpMin(int idx);
	void HeapifyUpMax(int idx);
	void HeapifyDown(int idx);
	void HeapifyDownMin(int idx);
	void HeapifyDownMax(int idx);
};

inline int MinMaxHeap::parent(int idx)
{
	return (idx - 1) / 2;
}

inline int MinMaxHeap::left(int idx)
{
	return idx*2 +1;
}

inline int MinMaxHeap::right(int idx)
{
	return idx*2+2;
}

void MinMaxHeap::calMin(int idx)
{
	if (idx == 0) IsMin[idx] = true;
	else if (idx == 1 || idx == 2) IsMin[idx] = false;
	else
	{
		if (IsMin[parent(idx)] == true) IsMin[idx] = false;
		else IsMin[idx] = true;
	}
}

void MinMaxHeap::insert(int value)
{
	heap[size] = value;
	calMin(size);
	HeapifyUp(size);
	size += 1;
}

int MinMaxHeap::extractMin()
{
	if (size == 0) return NULL;

	int minValue = heap[0];
	if (size == 1)
	{
		size = 0;
		heap[0] = NULL;
		return minValue;
	}
	heap[0] = heap[size - 1];
	heap[size - 1] = NULL;
	size -= 1;
	HeapifyDown(0);

	return minValue;
}

int MinMaxHeap::extractMax()
{
	if (size == 0) return NULL;

	int maxValue = heap[0];
	int maxValueIdx = 0;
	if (size == 1)
	{
		size = 0;
		heap[0] = NULL;
		return maxValue;
	}

	maxValueIdx = (heap[1] > heap[2] ? 1 : 2);
	maxValue = heap[maxValueIdx];
	heap[maxValueIdx] = heap[size - 1];
	heap[size - 1] = NULL;
	size -= 1;
	HeapifyDown(maxValueIdx);

	return maxValue;
}

void MinMaxHeap::HeapifyUp(int idx)
{
	int parentIdx = parent(idx);

	if (IsMin[idx])
	{
		if (idx > 0 && heap[idx] > heap[parentIdx])
		{
			swap(heap[idx], heap[parentIdx]);
			HeapifyUpMax(parentIdx);
		}
		else
		{
			HeapifyUpMin(idx);
		}
	}
	else
	{
		if (idx > 0 && heap[idx] < heap[parentIdx])
		{
			swap(heap[idx], heap[parentIdx]);
			HeapifyUpMin(parentIdx);
		}
		else
		{
			HeapifyUpMax(idx);
		}
	}

}

void MinMaxHeap::HeapifyUpMin(int idx)
{
	int grandParentIdx = parent(parent(idx));

	if (idx > 0 && heap[idx] < heap[grandParentIdx])
	{
		swap(heap[idx], heap[grandParentIdx]);
		HeapifyUpMin(grandParentIdx);
	}
}

void MinMaxHeap::HeapifyUpMax(int idx)
{
	int grandParentIdx = parent(parent(idx));

	if (idx > 1 && idx > 2 && heap[idx] > heap[grandParentIdx])
	{
		swap(heap[idx], heap[grandParentIdx]);
		HeapifyUpMax(grandParentIdx);
	}
}

void MinMaxHeap::HeapifyDown(int idx)
{
	if (IsMin[idx])
		HeapifyDownMin(idx);
	else
		HeapifyDownMax(idx);
}



void MinMaxHeap::HeapifyDownMin(int idx)
{
	int lChild = left(idx);
	int rChild = right(idx);
	int llChild = left(left(idx));
	int lrChild = left(right(idx));
	int rlChild = right(left(idx));
	int rrChild = right(right(idx));
	int smallest = idx;

	if (llChild < size && heap[llChild] < heap[smallest])
	{
		smallest = llChild;
	}
	if (lrChild < size && heap[lrChild] < heap[smallest])
	{
		smallest = lrChild;
	}
	if (rlChild < size && heap[rlChild] < heap[smallest])
	{
		smallest = rlChild;
	}
	if (rrChild < size && heap[rrChild] < heap[smallest])
	{
		smallest = rrChild;
	}

	if (smallest != idx)
	{
		swap(heap[idx], heap[smallest]);
		if (heap[smallest] > heap[parent(smallest)])
			swap(heap[smallest], heap[parent(smallest)]);
		HeapifyDown(smallest);
	}
	else
	{
		if (lChild < size && heap[lChild] < heap[idx])
		{
			swap(heap[lChild], heap[idx]);
			HeapifyDown(lChild);
		}
		else if (rChild < size && heap[rChild] < heap[idx])
		{
			swap(heap[rChild], heap[idx]);
			HeapifyDown(rChild);
		}
	}
}

void MinMaxHeap::HeapifyDownMax(int idx)
{
	int lChild = left(idx);
	int rChild = right(idx);
	int llChild = left(left(idx));
	int lrChild = left(right(idx));
	int rlChild = right(left(idx));
	int rrChild = right(right(idx));
	int biggest = idx;

	if (llChild < size && heap[llChild] > heap[biggest])
		biggest = llChild;
	if (lrChild < size && heap[lrChild] > heap[biggest])
		biggest = lrChild;
	if (rlChild < size && heap[rlChild] > heap[biggest])
		biggest = rlChild;
	if (rrChild < size && heap[rrChild] > heap[biggest])
		biggest = rrChild;
	if (biggest != idx)
	{
		swap(heap[idx], heap[biggest]);
		if (heap[biggest] < heap[parent(biggest)])
			swap(heap[biggest], heap[parent(biggest)]);
		HeapifyDown(biggest);
	}
	else
	{
		if (lChild < size && heap[lChild] > heap[idx])
		{
			swap(heap[lChild], heap[idx]);
			HeapifyDown(lChild);
		}
		else if (rChild < size && heap[rChild] > heap[idx])
		{
			swap(heap[rChild], heap[idx]);
			HeapifyDown(rChild);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int k = 0;
		int start = 0;
		int end = 0;
		int n = 0;
		char order = ' ';

		MinMaxHeap* mmh = new MinMaxHeap;

		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> order >> n;
			if (order == 'I')
			{
				mmh->insert(n);
			}
			if (order == 'D')
			{
				if (n == 1) mmh->extractMax();
				if (n == -1) mmh->extractMin();
			}
		}

		if (mmh->size == 0)
			cout << "EMPTY" << '\n';
		else if (mmh->size == 1)
		{
			cout << mmh->heap[0] << ' ' << mmh->heap[0] << '\n';
		}
		else
		{
			cout << (mmh->heap[1] > mmh->heap[2] ? mmh->heap[1] : mmh->heap[2]) << ' ' << mmh->heap[0] << '\n';
		}

		delete mmh;
	}

}








// 내 답안2
// 우선순위 큐 2개와 map 사용
/*
#include <iostream>
#include <queue>
#include <map>

#define MAX_K 1'000'001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int k = 0;
		int n = 0;
		char order = ' ';
		priority_queue<int> MaxPQ;
		priority_queue<int, vector<int>, greater<int>> MinPQ;
		map<long long int, int> MaxMap;
		map<long long int, int> MinMap;

		cin >> k;
		while (k--)
		{
			cin >> order >> n;
			if (order == 'I')
			{
				MaxPQ.push(n);
				MinPQ.push(n);
			}

			else if (order == 'D')
			{
				if (n == 1)
				{
					if (MaxPQ.empty())
					{
						continue;
					}
					if (MaxMap.find(MaxPQ.top()) == MaxMap.end() || MaxMap[MaxPQ.top()] == 0)
					{
						MinMap[MaxPQ.top()] += 1;
						MaxPQ.pop();
					}
					else
					{
						while (MaxMap.find(MaxPQ.top()) != MaxMap.end() && MaxMap[MaxPQ.top()] != 0)
						{
							MaxMap[MaxPQ.top()]--;
							MaxPQ.pop();
							if (MaxPQ.empty()) break;
						}
						if (!MaxPQ.empty())
						{
							MinMap[MaxPQ.top()] += 1;
							MaxPQ.pop();
						}
					}
				}
				else if (n == -1)
				{
					if (MinPQ.empty())
					{
						continue;
					}
					if (MinMap.find(MinPQ.top()) == MinMap.end() || MinMap[MinPQ.top()] == 0)
					{
						MaxMap[MinPQ.top()] += 1;
						MinPQ.pop();
					}
					else
					{
						while (MinMap.find(MinPQ.top()) != MinMap.end() && MinMap[MinPQ.top()] != 0)
						{
							MinMap[MinPQ.top()]--;
							MinPQ.pop();
							if (MinPQ.empty()) break;
						}
						if (!MinPQ.empty())
						{
							MaxMap[MinPQ.top()] += 1;
							MinPQ.pop();
						}
					}
				}
			}
		}

		if (!MaxPQ.empty())
		{
			while (MaxMap.find(MaxPQ.top()) != MaxMap.end() && MaxMap[MaxPQ.top()] != 0)
			{
				MaxMap[MaxPQ.top()]--;
				MaxPQ.pop();
				if (MaxPQ.empty()) break;
			}
		}
		if (!MinPQ.empty())
		{
			while (MinMap.find(MinPQ.top()) != MinMap.end() && MinMap[MinPQ.top()] != 0)
			{
				MinMap[MinPQ.top()]--;
				MinPQ.pop();
				if (MinPQ.empty()) break;
			}
		}

		if (MaxPQ.empty() && MinPQ.empty())
			cout << "EMPTY" << '\n';
		else if(MaxPQ.empty())
			cout << MinPQ.top() << ' ' << MinPQ.top() << '\n';
		else if (MinPQ.empty())
			cout << MaxPQ.top() << ' ' << MaxPQ.top() << '\n';
		else
			cout << MaxPQ.top() << ' ' << MinPQ.top() << '\n';

	}
}
*/