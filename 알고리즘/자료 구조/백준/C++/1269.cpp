// 대칭 차집합
// 공집합이 아닌 두 집합 A, B가 주어질 때, A-B, B-A 두 차집합의 합집합을 구하라.


// 내 답안1
#include <iostream> 
#include <unordered_set>

using namespace std;

int A = 0;
int B = 0;
int answer = 0;
unordered_set<int> hset;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B;

	answer = A + B;
	for (int i = 0; i < A; i++)
	{
		int num = 0;

		cin >> num;

		hset.insert(num);
	}

	for (int i = 0; i < B; i++)
	{
		int num = 0;

		cin >> num;

		if (hset.find(num) != hset.end())
		{
			answer -= 2;
		}
	}

	cout << answer << '\n';
}