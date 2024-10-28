// 두 수의 합
// N개의 서로 다른 양의 정수가 주어질 때, 두 정수의 합이 x가 되는 쌍의 수를 구하라.


// 내 답안1
#include <iostream>
#include <unordered_map>

#define MAX_N 100001

using namespace std;

int N = 0;
int x = 0;
int answer = 0;
int arr[MAX_N];
unordered_map<int, bool> hmap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		hmap[arr[i]] = true;
	}
	cin >> x;

	for (int i = 0; i < N; i++)
	{
		if (hmap[arr[i]] && hmap[x - arr[i]] && (arr[i] != x - arr[i]))
		{
			hmap[x - arr[i]] = false;
			hmap[arr[i]] = false;
			answer++;
		}
	}

	cout << answer << '\n';
}