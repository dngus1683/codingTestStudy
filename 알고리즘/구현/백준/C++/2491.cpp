// 수열
// n개의 수가 주어진다. 해당 수열 내에 가장 긴 오름차순 또는 내림차순의 부분 수열의 길이를 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

using namespace std;

bool up = true;
int N = 0;
int now = 0;
int pre = 0;
int cnt = 1;
int same = 0;
int answer = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	cin >> pre;
	for (int i = 0; i < N-1; i++)
	{
		cin >> now;

		if (pre < now)
		{
			if (up)
			{
				cnt++;
			}
			else
			{
				answer = max(answer, cnt);
				cnt = 2 + same;
				up = true;
			}
			same = 0;
		}
		else if (pre > now)
		{
			if (up)
			{
				answer = max(answer, cnt);
				cnt = 2 + same;
				up = false;
			}
			else
			{
				cnt++;
			}
			same = 0;
		}
		else
		{
			same++;
			cnt++;
		}

		pre = now;
	}

	cout << max(answer, cnt) << '\n';


}