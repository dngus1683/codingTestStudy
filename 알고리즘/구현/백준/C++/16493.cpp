// 최대 페이지 수
// 여러 챕터로 구성된 에세이 집을 반납 전까지 최대한 많은 챕터를 읽고자 할 때, 읽을 수 있는 최대 페이지 수를 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 201
#define MAX_M 21

using namespace std;

struct Book
{
	int day;
	int page;
};
int N = 0;
int M = 0;
vector<Book> VInfo(MAX_M);
int dp[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int day = 0;
		int page = 0;

		cin >> day >> page;
		VInfo[i].day = day;
		VInfo[i].page = page;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = N; j >= VInfo[i].day; j--)
		{
			dp[j] = max(dp[j], dp[j - VInfo[i].day] + VInfo[i].page);
		}
	}

	cout << dp[N] << endl;


}