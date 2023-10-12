// 별 찍기 - 13
// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
// 입력 - 3
// 출력
// *
// **
// ***
// **
// *


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<= 2*n-1; i++){
        int cnt = (n >= i) ? ((n > i)? i%n : n) : (n - i%n);
        for(int j = 0; j < cnt; j++)
            cout << '*';
        cout << '\n';
    }
}







// 답안 예시1
//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for(int i=1;i<2*n;i++){
//        for(int j=1;j<=(i>n?2*n-i:i);j++) printf("*");
//        printf("\n");
//    }
//}
