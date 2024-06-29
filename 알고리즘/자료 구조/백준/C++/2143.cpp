// 두 배열의 합
// 한 배열에 대한 부 배열은 연속되는 인덱스의 원소 배열을 의미한다. 두 배열 A, B가 주어졌을 때, 두 배열의 부 배열의 합끼리의 합이 T가 되는 경우의 수를 구하라.


// 내 답안1
// 먼저 A의 조합을 구한 다음, 해당 값을 해시 테이블에 key값으로 저장. value는 개수. 
// 그런 다음, B의 조합을 구해, T - B조합 값이 해시 테이블에 있다면, value 값을 최종 경우의 수에 더함.
#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 1001

using namespace std;


int T = 0;
int N = 0;
int M = 0;
vector<int> A;
vector<int> B;
unordered_map<long long, long long> HashMap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long answer = 0;

	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		A.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num = 0;

		cin >> num;
		B.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		long long sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += A[j];
			HashMap[sum]++;
		}
	}

	for (int i = 0; i < M; i++)
	{
		long long sum = 0;
		for (int j = i; j < M; j++)
		{
			sum += B[j];
			if (HashMap.find(T - sum) != HashMap.end())
			{
				answer += HashMap[T - sum];
			}
		}
	}

	cout << answer << '\n';
}
