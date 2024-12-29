// 택시 동승
/*
밤늦게 귀가할 때 안전을 위해 항상 택시를 이용하던 무지는 최근 야근이 잦아져 택시를 더 많이 이용하게 되어 택시비를 아낄 수 있는 방법을 고민하고 있습니다. 
"무지"는 자신이 택시를 이용할 때 동료인 어피치 역시 자신과 비슷한 방향으로 가는 택시를 종종 이용하는 것을 알게 되었습니다. 
"무지"는 "어피치"와 귀가 방향이 비슷하여 택시 합승을 적절히 이용하면 택시요금을 얼마나 아낄 수 있을 지 계산해 보고 "어피치"에게 합승을 제안해 보려고 합니다.
*/



#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF 987654321

using namespace std;

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i=1; i<=n; i++)
    {
        for(int j =1; j<=n; j++)
        {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for(vector<int> vec : fares)
    {
        dist[vec[0]][vec[1]] = vec[2];
        dist[vec[1]][vec[0]] = vec[2];
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int k=1; k<=n; k++)
    {
        if(dist[s][k] >= INF || dist[k][a] >= INF || dist[k][b] >= INF) continue;
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
    }
    if(dist[s][a] < INF && dist[s][b] < INF) 
        answer = min(answer, dist[s][a] + dist[s][b]);
    
    return answer;
}