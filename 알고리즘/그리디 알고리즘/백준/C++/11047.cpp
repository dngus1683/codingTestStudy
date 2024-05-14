// 동전 0
// 준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
// 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다.이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
// 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)


// 내 답안1
#include <iostream>

#define MAX_N 11
#define MAX_K 100'000'001
#define MAX_A 1'000'001

using namespace std;

int coin[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;
	int ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (coin[i] > K) continue;

		ans += K / coin[i];
		K = K % coin[i];
	}

	cout << ans << '\n';


}