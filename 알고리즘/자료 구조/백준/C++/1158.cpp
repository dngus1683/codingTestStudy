// 요세푸스 문제


// 내 답안1
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 5001

using namespace std;

int N = 0;
int K = 0;
int idx = -1;
queue<int> q;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	int cnt = 1;
	while (!q.empty())
	{	
		if (cnt++ == K)
		{
			cnt = 1;
			answer.push_back(q.front());
			q.pop();
			continue;
		}

		q.push(q.front());
		q.pop();
	}

	cout << '<';
	for (int i = 0; i < N - 1; i++)
	{
		cout << answer[i] << ", ";
	}
	cout << answer[N - 1] << '>' << '\n';

}