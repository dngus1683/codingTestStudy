// 크냑과 3D프린터
// 밑면의 가로 세로가 1이고 높이가 hi인 직육면체를 빈틈없이 일렬로 세워 붙인 3D 모형의 총 겉넓이를 구하라.


// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
long long answer = 0;
vector<int> h;

inline int abs(int a)
{
	return (a >= 0 ? a : -a);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		h.push_back(num);
	}

	answer += h[0] * 3 + 1 * 2;

	for (int i = 1; i < h.size(); i++)
	{
		answer += h[i] * 2 + 1 * 2;
		answer += abs(h[i] - h[i - 1]);
	}
	answer += h[N - 1];

	cout << answer << '\n';
}

