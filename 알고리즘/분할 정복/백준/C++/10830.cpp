// 행렬 제곱
// 크기가 N x N인 행렬 A가 주어질 때, A의 B 제곱을 구하라. 이때 각 원소를 1,000으로 나눈 나머지를 출력한다.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 5
#define MAX_B 100'000'000'000
#define ULLint unsigned long long int

using namespace std;

vector<vector<int>> mat;

vector<vector<int>> operator* (vector<vector<int>> a, vector<vector<int>> b)
{
	int size = a.size();
	vector<vector<int>> newV;

	for (int i = 0; i < size; i++)
	{
		vector<int> row;
		for (int j = 0; j < size; j++)
		{
			int element = 0;
			for (int k = 0; k < size; k++)
			{
				element += (a[i][k] * b[k][j]) % 1000;
				element %= 1000;
			}
			row.push_back(element % 1000);
		}
		newV.push_back(row);
	}

	return newV;
}

vector<vector<int>> DCPow(vector<vector<int>> m, ULLint B)
{
	if (B == 1)
	{
		return m;
	}
	else
	{
		vector<vector<int>> half = DCPow(m, B / 2);
		if (B % 2 == 1)
			return half * half * m;
		else
			return half * half;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	ULLint B = 0;

	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		vector<int> row;
		for (int j = 0; j < N; j++)
		{
			int element = 0;
			cin >> element;
			row.push_back(element % 1000);
		}
		mat.push_back(row);
	}
	vector<vector<int>> a = DCPow(mat, B);

	for (int i = 0; i < a.size(); i++)
	{

		for (int j = 0; j < a.size(); j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}