// 쿼드 트리
// 쿼드 트리는 흑백 영상을 압축하여 표현하는 데이터 구조 중 하나이다.
// 주어진 영상이 흰색으로만 이루어져 있으면 0으로 압축하고, 검은색으로만 이루어져 있으면 1로 압축한다.
// 만약 섞여있다면 (좌상, 우상, 좌하, 우하) 네 구역으로 나눠 한 가지 만으로 이뤄져 있을 때까지 반복하여 압축한다.
// N x N 크기의 영상 정보가 주어질 때, 이를 압축하라.


// 내 답안1
#include <iostream>
#include <string>

#define MAX_N 64
using namespace std;

int N = 0;
char graph[MAX_N][MAX_N];
string answer = "";

void DC(int startI, int endI, int startJ, int endJ, int length)
{
	for (int i = startI; i < endI; i++)
	{
		for (int j = startJ; j < endJ; j++)
		{
			if (graph[startI][startJ] != graph[i][j])
			{
				answer += '(';
				DC(startI, startI + length / 2, startJ, startJ + length / 2, length / 2);
				DC(startI, startI + length / 2, startJ + length / 2, endJ, length / 2);
				DC(startI + length / 2, endI, startJ, startJ + length / 2, length / 2);
				DC(startI + length / 2, endI, startJ + length / 2, endJ, length / 2);
				answer += ')';
				return;
			}
		}
	}
	answer += graph[startI][startJ];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}
	DC(0, N, 0, N, N);

	cout << answer << endl;
}