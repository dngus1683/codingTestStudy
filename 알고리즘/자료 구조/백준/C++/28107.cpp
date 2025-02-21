// 회전초밥
// N명의 손님이 각자가 먹고 싶어하는 초밥의 종류가 주어진다. 요리사는 M개의 각기 다른 초밥을 제작하며, 초밥은 1번 손님부터 앞으로 지나가게 된다.
// 손님들은 먹고 싶어하는 초밥은 무조건 먹고, 그렇지 않은 초밥은 무조건 먹지 않을 때, 각 손님이 먹는 초밥의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <queue>

#define MAX_N 100'001
#define MAX_M 200'001
#define MAX_A 200'001

using namespace std;

int N = 0;
int M = 0;
int k = 0;
int answer[MAX_N];
queue<int> A[MAX_A];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> k;

		for (int j = 0; j < k; j++)
		{
			int num = 0;

			cin >> num;
			A[num].push(i);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int num = 0;

		cin >> num;

		if (!A[num].empty())
		{
			answer[A[num].front()]++;
			A[num].pop();
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << ' ';
	}
}