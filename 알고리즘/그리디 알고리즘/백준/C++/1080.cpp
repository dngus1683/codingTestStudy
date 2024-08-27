// 행렬
// 0과 1로 이루어진 행렬 A, B가 주어진다. 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 50

using namespace std;

char A[MAX_N][MAX_N];
char B[MAX_N][MAX_N];

void reverse3x3(int n, int m)
{
	for (int i = n; i < n + 3; i++)
	{
		for (int j = m; j < m + 3; j++)
		{
			A[i][j] = (A[i][j] == '1' ? '0' : '1');
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int answer = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (A[i][j] != B[i][j])
			{
				reverse3x3(i, j);
				answer++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << answer << '\n';
}