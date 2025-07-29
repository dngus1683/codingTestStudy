// 세 수의 합
// N개의 수 중 세 수를 골라 더했을 때 그 수가 그 집합에 있는 경우 그 수가 가장 큰 경우를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define MAX_N 1'001

using namespace std;

vector<int> vec(MAX_N);
unordered_set<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];

		dp.insert(vec[i]);
	}

	sort(vec.begin(), vec.end(), greater<>());

	for (int i = 0; i < N ; i++)
	{
		for (int j = i+1; j < N ; j++)
		{
			int target = vec[i] - vec[j];

			int l = j;
			int r = N - 1;

			while (l < r)
			{
				int mid = (l + r) / 2;

				if (vec[mid] > (target / 2))
				{
					l = mid + 1;
				}
				else if (vec[mid] < (target / 2))
				{
					r = mid - 1;
				}
				else
				{
					break;
				}
			}

			if (l > (j + N - 1) / 2)
			{
				for (int k = l; k < N; k++)
				{
					if (dp.find(target - vec[k]) != dp.end())
					{
						answer = max(answer, vec[i]);
					}

				}
			}
			else
			{
				for (int k = j ; k <= l; k++)
				{
					if (dp.find(target - vec[k]) != dp.end())
					{
						answer = max(answer, vec[i]);
					}

				}
			}
		}
	}
	cout << answer;

	return 0;

}
