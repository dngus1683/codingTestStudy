// 스타트와 링크
// 짝수 N명의 사람이 같은 인원으로 스타트팀과 링크팀으로 나눠 축구를 한다. 이때, 두 사람이 팀이 되었을 때 팀에 부여되는 능력치 S_ij 정보가 주어질 때, 
// 두 팀의 능력치 차이의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 21

using namespace std;

int Stats[MAX_N][MAX_N];
bool team[MAX_N];

int MakeTeam(int start, int N, int cnt)
{
	if (cnt == N/2)
	{
		int ReturnValue = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				if (team[i] == team[j])
				{
					ReturnValue += (team[i] ? Stats[i][j] : -Stats[i][j]);
				}
			}
		}
		return ReturnValue;
	}
	int ReturnValue = 987654321;
	for (int i = start; i < N; i++)
	{
		team[i] = true;
		ReturnValue = min(abs(ReturnValue), abs(MakeTeam(i + 1, N, cnt + 1)));
		team[i] = false;

		if (cnt == 0) break;
	}
	return ReturnValue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;

			Stats[i][j] += num;
			Stats[j][i] = Stats[i][j];
		}
	}

	cout << MakeTeam(0, N, 0) << endl;
}