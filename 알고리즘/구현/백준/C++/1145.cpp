// 적어도 대부분의 배수
// 서로 다른 다섯 개의 자연수가 주어질 때, 적어도 세 개의 수의 공배수 중 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int answer = 100;

	for (int i = 0; i < 5; i++)
	{
		int num = 0;

		cin >> num;
		arr.push_back(num);

		answer = (answer > num ? num : answer);
	}

	while (true)
	{
		int cnt = 0;
		for (auto num : arr)
		{
			if (answer % num == 0)
				cnt++;
		}

		if (cnt >= 3)
			break;
		else
			answer++;
	}

	cout << answer << '\n';

}