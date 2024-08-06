// 세 용액
// 산성은 1~1,000,000,000 알칼리성은 -1~-1,000,000,000의 값을 가지며, 이러한 용액이 N개 주어진다. 3개의 용액을 섞어 중성에 가깝게 만드려할 때, 가장 0에 가까운 조합을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 5001
#define ll long long int

using namespace std;

inline ll abs(ll& a)
{
	return (a >= 0 ? a : -a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N = 0;
	vector<ll> vec;
	vector<ll> answer(3);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll num = 0;
		cin >> num;

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int std = 0;
	ll sum = 3000000001;

	while (std < (N - 2))
	{
		int left = std + 1;
		int right = N - 1;

		while (left < right)
		{
			if (sum > abs(vec[std] + vec[left] + vec[right]))
			{
				sum = abs(vec[std] + vec[left] + vec[right]);
				answer[0] = vec[std];
				answer[1] = vec[left];
				answer[2] = vec[right];
			}
			if (vec[std] + vec[left] + vec[right] > 0)
			{
				right--;
				continue;
			}
			else if (vec[std] + vec[left] + vec[right] < 0)
			{
				left++;
				continue;
			}
			else break;
		}
		std++;
	}

	for (auto n : answer)
	{
		cout << n << ' ';
	}
	cout << endl;

}

