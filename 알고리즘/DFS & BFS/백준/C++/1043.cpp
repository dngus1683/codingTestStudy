// 거짓말
// 지민이는 M개의 파티에 참가하여 거짓말을 하려 한다. K명의 사람이 지민이의 말이 거짓말인 것을 알기 때문에 그들이 같은 파티에 참석한 사람들에게 진실을 알린다.
// 진실을 들은 자들 역시 다른 파티에 가서 진실을 알린다. 지민이는 진실을 모르는 사람들만 참석하는 파티에서만 거짓말을 할 수 있다.
// 지민이가 참석할 수 있는 파티의 최대 수를 구하라.


// 내 답안1
#include <iostream>
#include <set>

#define MAX_N 51

using namespace std;

int party[MAX_N][MAX_N];
set<int> graph[MAX_N];
int truth[MAX_N];
int visited[MAX_N];

void dfs(int x)
{
	visited[x] = true;
	for (auto const next : graph[x])
	{
		if (!visited[next]) dfs(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	int N = 0;
	int M = 0;
	int t = 0;

	cin >> N >> M;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> truth[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> party[i][0];
		for (int j = 1; j <= party[i][0]; j++)
		{
			cin >> party[i][j];
		}

		for (int j = 1; j <= party[i][0]-1; j++)
		{
			for (int k = j + 1; k <= party[i][0]; k++)
			{
				graph[party[i][j]].insert(party[i][k]);
				graph[party[i][k]].insert(party[i][j]);
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		if (!visited[truth[i]])
			dfs(truth[i]);
	}

	for (int i = 0; i < M; i++)
	{
		if (visited[party[i][1]])
			continue;
		else
			ans++;
	}
	cout << ans << '\n';
}









// 답안 예시1 - https://www.acmicpc.net/source/63365068
// 완전 탐색
/* 
#include <stdio.h>
int main(){
	int N,M;
	int k=0;
	int cnt=0;
	int tn;
	int check=0;
	int tnum[50]={0,};
	int party[50][51];
	scanf("%d %d",&N,&M);
	scanf("%d",&tn);
	for(int i=0;i<tn;i++){
		scanf("%d",&k);
		tnum[k]=1;
	}
	for(int i=0;i<M;i++){
		scanf("%d",&party[i][0]);
		for(int j=0;j<party[i][0];j++){
			scanf("%d",&party[i][j+1]);
		}
	}


	// 모든 파티를 확인해서 진실을 아는 사람이 있으면 나머지 파티원들도 진실을 아는사람으로 표시.
	// 이후, 뒷 인덱스의 파티에서 진실을 알아버렸지만 앞 인덱스 파티에서 그 점을 고려하지 못할 수 있기 때문에 다시 돌면서 확인
	// 값의 변환이 더이상 없다면 반복문x
	while(check==0){
		check=1;
		for(int i=0;i<M;i++){
			int all=0;
			for(int j=0;j<party[i][0];j++){
				if(all==-1&&tnum[party[i][j+1]]==0){
					check=0;
					tnum[party[i][j+1]]=1;
				}
				if(tnum[party[i][j+1]]==1&&all==0){
					j=-1;
					all=-1;
				}
			}
	}





	}
	for(int i=0;i<M;i++){
			for(int j=0;j<party[i][0];j++){
				if(tnum[party[i][j+1]]==1)break;
				if(j==party[i][0]-1)cnt++;
			}
	}
	printf("%d",cnt);



}
*/