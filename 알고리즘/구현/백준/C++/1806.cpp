// 부분합
// 10, 000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>

#define MAX_N 100'001
#define MAX_S 100'000'001

using namespace std;

int arr[MAX_N];

inline int min(const int& a, const int& b)
{
	return (a < b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int S = 0;
	int start = 0;
	int sum = 0;
	int mn = 987654321;

	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int end = 0; end < N; end++)
	{
		sum += arr[end];
		if (sum >= S)
		{
			while (sum >= S)
			{
				sum -= arr[start++];
			}
			mn = min(mn, end - start + 2);
		}
	}
	cout << (mn == 987654321 ? 0 : mn) << '\n';
}