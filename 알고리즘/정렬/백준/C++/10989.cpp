// 수 정렬하기3
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하라.
// 시간 제한: 5초, 메모리 제한: 8MB
// <algorithm> 의 sort()는 메모리 제한으로 사용할 수 없다.

// 내 답안1
// 계수 정렬
#include <iostream>

#define MAX_N 10001

using namespace std;

int arr[MAX_N] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		
		cin >> a;
		arr[a]++;
	}


	for (int i = 1; i < 10001; i++)
		for (; arr[i] != 0; arr[i]--)
			cout << i << '\n';
}