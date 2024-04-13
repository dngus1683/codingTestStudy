// 블랙잭
// N장의 카드가 주어질 때, 그 중 3장의 카드의 합이 정수 M을 넘지 않으면서 가장 큰 경우 그 합을 구하라.


// 내 답안
// 완전 탐색
#include <iostream>
#include <algorithm>

#define MAX_N 101

using namespace std;

int arr[MAX_N];

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, a, b, c, ans = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (arr[i] + arr[j] + arr[k] > M) continue;
				ans = (ans > arr[i] + arr[j] + arr[k] ? ans : arr[i] + arr[j] + arr[k]);
			}
		}
	}


	cout << ans << '\n';
}