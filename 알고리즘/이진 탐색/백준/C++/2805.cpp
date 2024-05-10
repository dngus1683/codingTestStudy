// 나무 자르기
// N개의 나무의 길이가 주어지고, 가지고 갈 나무의 총 길이 M이 주어진다.
// N개의 나무는 모두 공통된 길이 만큼 한 번 자를 수 있고, 자르고 남은 나무를 가져간다 할 때, 적어도 M 미터의 나무를 가지기 위해 나무를 자를 최대 높이를 구하라.


// 내 답안1
// 그리디 알고리즘 접근 - 자료형 범위에 대한 문제인줄 알았으나 접근 방식 자체가 문제로 보임.
/*
#include <iostream>
#include <algorithm>

#define MAX_N 1000001
#define MAX_M 2000000000

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int trees[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	unsigned long long int H = 0;
	bool IsPlus = true;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
	}

	sort(trees, trees + N, compare);


	if (trees[0] >= M)
	{
		H = trees[0] - M;
	}
	else
	{
		H = M - trees[0];
		IsPlus = false;
	}

	for (int i = 1; i < N; i++)
	{
		if ((trees[i] > H && IsPlus) || !IsPlus)
		{
			if (!IsPlus)
			{
				if(H >= trees[i])
					H -= trees[i];
				else
				{
					H = ((trees[i] + H) / (i + 1)) - H;
					IsPlus = true;
				}
			}
			else H += ((trees[i] - H) / (i + 1));
		}

	}

	cout << H << '\n';
}
*/



// 내 답안2
// 이진 탐색
#include <iostream>

#define MAX_N 1000000
#define MAX_M 2000000000

using namespace std;

int trees[MAX_N];
int N = 0;
int M = 0;

int BinarySearch(int start, int end)
{
	int ans = 0;

	while (start <= end)
	{
		unsigned long long int sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			if (trees[i] >= mid) sum += (trees[i] - mid);
			else continue;
		}

		if (sum > M)
		{
			start = mid + 1;
			ans = (ans > mid ? ans : mid );
		}
		else if (sum < M)
		{
			end = mid - 1;
		}
		else
		{
			ans = (ans > mid ? ans : mid);
			break;
		}
	}

	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int start = 0;
	int end = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
		end = (trees[i] > end ? trees[i] : end);
	}

	cout << BinarySearch(start, end) << '\n';
}
