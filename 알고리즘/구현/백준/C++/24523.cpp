// 내 뒤에 나와 다른 수
// 길이가 N인 수열이 주어진 다. (i < j < N && A_i != A_j)를 만족하는 j의 최솟값을 각 i마다 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'000'001

using namespace std;

int N = 0;
int arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int cnt = 1;
	int idx = 2;
	int preNum = arr[1];
	while (idx <= N)
	{
		if (arr[idx] == preNum)
		{
			cnt++;
		}
		else
		{
			while (cnt--)
			{
				cout << idx << ' ';
			}
			cnt = 1;
			preNum = arr[idx];
		}
		idx++;
	}
	while (cnt--)
	{
		cout << -1 << ' ';
	}
}