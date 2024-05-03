// 최소공배수
// 두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int testCase = 0; testCase < T; testCase++){
        int a, b, mab;
        cin >> a >> b;
        for(int i=min(a,b); i>0; i--){
            if(a%i == 0 && b%i == 0){
                mab = i;
                break;
            }
        }
        cout << a*b/mab << '\n';
    }
}




// 답안 예시1 - https://www.acmicpc.net/source/35767919
// 유클리드 호제법
// f(a, b) = gcd(a, b)라 하자.

// 이 때 a mod b = 0 이라면, f(a, b) = b임이 자명.

// 이 때 a mod b이 0이 아닌 경우, f(a, b) = f(b, a mod b)가 성립한다.

// => a,b에 대해 a%b가 0이 될 때까지 b % (a%b)의 재귀 계산을 이어나간다. 최종 b값이 gcd값.

// 최대 공약수 구하는 부분 주목
//#include <stdio.h>
//
//int main(){
//    int a,b,c,d,n;
//    scanf("%d",&n);
//    while(n--){
//        scanf("%d %d",&a,&b);
//        d=a*b;
//        while(b!=0)
//        {
//            c=a%b;
//            a=b;
//            b=c;
//
//        }
//        printf("%d\n",d/a);}
//}
