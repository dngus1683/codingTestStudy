// 성 지키기
// 영식이는 직사각형 모양의 성을 가지고 있다. 성의 1층은 몇 명의 경비원에 의해서 보호되고 있다.
// 영식이는 모든 행과 모든 열에 한 명 이상의 경비원이 있으면 좋겠다고 생각했다.
// 성의 크기와 경비원이 어디있는지 주어졌을 때, 몇 명의 경비원을 최소로 추가해야 영식이를 만족시키는지 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>

using namespace std;

int N = 0;
int M = 0;
int answer = 0;
char state;
bool graphI[51];
bool graphJ[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool IsThere = false;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> state;

			if (state == 'X')
			{
				IsThere = true;
				graphJ[j] = true;
			}
		}
		if (IsThere)
		{
			graphI[i] = true;
		}
		IsThere = false;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!graphI[i] && !graphJ[j])
			{
				answer++;
				graphI[i] = true;
				graphJ[j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!graphI[i])
		{
			answer++;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (!graphJ[i])
		{
			answer++;
		}
	}
	cout << answer << '\n';

}