// 시그마
// 두 정수 A와 B가 주어졌을 때, 두 정수 사이에 있는 수의 합을 구하는 프로그램을 작성하시오. 사이에 있는 수들은 A와 B도 포함한다.

// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, tmp;
    cin >> a >> b;

    if(a>b){
        tmp = b;
        b = a;
        a = tmp;
    }

    cout << (b*(b+1))/2 - (a*(a+1))/2 + a<< '\n';
}




// 답안 예시1 - https://www.acmicpc.net/source/52900362
//#include <stdio.h>
//int main(){
//    long long int a,b;
//    scanf("%lld%lld",&a,&b);
//    printf("%lld",(a+b)*(b>a?b-a+1:a-b+1)/2);
//}

