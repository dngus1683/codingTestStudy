// 구간 곱 구하기
// 중간중간 요소의 수가 바뀌는 상황에서 K번의 구간 곱을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'000'001
#define MAX_M 10'001
#define MAX_K 10'001
#define MOD_NUM 1'000'000'007
#define ull unsigned long long 

using namespace std;

int N = 0;
int M = 0;
int K = 0;
vector<ull> arr(MAX_N);
vector<ull> segTree(MAX_N * 4);

void initTree(vector<ull>& tree, vector<ull>& arr, int index, int start, int end)
{
	if (start == end)
	{
		tree[index] = arr[start];
		return;
	}
	initTree(tree, arr, index * 2, start, (start + end) / 2);
	initTree(tree, arr, index * 2 + 1, (start + end) / 2 + 1, end);
	tree[index] = (tree[index * 2] * tree[index * 2 + 1]) % MOD_NUM;
}

int intervalMux(vector<ull>& tree, int index, int start, int end, int l, int r)
{
	if (start > r || end < l) return 1;
	if (l <= start && end <= r) return tree[index];

	ull lnum = intervalMux(tree, index * 2, start, (start + end) / 2, l, r);
	ull rnum = intervalMux(tree, index * 2 + 1, (start + end) / 2 + 1, end, l, r);

	return (lnum * rnum) % MOD_NUM;
}

void update(vector<ull>& tree, vector<ull>& arr, int index, int start, int end, int target, ull number)
{
	if (start > target || end < target) return;
	if (start == end)
	{
		arr[target] = number;
		tree[index] = number;
		return;
	}

	update(tree, arr, index * 2, start, (start + end) / 2, target, number);
	update(tree, arr, index * 2 + 1, (start + end) / 2 + 1, end, target, number);
	tree[index] = (tree[index * 2] * tree[index * 2 + 1]) % MOD_NUM;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	initTree(segTree, arr, 1, 1, N);

	for (int i = 0; i < M + K; i++)
	{
		int a = 0;
		int b = 0;
		int c = 0;

		cin >> a >> b >> c;

		if (a == 1)
		{
			update(segTree, arr, 1, 1, N, b, c);
		}
		else
		{
			cout << intervalMux(segTree, 1, 1, N, b, c) << '\n';
		}
	}

}

