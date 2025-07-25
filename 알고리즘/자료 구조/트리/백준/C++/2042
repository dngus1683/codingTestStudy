// 구간 합 구하기
// 중간에 값의 변경이 있는 상황에서 구간 합을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'000'001
#define MAX_M 10'001
#define ll long long

using namespace std;



void InitSegTree(vector<ll>& tree, vector<ll>& nums, int index, int start, int end)
{
	if (start == end)
	{
		tree[index] = nums[start];
		
		return;
	}

	InitSegTree(tree, nums, index * 2, start, (start + end) / 2);
	InitSegTree(tree, nums, index * 2 + 1, (start + end) / 2 + 1, end);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

ll FindElement(vector<ll>& tree, int index, int start, int end, int l, int r)
{
	if (l > end || r < start) return 0;
	if (l <= start && r >= end) return tree[index];

	ll left = FindElement(tree, index * 2, start, (start + end) / 2, l, r);
	ll right = FindElement(tree, index * 2 + 1, (start + end) / 2 + 1, end, l, r);

	return left + right;

}

void update(vector<ll>& tree, int index, int start, int end, int targetIdx, ll value)
{
	if (start > targetIdx) return;
	if (end < targetIdx) return;
	if (start == end && start == targetIdx)
	{
		tree[index] = value;

		return;
	}

	update(tree, index * 2, start, (start + end) / 2, targetIdx, value);
	update(tree, index * 2 + 1, (start + end) / 2 + 1, end, targetIdx, value);

	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int K = 0;
	vector<ll> vec;
	vector<ll> segTree(MAX_N*4);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		ll num = 0;

		cin >> num;

		vec.push_back(num);
	}
	
	InitSegTree(segTree, vec, 1, 0, N-1);

	for (int i = 0; i < M + K; i++)
	{
		ll a = 0;
		ll b = 0;
		ll c = 0;

		cin >> a >> b >> c;

		if (a == 1)
		{

			update(segTree, 1, 0, N - 1, b-1, c);
		}
		else
		{
			cout << FindElement(segTree, 1, 0, N - 1, b-1, c-1) << '\n';
		}
	}
}
