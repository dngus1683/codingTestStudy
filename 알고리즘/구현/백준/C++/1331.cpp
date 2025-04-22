// 나이트 투어
// 나이트 투어는 나이트가 체스판 위의 모든 칸을 정확히 한 번씩만 방문하고 마지막 칸에서 시작지점으로 다시 돌아올 수 있는 경로다.
// 6x6 체스판에 대한 투어 경로가 36개 주어질 때, 나이트 투어에 해당되는지 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool answer = true;
int di[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dj[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
unordered_set<string> hset;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string start = "";
    string pre = "";
    string now = "";
    
    cin >> pre;
    
    start = pre;
    
    for(int i=1; i<36; i++)
    {
        cin >> now;
        
        bool flag = false;
        for(int d=0; d<8; d++)
        {
            string tmp;
            
            tmp.push_back(pre[0]+dj[d]);
            tmp.push_back(pre[1]+di[d]);
            
            if(tmp == now && hset.find(tmp) == hset.end())
            {
                flag = true;
                hset.insert(tmp);
            }
        }
        
        if(!flag)
        {
            answer = false;
            break;
        }
        pre = now;
    }
    
    if(!answer)
    {
        cout << "Invalid" << '\n';
        return 0;
    }
    else
    {
        answer = false;
        for(int d=0; d<8; d++)
        {
            string tmp;
            
            tmp.push_back(pre[0]+dj[d]);
            tmp.push_back(pre[1]+di[d]);
            
            if(tmp == start)
            {
                answer = true;
                break;
            }
        }
        if(answer)
        {
            cout << "Valid" << '\n';
        }
        else
        {
            cout << "Invalid" << '\n';
        }
    }
}
