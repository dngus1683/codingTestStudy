// 나이순 정렬
// 나이와 이름이 주어지면, 나이가 증가하는 순으로, 동갑이라면 먼저 주어진 사람이 앞에 오는 순서로 정렬하라.


// 내 답안1
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_N 100001

using namespace std;

typedef struct person
{
	int age;
	string name;
	int order;
}person;

bool compare(person a, person b)
{
	if (a.age < b.age)
		return 1;
	else if (a.age == b.age && a.order < b.order)
		return 1;
	else
		return 0;
}

person arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a;
		string b;

		cin >> a >> b;
		arr[i] = { a, b, i };
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].age << ' ' << arr[i].name << '\n';
	}
}