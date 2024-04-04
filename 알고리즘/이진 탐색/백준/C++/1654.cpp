// 랜선 자르기
// 길이가 제각각인 랜선 k개가 주어진다. # 길이가 제 각각인 랜선 K개가 있다. 이를 적절히 잘라서 N개 이상의 같은 길이의 랜선으로 만들 때, 최대 랜선 길이를 구하라.


// 내 답안1
// 랜선의 최대 길이는 2^31 -1 이므로 순차 탐색으로 문제를 푼다면 시간초과가 발생한다.
// 반면 이진 탐색을 한다면 깊이가 최대 31번이므로 시간이 굉장히 적게 소모된다.
#include <iostream>
#include <algorithm>

#define MAX_K 10001

using namespace std;

long long int length[MAX_K];
long long int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	long long int start = 1, end = 0;

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> length[i];
		end = max(length[i], end);
	}

	while (start <= end)
	{
		int num = 0;
		long long int mid = (end + start) / 2;

		for (int i = 0; i < k; i++)
		{
			num += length[i] / mid;
		}

		if (num < n) end = mid - 1;
		else
		{
			ans = mid;
			start = mid + 1;
		}
	}

	cout << ans << '\n';
}
