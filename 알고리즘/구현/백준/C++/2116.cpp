// 주사위 쌓기
// 마주보는 숫자의 합이 7이 아닌 주사위를 수직으로 쌓는다. 각 주사위의 수 배치는 다르다. 이때, 맞닿는 두 주사위의 면의 수가 같아야 한다.
// 수직으로 세웠을 때, 4개의 긴 옆면 중 그 수들의 합의 최댓값을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 10'001

using namespace std;

int N = 0;
int answer = 0;
int opposite[6] = { 5, 3, 4, 1, 2, 0 };
int dice[MAX_N][7];

int dfs(int bottom, int layer)
{
	if (layer == N)
	{
		return 0;
	}

	int top = dice[layer][bottom];
	int returnValue = 0;

	if (bottom != 6 && top != 6)
	{
		returnValue = 6;
	}
	else if (bottom != 5 && top != 5)
	{
		returnValue = 5;
	}
	else
	{
		returnValue = 4;
	}
	returnValue += dfs(top, layer + 1);

	return returnValue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int arr[6] = { 0, };
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[j];

		}
		for (int j = 0; j < 6; j++)
		{
			dice[i][arr[opposite[j]]] = arr[j];
		}
	}

	for (int i = 1; i <= 6; i++)
	{
		answer = max(answer, dfs(dice[0][i], 0));
	}

	cout << answer << '\n';
}