// 스위치 켜고 끄기
// N개의 스위치와 현재 각각의 상태가 0,1로 주어진다.
// 남자가 번호를 뽑았을 때, 해당 번호이 배수 스위치의 상태를,
// 여자가 번호를 뽑았을 때, 해당 번호를 기준으로 좌우 대칭인 모든 스위치 상태를 반대로 바꾼다.
// 스위치의 마지막 상태를 구하라.


// 내 답안1
#include <iostream>
#include <vector>


#define MAX_N 101
#define MAX_M 101

using namespace std;

int N = 0;
int M = 0;
vector<bool> state(MAX_N, false);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        int num = 0;
        
        cin >> num;
        if(num) state[i] = true;
        else state[i] = false;
    }
    cin >> M;
    
    for(int i=0; i<M; i++)
    {
        int a = 0;
        int b = 0;
        
        cin >> a >> b;
    
        if(a == 1)
        {
            for(int j=b; j<=N; j += b)
            {
                state[j] = !state[j];
            }
        }
        else if(a == 2)
        {
            for(int l=b, r = b; l > 0 && r <=N; l--, r++)
            {
                if(state[l] == state[r])
                {
                    state[l] = !state[l];
                    state[r] = state[l];
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        cout << state[i] << ' ';
        if(i % 20 == 0) cout << '\n';
    }
    
}


