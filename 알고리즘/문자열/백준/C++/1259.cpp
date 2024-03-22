// 팰린드롬수
// radar, sees 와 같은 단어들을 팰린드롬이라 하며, 이를 착안하여 거꾸로 읽어도 똑같은 수를 팰린드롬수라 한다. 여러 수가 입력될 때, 그 수가 팰린드롬수라면 yes, 그렇지 않으면 no를 출력하는 프로그램을 작성하라. 입력의 마지막은 0을 입력받는다.


// 내 답안1
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(1)
    {
        int flag = 1;
        char n[6];

        cin >> n;
        if(!strcmp(n, "0")) break;

        for(int i=0; i<strlen(n)/2; i++)
        {
            if(n[i] != n[strlen(n)-1-i]) {flag = 0; break;}
        }
        cout << (flag ? "yes" : "no") << '\n';
    }
}








// 답안 예시1
// 입력 숫자를 거꾸로 돌려서 기존과 같은지 확인
//#include <stdio.h>
//int main()
//{
//    while(1){
//        int n;
//        scanf("%d", &n);
//        if(!n) break;
//        int q=0, m=n;
//        while(n){
//            q=10*q+n%10;
//            n/=10;
//        }
//        if(q==m) printf("yes\n");
//        else printf("no\n");
//    }
//    return 0;
//}
