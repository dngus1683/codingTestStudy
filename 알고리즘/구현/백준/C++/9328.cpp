// 열쇠
// 빌딩의 정보가 주어질 때, 빌딩 바닥에 놓여있는 열쇠를 얻어 훔칠 수 있는 문서의 최대 개수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

#define MAX_H 101
#define MAX_W 101
#define ALPHATRANS 'A'-'a'
using namespace std;

int h = 0;
int w = 0;
int T = 0;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

void dfs(int nowI, int nowJ, int& answer, bool& flag, vector<vector<bool>>& visited, vector<vector<char>>& board, unordered_set<char>& keys)
{
	visited[nowI][nowJ] = true;

	for (int d = 0; d < 4; d++)
	{
		int nextI = nowI + di[d];
		int nextJ = nowJ + dj[d];

		if (nextI < 0 || nextI >= h || nextJ < 0 || nextJ >= w) continue;
		if (visited[nextI][nextJ]) continue;

		if (board[nextI][nextJ] == '.')
		{
			dfs(nextI, nextJ, answer, flag, visited, board, keys);
		}
		else if (board[nextI][nextJ] >= 'A' && board[nextI][nextJ] <= 'Z' && keys.find(board[nextI][nextJ]) != keys.end())
		{
			board[nextI][nextJ] = '.';
			dfs(nextI, nextJ, answer, flag, visited, board, keys);
		}
		else if (board[nextI][nextJ] >= 'a' && board[nextI][nextJ] <= 'z')
		{
			keys.insert(board[nextI][nextJ] + ALPHATRANS);
			board[nextI][nextJ] = '.';
			flag = true;
			dfs(nextI, nextJ, answer, flag, visited, board, keys);
		}
		else if (board[nextI][nextJ] == '$')
		{
			answer++;
			board[nextI][nextJ] = '.';
			dfs(nextI, nextJ, answer, flag, visited, board, keys);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		string k = "";
		vector<pair<int, int>> entrance;
		vector<vector<char>> board(MAX_H, vector<char>(MAX_W));
		unordered_set<char> keys;

		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && board[i][j] != '*')
				{
					entrance.push_back({ i,j });
				}
			}
		}
		cin >> k;
		for (int i = 0; i < k.length(); i++)
		{
			if (k[i] == '0') continue;
			keys.insert((char)(k[i] + ALPHATRANS));
		}

		int answer = 0;

		while(true)
		{
			bool flag = false;
			vector<vector<bool>> visited(MAX_H, vector<bool>(MAX_W, false));
			for (pair<int, int> pos : entrance)
			{
				if (visited[pos.first][pos.second]) continue;

				if (board[pos.first][pos.second] == '.')
				{
					dfs(pos.first, pos.second, answer, flag, visited, board, keys);
				}
				if (board[pos.first][pos.second] == '$')
				{
					answer++;
					board[pos.first][pos.second] = '.';
					dfs(pos.first, pos.second, answer, flag, visited, board, keys);
				}
				else if (board[pos.first][pos.second] >= 'a' && board[pos.first][pos.second] <= 'z')
				{
					keys.insert(board[pos.first][pos.second] + ALPHATRANS);
					board[pos.first][pos.second] = '.';
					flag = true;
					dfs(pos.first, pos.second, answer, flag, visited, board, keys);
				}
				else if (board[pos.first][pos.second] >= 'A' && board[pos.first][pos.second] <= 'Z' && keys.find(board[pos.first][pos.second]) != keys.end())
				{
					board[pos.first][pos.second] = '.';
					dfs(pos.first, pos.second, answer, flag, visited, board, keys);
				}
			}
			if (!flag) break;
		}

		cout << answer << '\n';
	}
}