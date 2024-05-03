// 별 찍기 - 12
// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
// 입력 - 3
// 출력
//   *
//  **
// ***
//  **
//   *


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;

    for(int i = 1; i <= 2*(a-1)+1 ; i++){
        int cnt = i%a;
        if(cnt == 0) cnt = a;
        else if((i/a)%2 == 1) cnt = a-cnt;
        for(int k=0; k<a-cnt; k ++)
            cout << ' ';
        for(int j=0; j<cnt ;j++)
            cout << '*';
        cout << '\n';
    }
}






// 답안 예시1 - https://www.acmicpc.net/source/41586008
//#include<stdio.h>
//int a,b,c;
//int main(){
//    scanf("%d",&a);
//    for(int i=1;i<=2*a-1;i++){
//        for(int q=1;q<=a;q++){
//            printf("%c",a>i?(q<=a-i?' ':'*'):q<=i-a?' ':'*');
//        }
//        printf("\n");
//    }
//}

