// 오르막 수
// 오름차순으로 이뤄진 수를 오르막 수라 한다. 수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 1'001

using namespace std;

int N = 0;
int sum = 0;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		answer.push_back(1);
		sum += 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int tmp = answer[j];

			answer[j] = sum;
			
			if (sum < tmp) sum += 10007;
			sum -= tmp;
		}
		for (int j = 0; j < 10; j++)
		{
			sum += answer[j];
			sum %= 10007;
		}
	}

	cout << sum << endl;
}