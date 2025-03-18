// ZOAC 4
// H x W 크기의 맵에 사람을 최대한 많이 배치하려 한다. 이때, 세로로 N, 가로로 M 만큼은 최소 띄워 앉아야 한다.
// 최대 수용 인원 수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int H = 0;
int W = 0;
int N = 0;
int M = 0;

int cal(int a, int b)
{
	return ((a / (b + 1)) + (a % (b + 1) != 0));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> N >> M;

	cout << cal(H, N) * cal(W, M) << endl;

}


