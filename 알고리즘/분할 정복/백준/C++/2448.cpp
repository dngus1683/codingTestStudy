// 별 찍기 - 11
// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
// 예제 입력
// 24
// 예제 출력
/*
                       *
                      * *
                     *****
                    *     *
                   * *   * *
                  ***** *****
                 *           *
                * *         * *
               *****       *****
              *     *     *     *
             * *   * *   * *   * *
            ***** ***** ***** *****
           *                       *
          * *                     * *
         *****                   *****
        *     *                 *     *
       * *   * *               * *   * *
      ***** *****             ***** *****
     *           *           *           *
    * *         * *         * *         * *
   *****       *****       *****       *****
  *     *     *     *     *     *     *     *- 백준(c++: 1987)
 * *   * *   * *   * *   * *   * *   * *   * *
***** ***** ***** ***** ***** ***** ***** *****
*/


// 내 답안1
#include <iostream>
#include <algorithm>

#define Pow2MAX 1024
using namespace std;

char star[3*Pow2MAX+1][6*Pow2MAX+1];

void DrawNTriangle(int n, int CenterI, int CenterJ)
{
    if (n == 1)
    {
        star[CenterI-2][CenterJ] = '*';
        star[CenterI - 1][CenterJ - 1] = '*';
        star[CenterI - 1][CenterJ + 1] = '*';

        for(int j = CenterJ-2; j < CenterJ+3; j++)
            star[CenterI][j] ='*';
    }
    else
    {
        DrawNTriangle(n / 2, CenterI - (n / 2) * 3, CenterJ);
        DrawNTriangle(n / 2, CenterI, CenterJ - ((float)n / 4) * 6);
        DrawNTriangle(n / 2, CenterI, CenterJ + ((float)n / 4) * 6);
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;

    cin >> N;

    fill(&star[0][0], &star[3 * Pow2MAX][6 * Pow2MAX + 1], ' ');

    DrawNTriangle(N / 3, N, (((float)N / 6) * 6));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 6 * (N / 3); j++)
            cout << star[i][j];
        if(i==N) break;
        cout << '\n';
    }
}