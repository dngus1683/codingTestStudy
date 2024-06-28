// 별 찍기 - 4
// 첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제
/*
*****
 ****
  ***
   **
    *
*/


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;

    cin >> N; 
    for (int i = N; i >= 1; i--)
    {
        for (int j = 0; j < N - i; j++)
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << '*';
        if (i > 1) cout << endl;
    }
}