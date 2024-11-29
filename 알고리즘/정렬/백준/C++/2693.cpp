// N번째 큰 수
// 배열 A가 주어졌을 때, N번째 큰 값을 출력하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T = 0;
int N = 3;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		vector<int> A(10);

		for (int i = 0; i < 10; i++)
		{
			cin >> A[i];
		}

		sort(A.begin(), A.end());

		cout << A[7] << '\n';
	}
}