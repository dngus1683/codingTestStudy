// 덩치
// N명의 사람의 체중과 키가 주어진다. 두 사람의 체중과 무게를 비교했을 때, 두 요소 모두 한 쪽이 크다면 해당 사람이 덩치가 더 크다고 정의한다. 
// 본인보다 덩치가 큰 사람의 수를 k라 할 때, 각자의 덩치 순위는 k+1등이다.
// 모두의 덩치 순위를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 51

using namespace std;

typedef struct person
{
	int kg, cm;
}person;

person people[MAX_N];
int ans[MAX_N] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> people[i].kg >> people[i].cm;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (people[i].kg < people[j].kg && people[i].cm < people[j].cm)
				ans[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ++ans[i] << ' ';
	cout << '\n';
}