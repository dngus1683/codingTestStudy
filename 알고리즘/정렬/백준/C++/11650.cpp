// 좌표 정렬하기
// 2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.


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
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else
		return a.x < b.x;
}

point arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;

		cin >> a >> b;
		arr[i].x = a;
		arr[i].y = b;
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}


}