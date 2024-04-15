// 숫자 카드2
// N장의 정수 카드와 정수 M개가 주어질 때, 이 정수들이 적혀있는 숫자 카드가 몇 장인지 구하라.


// 내 답안1
#include <iostream>
#include <map>

#define MAX_N 500001

using namespace std;

int arrN[MAX_N];
int arrM[MAX_N];
int ans[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	map<int, int> table;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (table.find(a) == table.end())
		{
			table.insert({ a,1 });
		}
		else
		{
			table.find(a)->second += 1;
		}
	}
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> arrM[i];
	}

	for (int i = 0; i < m; i++)
	{
		if (table.find(arrM[i]) == table.end())
			cout << 0 << ' ';
		else 
			cout << table.find(arrM[i])->second << ' ';
	}
}