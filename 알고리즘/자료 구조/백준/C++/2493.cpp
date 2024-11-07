// 탑
// N개의 탑의 높이가 주어진다. 모든 탑의 꼭대기에서 왼쪽방향으로 레이저를 지면에 수평인 방향으로 쏜다.
// 각 탑이 쏜 레이저를 어느 탑이 먼저 수신하는지 구하라.


// 내 답안1
#include <iostream>
#include <stack>
#include <vector>
#define MAX_N 500'001

using namespace std;

int N = 0;
int subNumIdx = 0;
vector<int> height(MAX_N);
vector<int> answer(MAX_N);
stack<int> stMain;
stack<int> stSub;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> height[i];
		stMain.push(i);
	}
	stSub.push(stMain.top());
	stMain.pop();


	while (!stMain.empty())
	{
		int curNum = stMain.top();
		stMain.pop();

		while (!stSub.empty())
		{
			if (height[curNum] >= height[stSub.top()])
			{
				answer[stSub.top()] = curNum;
				stSub.pop();
			}
			else if (height[curNum] < height[stSub.top()])
			{
				break;
			}
		}
		stSub.push(curNum);
	}

	while (!stSub.empty())
	{
		answer[stSub.top()] = 0;
		stSub.pop();
	}

	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << ' ';
	}
	cout << '\n';




}