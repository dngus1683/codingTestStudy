// 좌표 정렬하기 2
// 2차원 좌표가 N개 주어진다. y를 기준 오름차순으로, y값이 같다면 x가 증가하는 순으로 정렬하라.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 100001

using namespace std;

typedef struct point
{
	int x, y;
}point;

bool compare(point a, point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
		
}

point arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}
	
	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}

}
