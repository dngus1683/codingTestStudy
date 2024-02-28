// 1, 2, 3 더하기
// 정수 N이 주어졌을 때, 순서 고려하여 1,2,3의 합으로 표현하는 경우의 수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 11

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for(int TestCase=0; TestCase<T; TestCase++)
    {
        int n;

        cin >> n;

        int d[n+1];

        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        for(int i=4; i<=n; i++)
        {
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }

        cout << d[n] << '\n';

    }


}