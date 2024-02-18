// 피보나치 함수
// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n‐1) + fibonacci(n‐2);
//     }
// }
// 위 함수는 피보나치 수를 구하는 함수다.
// 해당 함수는 0과 1을 여러 번 리턴하게 되는데, n이 주어졌을 때 0과 1을 리턴하는 수를 구하라.
// (예를 들어 n = 3일 때, 0은 1, 1은 2번 리턴 된다.)


// 내 답안1
#include <iostream>

#define MAX_N 41

using namespace std;

int d[MAX_N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;
    for(int TestCase=0; TestCase<T; TestCase++)
    {
        int N;

        cin >> N;

        fill(&d[0][0], &d[MAX_N-1][2], 0);
        d[0][0] = 1;
        d[1][1] = 1;
        for(int i=2; i<=N; i++)
        {
            d[i][0] = d[i-1][0] + d[i-2][0];
            d[i][1] = d[i-1][1] + d[i-2][1];
        }

        cout << d[N][0] << ' ' << d[N][1] << '\n';
    }
}














// 답안 예시
//#include<cstdio>
//int main(){
//    int f[60]={1,0},T,a;
//    for(a=0;a<50;a++)f[a+2]=f[a+1]+f[a];
//    scanf("%d",&T);
//    while(T--){
//    scanf("%d",&a);
//    printf("%d %d\n",f[a],f[a+1]);
//    }
//}
