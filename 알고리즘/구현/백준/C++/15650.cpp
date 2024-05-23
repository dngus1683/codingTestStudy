// N과 M (2)
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
// + 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
// + 고른 수열은 오름차순이어야 한다.


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 9

using namespace std;

int N = 0;
int M = 0;

void combination(int start, vector<int>& pick, int count)
{
    if(count == M)
    {
        for(int i=0; i<M-1; ++i)
        {
            cout << pick[i] << ' ';
        }
        cout << pick[M-1] << '\n';
        return ;
    }
    else
    {
        for(int i=start+1; i<=N; ++i)
        {
            pick.push_back(i);
            combination(i, pick, count+1);
            pick.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    vector<int> comb;
    combination(0, comb, 0);

}
