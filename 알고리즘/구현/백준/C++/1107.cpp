// 리모컨
// M개의 숫자 버튼이 고장났다. 나머지 숫자버튼과 +, - 버튼을 사용하여, 현재 채널 100에서 원하는 채널 N을 트는데 걸리는 최소 횟수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 500001
#define MAX_M 11
#define INF 987654321

using namespace std;

bool BrokenButton[10];

inline int abs(int num)
{
	return (num >= 0 ? num : -1 * num);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int ans = INF;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int button = 0;
		 
		cin >> button;
		BrokenButton[button] = true;
	}

	for (int i = 0; i < MAX_N+MAX_N; i++)
	{
		int channel = i;
		int DecNum = 1;
		int flag = 1;
		int cnt = 0;
		int CntPM = 0;
		
		while (i/DecNum > 0 || (i == 0 && DecNum == 1))
		{
			if (BrokenButton[channel - (channel / 10) * 10])
			{
				flag = 0;
				break;
			}
			else
			{
				cnt++;
			}

			channel /= 10;
			DecNum *= 10;
		}

		if (flag)
		{
			CntPM = abs(N-i);

			ans = (ans < cnt+CntPM ? ans : cnt+CntPM);
			/*
			cout << "channel = " << i << ' '
				<< "ans = " << ans << ' '
				<< "cnt = " << cnt << ' '
				<< "CntPM = " << CntPM << endl;
				*/
		}

	}

	cout << (ans < abs(N - 100) ? ans : abs(N - 100)) << '\n';
}