// 숫자 카드
// N개의 숫자 카드가 주어진다. 정수 M개가 주어질 때, 그 수의 숫자카드를 가지고 있는지 출력하라.


// 내 답안1
#include <iostream>
#include <unordered_map>

#define MAX_N 500'001

using namespace std;

int N = 0;
int M = 0;
unordered_map<int, bool> hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		hmap[num] = true;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num = 0;

		cin >> num;
		if (hmap.find(num) == hmap.end())
		{
			cout << 0 << ' ';
		}
		else
		{
			cout << 1 << ' ';
		}
	}
	cout << '\n';
}



// 답안 예시1 - https://www.acmicpc.net/source/43029995
// bitset 사용.
/*
#include <iostream>
#include <bitset>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
	Max = 20'000'000+1,
	Offset = 10'000'000
};
bitset<Max> bits;
int N, M;
int main()
{
	FASTIO;
	cin >> N;
	M_Loop(i, 0, N)
	{
		int n; cin >> n;
		bits[n+Offset] = 1;
	}
	cin >> M;
	M_Loop(i, 0, M)
	{
		int m; cin >> m;
		if (bits[m + Offset]) cout << 1 << " ";
		else cout << 0 << " ";
	}
	return 0;
}
*/