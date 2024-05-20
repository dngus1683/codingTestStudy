// 가장 가까운 세 사람의 심리적 거리
// MBTI는 총 4가지 유형의 성격을 두가지로 나눠 성격을 총 2^4 = 16가지로 나눈 것이다. 이때, 각 유형별로의 차이를 1이라 할 때(ex. INPF - INTF = 1, INPF - ENTF = 2), 
// 세 사람 사이의 심리적 거리는 두명씩 짝지어서 성격 차이 수를 모두 더한 값이다. 
// N명의 MBTI가 주어질 때, 세 사람의 심리적 거리의 최솟값을 구하라.


// 내 답안1
// 비둘기집 원리 - mbti는 총 16가지가 있기 때문에, 사람이 17명 이상이라면 최소 2명은 같은 mbti를 가진다.
//				 이를 확장하여, 사람이 33명 이상이라면 최소 3명은 같은 mbti를 가진다.
#include <iostream>

#define MAX_N 100'000

using namespace std;

int compare(char a[4], char b[4])
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i]) cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int N = 0;
		int ans = 100;
		char mbti[MAX_N][4];

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> mbti[i];

		if (N > 32) ans = 0;
		else
		{
			for (int i = 0; i < N - 2; i++) 
			{
				for (int j = i + 1; j < N - 1; j++) 
				{
					for (int k = j + 1; k < N; k++) 
					{
						int cnt = 0;
						cnt += compare(mbti[i], mbti[j]);
						cnt += compare(mbti[j], mbti[k]);
						cnt += compare(mbti[k], mbti[i]);
						ans = (ans > cnt ? cnt : ans);
					}
				}
			}

		}

		cout << ans << '\n';
	}
}