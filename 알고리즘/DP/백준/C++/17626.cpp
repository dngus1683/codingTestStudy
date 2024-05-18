// Four Squares
// 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현가능하다고 라그랑주가 증명하였다. 그리고 그 제곱수의 조합은 여러 개일 수 있다.
// 자연수 n이 주어질 때, 그러한 제곱수 조합의 최소 원소 수를 구하라.


// 내 답안1
// dp
#include <iostream>

#define MAX_N 50'001

using namespace std;

static inline int min(const int& a, const int& b)
{
    return (a < b ? a : b);
}

int dp[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;
    int sn = 2;

    cin >> N;

    dp[1] = 1;
    for(int i=2; i<=N; i++)
    {
        dp[i] = (dp[i] == 0 ? MAX_N : dp[i]);
        if(i == sn*sn)
        {
            dp[i] = 1;
            sn += 1;
            continue;
        }
        for(int j=1; j<sn; j++)
        {
            dp[i] = min(dp[i], dp[j*j]+dp[i-j*j]);
        }
    }

    cout << dp[N] << '\n';
}










// 답안 예시 - https://www.acmicpc.net/source/30147767
// 완전 탐색 알고리즘.
//#include<stdio.h>
//
//int n, a, b, c, i, j, k;
//int main(void)
//{
//    scanf("%d", &n);
//    for(i=1;i*i<=n;i++) if(i*i==n)
//    {
//        printf("1");
//        return 0; //정확히 제곱수인 경우.
//    }
//    for(i=1;i*i<=n;i++) for(j=1;j<=i;j++) if( (i*i+j*j)==n)
//    {
//        printf("2");
//        return 0; //2개인 경우
//    }
//    for(i=1;i*i<=n;i++) for(j=1;j<=i;j++) for(k=1;k<=j;k++) if( (i*i+j*j+k*k)==n)
//    {
//        printf("3");
//        return 0;
//    }
//    printf("4");
//    return 0;
//}

