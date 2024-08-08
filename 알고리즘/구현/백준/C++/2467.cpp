// 용액
// 1~1,000,000,000의 값을 갖는 산성용액과, -1,000,000,000~-1의 값을 갖는 알칼리용액들이 N개 주어진다. 두 개의 용액을 섞었을 때, 계산되는 특성값(두 용액의 합)이 0에 가장 가까운 경우를 구하라.


// 내 답안1
// two pointer
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void TwoPointer(int left, int right, vector<int>& vec)
{
	int sum = 2000000002;
	vector<int> answer(2);

	while (left < right)
	{
		int tmp = vec[left] + vec[right];

		if (sum > abs(tmp))
		{
			sum = abs(tmp);
			answer[0] = vec[left];
			answer[1] = vec[right];
		}
		if (tmp > 0)
		{
			right--;
		}
		else if (tmp < 0)
		{
			left++;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		cout << answer[i] << ' ';
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	vector<int> vec;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	TwoPointer(0, N - 1, vec);

}