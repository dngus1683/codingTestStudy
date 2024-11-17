// 영역 구하기
// M x N 크기의 모눈 종이에 K개의 직사각형이 주어질 때, 해당 직사각형들로 인해 분리된 모눈 종이의 영역 개수와 각 영역의 넓이를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 101

using namespace std;

int M = 0;
int N = 0;
int K = 0;
int answer = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
bool IsRect[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> answerArr;


int dfs(int nowI, int nowJ)
{
	int count = 1;

	visited[nowI][nowJ] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int nextI = nowI + di[dir];
		int nextJ = nowJ + dj[dir];

		if (nextI >= M || nextI < 0 || nextJ >= N || nextJ < 0) continue;
		if (visited[nextI][nextJ] == true || IsRect[nextI][nextJ]) continue;

		count += dfs(nextI, nextJ);
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int i1 = 0;
		int j1 = 0;
		int i2 = 0;
		int j2 = 0;

		cin >> j1 >> i1 >> j2 >> i2;

		for (int ii = i1; ii < i2; ii++)
		{
			for (int jj = j1; jj < j2; jj++)
			{
				IsRect[ii][jj] = true;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false && IsRect[i][j] == false)
			{
				answerArr.push_back(dfs(i, j));
				answer++;
			}
		}
	}
	
	sort(answerArr.begin(), answerArr.end());

	cout << answer << '\n';
	for (int num : answerArr)
	{
		cout << num << ' ';
	}
	cout << '\n';
}