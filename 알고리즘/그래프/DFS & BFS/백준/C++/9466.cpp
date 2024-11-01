// 텀 프로젝트
// N명의 학셍들이 텀 프로젝트 팀을 구성한다. 각자가 원하는 팀원 한명 씩 지목하였고(혼자 하고 싶은 경우는 본인 선택) 팀원들 모두 본인 희망사항이 만족되었을 때 팀이 구성된다고 할 때,
// 어느 팀에도 속하지 못한 학생의 수를 구하라.


// 내 답안1
// dfs 활용.
// 방문 여부 배열과 상태 배열을 따로 분리.
#include <iostream>
#include <vector>

#define MAX_N 100'001

using namespace std;

int T = 0;
int N = 0;
int graph[MAX_N];

int dfs(int now, vector<bool>& visited, vector<short>& state)
{
	if (visited[now])
	{
		state[now] = 1;
		return now;
	}

	int next = graph[now];

	visited[now] = true;

	if (state[next] != 0)
	{
		state[now] = -1;
		return -1;
	}

	int StartPoint = dfs(next, visited, state);
	
	if (StartPoint == now)
	{
		return -1;
	}
	else if (StartPoint == -1)
	{
		state[now] = -1;
		return -1;
	}
	else
	{
		state[now] = true;
		return StartPoint;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		int answer = 0;
		vector<short> state(MAX_N);

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> graph[i];
		}

		for (int i = 1; i <= N; i++)
		{
			vector<bool> visited(MAX_N);
			if (state[i] == 0)
			{
				dfs(i, visited, state);
			}
			if (state[i] == -1)
			{
				answer++;
			}
		}
		cout << answer << '\n';
	}
}





// 답안 예시1 - https://www.acmicpc.net/source/85399419
// dfs를 활용.
// 한번 방문한 곳을 또 방문했을 때, 해당 위치부터 사이클의 첫번째 위치까지 for문을 활용하여 counting.
// 총 인원에서 최종 counting 된 수를 뺀다.
/*
#include <iostream>
#include <vector>

using namespace std;

int count;
vector<int> visited, nums;

void DFS(int now) {
	visited[now] = 1;
	int next = nums[now];

	if(visited[next] == 0) {
		DFS(next);
	}
	else if(visited[next] == 1) {
		for(int i=next; i!=now; i=nums[i]) {
			count++;
		}
		count++;
	}

	visited[now] = 2;
}

int main(int args, char const *argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		count = 0;
		nums = vector<int>(n+1);
		for(int i=1; i<=n; i++) cin >> nums[i];

		visited = vector<int>(n+1, 0);

		for(int i=1; i<=n; i++) {
			if(visited[i] == 0) {
				DFS(i);
			}
		}

		cout << n - count << "\n";
	}

	return 0;
}
*/