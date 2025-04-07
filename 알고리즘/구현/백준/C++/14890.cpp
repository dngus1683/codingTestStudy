// 경사로
// N x N 크기의 지도에 경사도가 주어진다. 각 행과 열의 시작점부터 끝지점까지의 경로를 길이라 한다. 
// 같은 경사도에 대해서만 지나갈 수 있으며, L길이의 경사로를, 경사도가 1만큼만 낮은 타일 L개에 놓을 수 있으면 1 높은 경사도 타일로 이동 가능하다.
// 지도가 주어졌을 때, 지나갈 수있는 길의 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 101

using namespace std;

int N = 0;
int L = 0;
int answer = 0;
int graph[MAX_N][MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 가로줄 확인
	for (int i = 0; i < N; i++)
	{
		bool possible = true;
		bool flag[MAX_N] = { 0, };
		int idx = 1;
		int pre = graph[i][0];

		while (idx != N)
		{
			int now = graph[i][idx];

			if ((pre - now > 1) || (now - pre > 1))
			{
				possible = false;
				break;
			}
			else if (pre == now)
			{
				pre = now;
				idx++;
			}
			else if (pre - now == 1)
			{
				int cnt = L;

				while (cnt--)
				{
					if (idx == -1 || idx == N)
					{
						possible = false;
						break;
					}

					now = graph[i][idx];

					if (pre - now != 1)
					{
						possible = false;
						break;
					}
					flag[idx++] = true;
				}
				pre = now;
			}
			else if (now - pre == 1)
			{
				int cnt = L;
				idx--;

				while (cnt--)
				{
					if (idx == -1 || idx == N)
					{
						possible = false;
						break;
					}

					pre = graph[i][idx];

					if (now - pre != 1 || flag[idx])
					{
						possible = false;
						break;
					}
					flag[idx--] = true;
				}
				idx += (L + 2);
				pre = now;
			}
			if (!possible) break;
		}
		if (possible) answer++;
	}
	// 세로줄 확인
	for (int j = 0; j < N; j++)
	{
		bool possible = true;
		bool flag[MAX_N] = { 0, };
		int idx = 1;
		int pre = graph[0][j];

		while (idx != N)
		{
			int now = graph[idx][j];

			if ((pre - now > 1) || (now - pre > 1))
			{
				possible = false;
				break;
			}
			else if (pre == now)
			{
				pre = now;
				idx++;
			}
			else if (pre - now == 1)
			{
				int cnt = L;

				while (cnt--)
				{
					if (idx == -1 || idx == N)
					{
						possible = false;
						break;
					}

					now = graph[idx][j];

					if (pre - now != 1)
					{
						possible = false;
						break;
					}
					flag[idx++] = true;
				}
				pre = now;
			}
			else if (now - pre == 1)
			{
				int cnt = L;
				idx--;

				while (cnt--)
				{
					if (idx == -1 || idx == N)
					{
						possible = false;
						break;
					}

					pre = graph[idx][j];

					if (now - pre != 1 || flag[idx])
					{
						possible = false;
						break;
					}
					flag[idx--] = true;
				}
				idx += (L + 2);
				pre = now;
			}

			if (!possible) break;
		}
		if (possible) answer++;
	}

	cout << answer << '\n';
}






// 답안 예시 - https://www.acmicpc.net/source/24154725
// 오르막 타일을 놓을 개수를 C로 세는 방식
// 같은 기능을 하는 코드를 배열의 행과 열에 따로 적용할 때 코드를 절약하는 방법으로, 해당 배열을 전치해서 복사한 후 한꺼번에 처리.
/*
#include<stdio.h>
int main(){
	int N, L, ans=0, M, i, j, c;
	short A[200][100];
	scanf("%d %d", &N, &L);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%hd", &A[i][j]);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	A[i+N][j]=A[j][i];
	M=2*N;
	for(i=0;i<M;++i){
		c=1;
		for(j=0;j<N-1;++j){
			if(A[i][j]==A[i][j+1])	++c;
			else if(A[i][j]+1==A[i][j+1] && c>=L)	c=1;
			else if(A[i][j]-1==A[i][j+1] && c>=0)	c=-L+1;
			else	break;
		}
		if(j==N-1 && c>=0)	++ans;
	}
	printf("%d\n", ans);
	return 0;
}
*/