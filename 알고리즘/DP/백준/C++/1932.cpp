// 정수 삼각형
// 층수가 N층인 정수로 이루어진 삼각형이 주어진다. 맨 꼭대기에서 맨 바닥까지 내려오면서 선택했던 정수들의 합의 최댓값을 구하라.


// 내 답안1
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 501
#define INF 987654321

using namespace std;

int N = 0;
vector<int> triangle[MAX_N];
int dp[MAX_N][MAX_N];
inline int max(const int& a, const int& b)
{
    return (a>b?a:b);
}

int BiggestValue(int level, int idx)
{
    if(level == N)
    {
        dp[level][idx] = triangle[level][idx];
        return dp[level][idx];
    }
    else
    {
        int left = 0;
        int right = 0;

        left = (dp[level+1][idx] == INF ? BiggestValue(level+1, idx) : dp[level+1][idx]);
        right = (dp[level+1][idx+1] == INF ? BiggestValue(level+1, idx+1) : dp[level+1][idx+1]);

        dp[level][idx] = triangle[level][idx]+max(left, right);
        return dp[level][idx];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            int a = 0;
            cin >> a;
            triangle[i].push_back(a);
        }
    }
    fill(&dp[0][0], &dp[MAX_N-1][MAX_N], INF);

    cout << BiggestValue(1, 0) << '\n';
}











// 답안 예시1 - https://www.acmicpc.net/source/38259566
// 입력을 받으면서 바로 dp배열을 채워감.
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <iostream>
//#include <memory.h>
//#include <malloc.h>
//#include <stdbool.h>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//
//#define FOR(N) for(int i = 0; i < N; i++)
//#define FOR2(N) for(int j = 0; j < N; j++)
//#define FORi(k, N) for(int i = k; i < N; i++)
//#define FOR2j(k, N) for(int j = k; j < N; j++)
//#define INF 987654321
//#define ll long long int
//using namespace std;
//
//
//char in[11000000], * op = in;
//int readN();
//void wrtN(int n);
//int POW(int, int);
//
//
//
//int main(void) {
//    cin.tie(NULL); cout.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    fread(in, 1, sizeof(in), stdin);
//
//    int n; n = readN();
//    int* dp = new int[n];
//    int* last = new int[n];
//    /*
//    dp[i]에 각 줄을 입력받는다.
//    last[n-1]에는 이전줄의 각 정수까지 최선의 경로로 왔을 떄 최대값이 각각 저장되어 있다.
//    dp[0]은 last[0] 만을 이어받을 수 있고, dp[n] 은 last[n-1] 만을 이어받을 수 있다.
//    1~n-2 사이의 i에 대하여 dp[i]값은 last[i-1], last[i] 값 중 max값이다.
//
//    이 과정을 0~n-1줄에 반복하낟.
//    */
//
//    last[0] = readN();
//    dp[0] = last[0];
//    FORi(2,n+1) {
//            FOR2(i) {
//                dp[j] = readN();
//                if (j== 0) dp[j] += last[0];
//                else if (j == i - 1) dp[j] += last[j - 1];
//                else dp[j] += max(last[j - 1], last[j]);
//            }
//            FOR2(i) {
//                last[j] = dp[j];
//            }
//
//    }
//    int max = -INF;
//    FOR(n) {
//        if (dp[i] > max)
//            max = dp[i];
//    }
//    cout << max;
//}
//int POW(int r, int p) {
//    int    total = 1;
//    if (p == 0)
//        return 1;
//
//    FOR(p) {
//        total *= r;
//    }
//    return total;
//}
//int readN() {
//    static char* p = in;
//    int r, b = 1;
//    while (*p < 45) p++;
//    if (*p == 45) b = -1, p++;
//    for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
//    return r * b;
//}
//void wrtN(int n) {
//    char temp[10], * t = temp;
//    if (n < 0) *op++ = '-', n = -n;
//    do *t++ = n % 10 | 48; while (n /= 10);
//    do *op++ = *--t; while (t != temp);
//    *op++ = ' ';
//}
//
