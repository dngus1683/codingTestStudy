// 수 찾기 
// N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 100001
#define MAX_M 100001

using namespace std;

int A[MAX_N];
int B[MAX_M];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A, A + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num, mn = 0, mx = n-1;

		cin >> num;
		while (mn <= mx)
		{
			int mid = (mn + mx) / 2;

			if (num < A[mid])
			{
				mx = mid - 1;
			}
			else if (num > A[mid])
			{
				mn = mid + 1;
			}
			else
			{
				B[i] = 1;
				break;
			}
		}
		if (B[i] != 1) B[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cout << B[i] << '\n';
	}
}
