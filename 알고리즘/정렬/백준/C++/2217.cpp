// 로프
// N개의 로프가 들수 있는 중량 정보가 주어진다. 한 물체에 여러 로프를 병렬로 연결하면 해당 무게가 균등히 분산되어 들 수 있다.
// 로프 정보를 통해 들 수 있는 물체의 최대 무게를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N = 0;
int answer = 0;
vector<int> rope;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		rope.push_back(num);
	}

	sort(rope.begin(), rope.end());

	answer = rope[N - 1];

	for (int i = 0; i < N - 1; i++)
	{
		answer = max(answer, rope[i] * (N - i));
	}

	cout << answer << '\n';
}



