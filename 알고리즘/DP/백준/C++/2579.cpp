// 계단 오르기
// 각 계단 별로 점수가 있는데, 끝까지 올랐을 때 밟았던 계단의 점수의 합이 가장 높은 경우를 구하라. 이때, 계단은 한칸, 두칸만 이동할 수 있고 연속으로 세 계단을 오를 수 없다.


// 내 답안1
#include <iostream>
#include <algorithm>

#define MAX_N 301

using namespace std;

int step[MAX_N];
int d[MAX_N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    step[0] = 0;
    for(int i=1; i<=N; i++)
    {
        cin >> step[i];
    }

    d[0][0] = 0;
    d[0][1] = 0;
    d[1][0] = step[1];
    d[1][1] = step[1];

    for(int i=2; i<=N; i++)
    {
        d[i][0] = step[i] + max(d[i-2][0], d[i-2][1]);
        d[i][1] = step[i] + d[i-1][0];
    }

    cout << max(d[N][0], d[N][1]) << '\n';
}








// 답안 예시1
//#include<cstdio>
//#define Max(a,b)(a>b?a:b)
//
//int N;
//int F[305];
//int DP[305];
//
//int main()
//{
//    scanf("%d", &N);
//
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", &F[i]);
//
//        DP[i] = Max(DP[i - 2] + F[i], DP[i - 3] + F[i - 1] + F[i]);
//    }
//
//    printf("%d", DP[N]);
//    return 0;
//}
