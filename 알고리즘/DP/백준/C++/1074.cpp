// Z
// 크기가 2^N × 2^N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다. 2^2 x 2^2배열이라면 2x2배열을 Z로 방문한 후, 그 단위만큼 또 Z 순으로 방문한다. N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하라.


// 내 답안1
// DP - bottom-up 방식
// 각 위치의 합은 (r,0), (0,c)값의 합이란 것을 알아냄.
// (r,0)의 값과 (0,c)의 값은, N의 크기에 따라 N-1의 값만큼 더해지는 것을 확인. (ex. (0,6) = 20은 16값에 (0,6-4)=(0,2)=4를 더한 값)
#include <iostream>
#include <cmath>

using namespace std;

int ArrR[0x10000] = {0,};
int ArrC[0X10000] = {0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, r, c;

    cin >> N >> r >> c;

    ArrC[1] = 1; ArrC[2] = 4; ArrC[3] = 5;
    ArrR[1] = 2; ArrR[2] = 8; ArrR[3] = 10;
    for(int i=3; i<=N; i++)
    {
        for(int j=pow(2,i-1); j<pow(2, i); j++)
        {
            if(j%2)
            {
                ArrC[j] = ArrC[j-1] + 1;
                ArrR[j] = ArrR[j-1] + 2;
            }
            else
            {
                ArrC[j] = (int)pow(2,(i-1)*2) + ArrC[j-(int)pow(2,i-1)];
                ArrR[j] = (int)pow(2,(i-1)*2+1) + ArrR[j-(int)pow(2,i-1)];
            }
        }
    }
    cout << ArrR[r]+ArrC[c]<< '\n';

}
















// 답안 예시1
// 네 사분면 계산을 큰 것부터 작은 것으로 들어가며 재귀적 계산을 함.
// 출처: https://wtg-study.tistory.com/70
//#include <stdio.h>
//#include <math.h>
//
//int func(int N, int r, int c) {
//    if (N < 1) return 0;
//
//    int mid = (int)pow(2, N - 1);
//
//    if (r < mid && c < mid) {
//        //printf("1사분면\n");
//        return func(N - 1, r, c);
//    }
//    else if (r < mid && c >= mid) {
//        //printf("2사분면\n");
//        return mid * mid + func(N - 1, r, c - mid);
//    }
//    else if (r >= mid && c < mid) {
//        //printf("3사분면\n");
//        return mid * mid * 2 + func(N - 1, r - mid, c);
//    }
//    else {
//        //printf("4사분면\n");
//        return mid * mid * 3 + func(N - 1, r - mid, c - mid);
//    }
//}
//
//
//int main() {
//    int N, r, c;
//    scanf("%d %d %d", &N, &r, &c);
//
//    int result = func(N, r, c);
//    printf("%d\n", result);
//
//    return 0;
//}
