// 킹
// 체스판 위에 킹과 돌이 하나 씩 주어진다. 돌이 있는 곳에 킹이 이동한다면, 돌은 킹과 같은 방향으로 한 칸 이동시킨다.
// 킹의 행동이 주어질 때, 최종 킹과 돌의 위치를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Position
{
	int i;
	int j;
	bool operator ==(const Position& other)const
	{
		return (i == other.i && j == other.j);
	}
};

int N = 0;
int di[8] = {0, 0, -1, 1, 1, 1, -1, -1 };
int dj[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int trans(string& s)
{
	if (s == "R") return 0;
	if (s == "L") return 1;
	if (s == "B") return 2;
	if (s == "T") return 3;
	if (s == "RT") return 4;
	if (s == "LT") return 5;
	if (s == "RB") return 6;
	if (s == "LB") return 7;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Position posKing;
	Position posStone;
	string sk = "";
	string ss = "";

	cin >> sk >> ss >> N;

	posKing.i = sk[1] - '0';
	posKing.j = sk[0] - 'A';
	posStone.i = ss[1] - '0';
	posStone.j = ss[0] - 'A';

	for (int i = 0; i < N; i++)
	{
		int dir = 0;
		string move = "";

		cin >> move;
		dir = trans(move);

		Position nextKing = { posKing.i + di[dir], posKing.j + dj[dir] };
		Position nextStone = { posStone.i + di[dir], posStone.j + dj[dir] };

		if (nextKing.i <= 0 || nextKing.i > 8 || nextKing.j < 0 || nextKing.j >= 8) continue;

		if (nextKing == posStone && (nextStone.i <= 0 || nextStone.i > 8 || nextStone.j < 0 || nextStone.j >= 8)) continue;


		posKing = nextKing;
		if (nextKing == posStone)
		{
			posStone = nextStone;
		}
	}
	cout << (char)(posKing.j + 'A') << posKing.i << '\n' << (char)(posStone.j + 'A') << posStone.i ;
}