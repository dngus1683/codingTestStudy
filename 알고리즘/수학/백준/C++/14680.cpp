// 효빈이의 과외
// 행렬의 곱셈을 구현하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MOD_NUM 1'000'000'007
#define ull unsigned long long

using namespace std;

int N = 0;
ull answer = 0;
vector<vector<vector<ull>>> Mats;
vector<vector<ull>> answerMat;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int cnt = 0; cnt < N; cnt++)
	{
		int X = 0;
		int Y = 0;

		cin >> X >> Y;

		vector<vector<ull>> mat(X, vector<ull>(Y));
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				cin >> mat[i][j];
			}
		}
		Mats.push_back(mat);
	}

	answerMat = Mats[0];
	for (int i = 1; i < N; i++)
	{
		if (answerMat[0].size() != Mats[i].size())
		{
			cout << -1 << '\n';
			return 0;
		}

		int row = answerMat.size();
		int column = Mats[i][0].size();

		vector<vector<ull>> temp(row, vector<ull>(column));
		for (int ii = 0; ii < answerMat.size(); ii++)
		{
			for (int jj = 0; jj < Mats[i][0].size(); jj++)
			{
				ull num = 0;
				for (int iii = 0; iii < Mats[i].size(); iii++)
				{
					num += (answerMat[ii][iii] * Mats[i][iii][jj]);
					num %= MOD_NUM;
				}
				temp[ii][jj] = num;
			}
		}
		answerMat = temp;
	}

	for (vector<ull> vec : answerMat)
	{
		for (ull num : vec)
		{
			answer += num;
			answer %= MOD_NUM;
		}
	}

	cout << answer << '\n';
}