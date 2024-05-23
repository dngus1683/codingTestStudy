// 내려가기
// Nx3 크기의 맵에 0~9의 숫자가 있다. 첫 번째 줄 원하는 곳부터 시작해서 맨 밑까지 계속 내려가며 해당 위치의 수를 모두 더한 값이 점수가 된다.
// 이동은, 바로 밑과 대각선 밑으로만 가능하다고 할 때, 받을 수 있는 최대 값을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 100'000

using namespace std;
int dj[3] = {-1, 0, 1};
int di = 1;
int MaxDp[2][3];
int MinDp[2][3];

inline int max(const int& a, const int& b)
{
    return (a>b ? a:b);
}

inline int min(const int& a, const int& b)
{
    return (a<b ? a:b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;

    cin >> N;

    cin >> MaxDp[0][0] >> MaxDp[0][1] >> MaxDp[0][2];
    MinDp[0][0] = MaxDp[0][0];
    MinDp[0][1] = MaxDp[0][1];
    MinDp[0][2] = MaxDp[0][2];
    for(int i=1; i<N; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            int mx = 0;
            int mn = 987654321;
            int score = 0;

            cin >> score;
            for(int k=0; k<3; ++k)
            {
                if(j+dj[k]<0 || j+dj[k]>2) continue;
                mx = max(mx, MaxDp[!di][j+dj[k]]);
                mn = min(mn, MinDp[!di][j+dj[k]]);
            }
            MaxDp[di][j] = score+mx;
            MinDp[di][j] = score+mn;
        }
        di = !di;
    }

    cout << max(MaxDp[!di][0], max(MaxDp[!di][1], MaxDp[!di][2]))
    << ' ' << min(MinDp[!di][0], min(MinDp[!di][1], MinDp[!di][2])) << '\n';
}
