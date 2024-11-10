// 회전하는 큐
// N개의 원소를 포함하는 양방향 순환 큐가 있다. 일반큐처럼 가장 앞의 원소를 뽑아낼 수 있고, 앞 뒤로 원소들을 이동시킬 수 있다.
// 양방향 순환 큐에서 뽑아내고 싶은 원소의 위치가 M개 주어졌을 때, 해당 원소들을 뽑아내는데 원소를 옮기는 작업의 최소 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <deque>

#define MAX_N 51

using namespace std;

int N = 0;
int M = 0;
int start = 1;
int answer = 0;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int count = 0;
		int tar = 0;

		cin >> tar;

		while (dq.front() != tar)
		{	
			dq.push_back(dq.front());
			dq.pop_front();
			count++;
		}
		
		answer += (count > dq.size() - count ? dq.size() - count : count);
		dq.pop_front();
	}

	cout << answer << '\n';
}