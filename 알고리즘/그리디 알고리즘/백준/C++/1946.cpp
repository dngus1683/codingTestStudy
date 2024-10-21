// 신입 사원
// 신입 사원 후보들의 필기 시험 등수와 면접 등수가 주어진다.
// 어느 한 명이라도 필기와 면접 성적이 모두 안좋다면 그 사람은 불합격이라고 할 때, 최대 합격자 수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int T = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		int N = 0;
		int mn = 0;
		int cnt = 1;
		int arr[100001] = { 0, };

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int a = 0;
			int b = 0;

			cin >> a >> b;
			arr[a] = b;
		}

		mn = arr[1];
		for (int i = 2; i <= N; i++)
		{
			if (arr[i] < mn)
			{
				mn = arr[i];
				cnt++;
			}
		}

		cout << cnt << '\n';
	}
	
}