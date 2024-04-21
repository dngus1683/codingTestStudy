// solved.ac
// solved.ac는 백준 문제에 사용자들이 직접 난이도를 부여한다. 난이도 부여는 정수로 부여하며, 주어진 난이도들을 30% 절사평균 내어 최종 난이도로 결정한다.
// 절사평균은 최댓값과 최솟값을 제외한 평균값인데, 여기서 30% 절사평균은 상위 15%, 하위 15%를 제외한 나머지 평균이다.
// 사용자들이 부여한 난이도가 n개 주어질 때 해당 문제의 최종 난이도를 구하라.


// 내 답안1
// 기댓값 방식으로 계산 - 44% 오답
// #include <iostream>
// #include <algorithm>
// #include <cmath>

// #define MAX_N 300001

// using namespace std;

// double arr[MAX_N];

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n, exc;
// 	double ans = 0;

// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		cin >> arr[i];

// 	sort(arr, arr + n);

// 	exc = round((double)n * 0.15);

// 	for (int i = exc; i < n - exc; i++)
// 	{
// 		ans += arr[i];
// 	}

// 	if (n == 0) cout << ans << '\n';
// 	else
// 	{
// 		ans /= (n - 2 * exc);
// 		cout << round(ans) << '\n';
// 	}
// }



// 내 답안2
// 일반적인 평균 계산 - 정답
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_N 300001

using namespace std;

double arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, exc;
	double ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	exc = round((double)n * 0.15);

	for (int i = exc; i < n - exc; i++)
	{
		ans += arr[i] / ((double)n - 2.0 * (double)exc);
	}

	cout << round(ans) << '\n';
}