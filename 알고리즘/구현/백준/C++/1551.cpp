// 수열의 변화
// 크기가 N인 배열이 주어진다. 해당 배열에 인접한 두 원소의 차로 이루어진 N-1크기의 배열을 만든다고 할 때,
// 이러한 계산을 K번 했을 때 나오는 수열을 구하라.


// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

void func(vector<int>& vec)
{
	for (int i = 0; i < vec.size()-1; i++)
	{
		vec[i] = vec[i + 1] - vec[i];
	}
	vec.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;
	vector<int> vec;

	cin >> N >> K;
	for (int i = 0; i < N*2-1; i++)
	{
		if (i % 2)
		{
			char comma;
			cin >> comma;
		}
		else
		{
			int num = 0;
			cin >> num;
			vec.push_back(num);
		}
	}

	for (int i = 0; i < K; i++)
	{
		func(vec);
	}
	for (int i = 0; i < vec.size()*2-1; i++)
	{
		if (i % 2)
		{
			cout << ',';
		}
		else
		{
			cout << vec[i / 2];
		}
	}
	cout << endl;
}