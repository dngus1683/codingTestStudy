// 시험 감독
// N개의 시험장이 있고, i번 시험장에는 Ai명의 응시자가 있다. 각 시험장에는 한 명의 총감독관과 한 명 이상의 부감독관이 있다. 
// 총감독관은 B명 감시할 수 있고 부감독관은 C명 감시할 수 있다고 할 때, 각 시험장마다 응시생들을 모두 감시할 때 필요한 감독관 수의 최솟값을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 1'000'001
#define MAX_A 1'000'001
#define MAX_BC 1'000'001

using namespace std;

int person[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N = 0;
	int B = 0;
	int C = 0;
	long long ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> person[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		ans += 1;
		if (person[i] - B > 0)
		{
			ans += ((person[i] - B - 1) / C + 1);
		}
	}
	cout << ans << '\n';
}