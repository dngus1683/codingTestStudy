// 영화감독 숌
// 6이 연속으로 3번 이상 들어간 수를 종말의 수라 한다. 숫자 n이 주어질 떄, n번째로 큰 종말의 수를 출력하라. (ex. 가장 작은 종말의 수는 666이며 그 다음으로 1666 2666 ... ...)


// 내 답안1
// 666 앞의 숫자를 분석하여 6이 몇 개 있는지에 따라 횟수를 더하는 방식
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 666;

    cin >> n;
    for(int i=1; i<n; i++)
    {
        int tmp, num, cnt = 0;

        ans += 1000;
        num = ans;
        tmp = (ans-666)/1000;
        while(1)
        {
            if(tmp%10 != 6) break;
            cnt += 1;
            tmp /= 10;
        }
        if(cnt != 0)
        {
            cnt = pow(10, cnt);
            ans = (tmp*1000 + 666)*cnt;
            while((i+1)<n && cnt > 1)
            {
                ans += 1;
                i++;
                cnt--;
            }
            if((i+1)<n && cnt <= 1) ans = num;
        }
    }


    cout << ans << '\n';
}














// 답안 예시1 - https://www.acmicpc.net/source/44594313
//#include <stdio.h>
//int N, r = 666;
//int main() {
//    scanf("%d", &N);
//    for(int i = 0; i <= 3000; i++) {
//        for(int j = 10, k = 1; j <= 10000 ; j *= 10, k = k * 10 + 1) {
//            if(i % j != k * 6) {
//                N -= j / 10;
//                if(N <= 0) {
//                    r += (k / 10 * 3 + N);
//                    break;
//                }
//                break;
//            }
//        }
//        if(N <= 0) {
//            break;
//        }
//        r += 1000;
//
//    }
//    printf("%d", r);
//}





// 답안 예시2
//#include<stdio.h>
//int cal(int pos){
//    int cnt = 0;
//    for ( int i = 0 ; ; i++ ){
//        if ( i % 1000 == 666 ){
//            for ( int j = 0 ; j <= 999 ; j++ ){
//                cnt++;
//                if(cnt==pos){
//                    return i * 1000 + j ;
//                }
//            }
//        }
//        else if ( i % 100 == 66 ){
//            for ( int j = 0 ; j <= 99 ; j++ ){
//                cnt++;
//                if(cnt == pos ){
//                    return i * 1000 + 600 + j ;
//                }
//            }
//        }
//        else if ( i % 10 == 6) {
//            for ( int j = 0 ; j <= 9 ; j++ ){
//                cnt++;
//                if(cnt==pos){
//                    return i * 1000 + 660 + j ;
//                }
//            }
//        }
//        else {
//            cnt++;
//            if(cnt==pos){
//                return i * 1000 + 666 ;
//            }
//        }
//    }
//}
//main()
//{
//    int n ;
//    scanf("%d",&n);
//    printf("%d",cal(n));
//
//}
