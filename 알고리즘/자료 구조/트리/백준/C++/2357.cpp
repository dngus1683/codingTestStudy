// 최솟값과 최댓값
// N개의 정수가 있을 때, a번 째 정수부터 b번 째 정수까지 최소,최댓값을 구하라. (M번의 쌍)


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100'001
#define INF 1'000'000'001

using namespace std;

int N = 0;
int M = 0;
vector<int> arr(MAX_N);
vector<int> minTree(MAX_N * 4);
vector<int> maxTree(MAX_N * 4);

void initTree(vector<int>& mintree, vector<int>& maxtree, vector<int>& arr, int index, int start, int end)
{
	if (start == end)
	{
		mintree[index] = arr[start];
		maxtree[index] = arr[start];
		return;
	}

	initTree(mintree, maxtree, arr, index * 2, start, (start + end) / 2);
	initTree(mintree, maxtree, arr, index * 2 + 1, (start + end) / 2 + 1, end);
	mintree[index] = min(mintree[index * 2], mintree[index * 2 + 1]);
	maxtree[index] = max(maxtree[index * 2], maxtree[index * 2 + 1]);
}

pair<int, int> intervalMinMax(vector<int>& mintree, vector<int>& maxtree, int index, int start, int end, int l, int r)
{
	if (r < start || l > end) return { INF, 0 };
	if (l <= start && r >= end)
	{
		return { mintree[index], maxtree[index] };
	}

	pair<int, int> lnums = intervalMinMax(mintree, maxtree, index * 2, start, (start + end) / 2, l, r);
	pair<int, int> rnums = intervalMinMax(mintree, maxtree, index * 2 + 1, (start + end) / 2 + 1, end, l, r);

	return { min(lnums.first, rnums.first), max(lnums.second, rnums.second) };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	initTree(minTree, maxTree, arr, 1, 1, N);

	for (int i = 0; i < M; i++)
	{
		int l = 0;
		int r = 0;
		pair<int, int> answer = {};

		cin >> l >> r;

		answer = intervalMinMax(minTree, maxTree, 1, 1, N, l, r);

		cout << answer.first << ' ' << answer.second << '\n';
	}

}