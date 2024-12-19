// 수 정렬하기
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하라.

 
// 내 답안1
#include <iostream>
#include <algorithm>

using namespace std;

int N = 0;
int arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << '\n';
	}
}