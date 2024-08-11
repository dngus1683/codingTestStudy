// 수열의 합
// N과 L이 주어질 때, 합이 N이면서, 길이가 적어도 L인 가장 짧은 연속된 음이 아닌 정수 리스트를 구하는 프로그램을 작성하시오.


// 내 답안1
// L의 값을 하나 씩 높여가며, 첫 수와 마지막 수의 합을 이용하여 정수 리스트의 총 합을 구하고, 그 값과 N을 비교한다.
#include <iostream>

#define MAX_N 1'000'000'001
#define MAX_L 100

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int L = 2;

	cin >> N >> L;

	int start = 100;
	int end = 0;
	while (start >= 0 && L <= MAX_L)
	{
		start = N / L - ((L - 1) / 2);
		end = N / L + (L / 2);
		int cnt = L/2;
		int rmd = L % 2;

		if (start < 0) break;
		if ((start + end) * cnt + ((N / L) * rmd) == N)
		{
			for (int i = start; i <= end; i++)
				cout << i << ' ';
			cout << endl;
			return 0;
		}
		else
		{
			L++;
		}
	}

	cout << -1 << endl;
}






// 답안 예시1 - https://www.acmicpc.net/source/51106155
/* 0부터 (2 ~ 99)까지 등차가 1인 등차수열 합을 먼저 구한다. 해당 정수 리스트의 모든 원소에 같은 값을 더했을 때, 그 값이 N이 되는 경우를 구한다.
#include <stdio.h>

int main() {
	int n, l, sum;

	scanf("%d %d", &n, &l);
	while (l <= 100)
	{
		sum = l * (l - 1) / 2;
		if ((n - sum) % l == 0 && n - sum >= 0)
		{
			for (int i = 0; i < l; i++)
				printf("%d ", i + (n - sum) / l);
			return 0;
		}
		l++;
	}
	printf("-1");
	return 0;
*/

