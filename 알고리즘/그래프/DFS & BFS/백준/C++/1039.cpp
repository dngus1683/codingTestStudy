// 교환
// 정수 N이 주어진다. 해당 정수의 임의의 자릿수 두 개의 위치를 K번 바꾼다. 
// 최종적으로 연산된 수의 최댓값을 구하라.


// 내 답안1
#include <iostream>
#include <queue>
#include <set>
#include <string>

#define MAX_N 1'000'001
#define MAX_K 11

using namespace std;

typedef struct Node
{
	int depth;
	string s;

	bool operator < (const Node& other) const
	{
		if (s != other.s)
		{
			return s < other.s;
		}
		else
		{
			return depth < other.depth;
		}
	}
};

inline int max(const int& a, const int& b)
{
	return (a > b ? a : b);
}

int bfs(string& start, int depth)
{
	int answer = 0;
	queue<Node> q;
	set<Node> visited;

	q.push({ 0, start });
	visited.insert({ 0, start });

	while (!q.empty())
	{
		int nowD = q.front().depth;
		string nowS = q.front().s;
		q.pop();

		if (nowD == depth)
		{
			answer = max(answer, stoi(nowS));
			continue;
		}

		for (int i = 0; i < nowS.length(); i++)
		{
			for (int j = i + 1; j < nowS.length(); j++)
			{
				int nextD = nowD + 1;
				string nextS = nowS;

				swap(nextS[i], nextS[j]);

				if (nextS[0] == '0') continue;
				
				if (visited.find({ nextD, nextS }) == visited.end())
				{
					visited.insert({nextD, nextS});
					q.push({ nextD, nextS });
				}
			}
		}
	}

	return answer;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K = 0;
	int answer = 0;
	string N = "";
	

	cin >> N >> K;

	answer = bfs(N, K);

	cout << (answer == 0 ? -1 : answer) << '\n';

}
