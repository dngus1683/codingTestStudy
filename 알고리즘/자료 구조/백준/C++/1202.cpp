// 보석 도둑
// N개의 보석의 정보(무게 M, 가격 V)가 주어진다. 각각 Ci만큼 담을 수 있는 가방 K개에 한 개의 보석을 넣어 훔치려고 할 때, 훔칠 수 있는 보석의 최대 가격을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 300'001
#define MAX_V 1'000'001
#define MAX_C 100'000'000

using namespace std;

priority_queue<int> pq;
vector<pair<int, int>> jewel;
vector<int> bag;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;
	unsigned long long int ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int mi = 0;
		int vi = 0;

		cin >> mi >> vi;
		jewel.push_back({ mi, vi });
	}
	for (int i = 0; i < K; i++)
	{
		int c = 0;

		cin >> c;
		bag.push_back(c);
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	int JewelIdx = 0;

	for (int i = 0; i < K; i++)
	{
		if (JewelIdx < N)
		{
			while (jewel[JewelIdx].first <= bag[i])
			{
				pq.push(jewel[JewelIdx++].second);
				if (JewelIdx >= N) break;
			}
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';
	
}