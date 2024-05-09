// 좌표 압축
// N개의 1차원 좌표가 주어진다. 본인 보다 값이 작은 좌표의 개수로 값을 업데이트 하는 것을 좌표 압축이라 할 때, 모든 좌표의 좌표 압축 값을 구하라.


// 내 답안1
// 이진탐색 - 시간초과 (N이 1,000,000이므로 O(nlogn)으로도 부족한 것으로 보인다.
/*
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1000001

using namespace std;

vector<int> graph, GraphSort;

int BinarySearch(int start, int end, int i)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (graph[i] > GraphSort[mid])
		{
			start = mid + 1;
		}
		else if (graph[i] < GraphSort[mid])
		{
			end = mid - 1;
		}
		else return mid;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a = 0;

		cin >> a;
		graph.push_back(a);
		GraphSort.push_back(a);
	}

	sort(GraphSort.begin(), GraphSort.end());

	for (int i = N-1; i > 0; i--)
	{
		if (GraphSort[i] == GraphSort[i - 1])
		{
			GraphSort.pop_back();
		}
	}

	int start = 0;
	int end = GraphSort.size() - 1;

	for (int i = 0; i < N; i++)
	{

		cout << BinarySearch(start, end, i) << ' ';
	}
}
*/




// 내 답안2
#include <iostream>
#include <algorithm>

#define MAX_N 1000001

using namespace std;

typedef struct Point
{
	int num = 0;
	int idx = 0;
	int cnt = 0;
}Point;

bool ComparePointNum(const Point& a, const Point& b)
{
	return a.num < b.num;
}

bool ComparePointIdx(const Point& a, const Point& b)
{
	return a.idx < b.idx;
}

Point PArr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a = 0;

		cin >> a;
		PArr[i] = { a, i, 0 };
	}

	sort(PArr, PArr + N, ComparePointNum);

	for (int i = 1; i < N; i++)
	{
		if (PArr[i].num == PArr[i - 1].num)
		{
			PArr[i].cnt = PArr[i - 1].cnt;
		}
		else
		{
			PArr[i].cnt = PArr[i - 1].cnt + 1;
		}
	}

	sort(PArr, PArr + N, ComparePointIdx);

	for (int i = 0; i < N; i++)
	{
		cout << PArr[i].cnt << ' ';
	}

}