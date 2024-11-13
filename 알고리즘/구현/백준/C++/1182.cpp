// 부분수열의 합
// N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중 그 수열의 원소를 다 더한 ㄱ밧이 S가 되는 경우의 수를 구하라.


// 내 답안1
// 부분수열은, 꼭 연속된 수의 나열이 아니다. 중간중깐 띄운 조합도 부분수열로 친다.
#include <iostream>
#include <vector>

#define MAX_N 21
#define MAX_S 1'000'001

using namespace std;

int N = 0;
int S = 0;
int answer = 0;
vector<int> arr(MAX_N);

void backtracking(int start, int sum)
{
	if (sum == S && start != 0)
	{
		answer++;
	}

	for (int i = start; i < N; i++)
	{
		sum += arr[i];
		backtracking(i + 1, sum);
		sum -= arr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	backtracking(0, 0);

	cout << answer << '\n';
}
