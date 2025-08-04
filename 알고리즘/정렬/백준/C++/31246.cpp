// 모바일 광고 입찰
// 광고 대행사에서 광고지면 경매를 대행한다.
// 대행사가 제시한 입찰가 A와, 대행사를 제외한 최고 입찰가 B가 주어질 때, 
// 최소 K개 이상의 지면을 낙찰받기 위한 입찰가 추가 금액 X의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;
	vector<int> Xs;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int A = 0;
		int B = 0;

		cin >> A >> B;
		
		Xs.push_back(B - A);
	}
	sort(Xs.begin(), Xs.end());

	cout << (Xs[K - 1] > 0 ? Xs[K - 1] : 0) << '\n';
}