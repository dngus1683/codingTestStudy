// 하노이 탑 이동 순서
// 원판의 개수 N이 주어질 때, 최소 횟수로 원판 탑을 세번 째 장대로 옮기는 프로그램을 작성하라.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 21

using namespace std;

int N = 0;
vector<pair<int, int>> order;

void func(int height, int start, int mid, int end)
{
	if (height == 1)
	{
		order.push_back({ start, end });
		return;
	}
	func(height - 1, start, end, mid);
	order.push_back({ start, end });
	func(height - 1, mid, start, end);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	func(N, 1, 2, 3);

	cout << order.size() << endl;
	for (auto v : order)
	{
		cout << v.first << ' ' << v.second << '\n';
	}
	
}