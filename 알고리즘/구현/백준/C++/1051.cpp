// 숫자 정사각형
// N×M크기의 직사각형이 있다. 각 칸에는 한 자리 숫자가 적혀 있다. 이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오. 이때, 정사각형은 행 또는 열에 평행해야 한다.


// 내 답안1
#include <iostream>

#define MAX_N 51

using namespace std;

char graph[MAX_N][MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;
    int M = 0;
    int length = 0;

    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        cin >> graph[i];
    }
    length = (N>M?N:M)-1;
    for(int l=length; l>=0; l--)
    {
        for(int i=0; i<N-l; i++)
        {
            for(int j=0; j<M-l; j++)
            {
                if(graph[i][j] == graph[i+l][j] && graph[i][j] == graph[i][j+l] && graph[i][j] == graph[i+l][j+l])
                {
                    cout << (l+1)*(l+1) << '\n';
                    return 0;
                }
            }
        }
    }
}

