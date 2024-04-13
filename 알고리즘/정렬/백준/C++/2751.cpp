// 수 정렬하기2
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 1000001

using namespace std;

int arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';
}
