// 수열 정렬
// 수열 정렬
// 길이가 N인 수열 A를 B[P[i]]=A[i]를 통해 비내림차순이 되는 수열 B를 만들려고 한다. 이때 배열 P를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 51
#define MAX_NUM 1001

using namespace std;

int N = 0;
int cnt[MAX_NUM];
vector<int> arr(MAX_N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				count++;
			}

		}
		count += cnt[arr[i]];
		cout << count << ' ';
		cnt[arr[i]]++;
	}
	cout << '\n';
}
