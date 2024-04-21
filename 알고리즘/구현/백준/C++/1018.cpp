// 체스판 다시 칠하기
// N x M 크기로 black & white 정보가 주어진다. 이를 8 x 8 크기로 잘라 흰색과 검은색이 반복되는 체스판으로 만들려고 한다. 이때, 색을 반대색으로 칠해야 하는 횟수의 최솟값을 구하라.


// 내 답안1
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M , ans = 65;

    cin >> N >> M;

    char board[N][M];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N-7; i++)
    {
        for(int j=0; j<M-7; j++)
        {
            int a = 0 , b = 0;
            for(int ii=i; ii<i+8; ii++)
            {
                for(int jj=j; jj<j+8; jj++)
                {
                    if((ii+jj)%2 == 0 && board[ii][jj] != 'W') a++;
                    if((ii+jj)%2 == 1 && board[ii][jj] != 'B') b++;
                }
            }
            ans = min(ans, min(a+b, 64-(a+b)));
        }
    }

    cout << ans << '\n';
}
