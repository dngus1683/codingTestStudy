// 통계학
// 홀수 N개의 정수가 주어질 때, 해당 정수들의 산술평균, 중앙값, 최빈값, 범위를 구하라.
// 산술평균: N개의 수들의 합을 N으로 나눈 값
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
// 범위 : N개의 수들 중 최댓값과 최솟값의 차이


// 내 답안1
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_N 500001

using namespace std;

int arr[MAX_N];
int cnt[4002 * 2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, midIdx, mn, mx, cntMax = 0, cntIdx = 0, cflag = 0;
	double sum = 0.0;

	cin >> N;

	midIdx = (N / 2) + 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

		sum += arr[i];
		cnt[arr[i] + 4000]++;
		if (i == 0)
		{
			mn = arr[i];
			mx = arr[i];
			continue;
		}
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
	}

	sort(arr, arr + N);
	for (int i = 0; i < 4002*2;i++)
	{
		if (cntMax < cnt[i])
		{
			cntMax = cnt[i];
			cntIdx = i;
			cflag = 0;
		}
		else if (cntMax == cnt[i] && cflag == 0)
		{
			cntIdx = i;
			cflag = 1;
		}
	}

	cout << (int)floor(sum / N + 0.5) << '\n';
	cout << arr[midIdx-1] << '\n';
	cout << cntIdx-4000 << '\n';
	cout << mx - mn << '\n';
}