// 돌 게임
// 탁자 위에 돌이 N개 있다. 상근이와 창영이가 한 번에 1 or 3개의 돌을 번갈아 가져갈 때, 마지막 돌을 가져가는 사람이 이기는 게임을 한다.
// 상근이가 게임을 먼저 시작할 때, 승자를 출력하라.


// 내 답안1
#include <iostream>

#define MAX_N 1001

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    if((N/3)%2==1)
    {
        if(N%3==0)
            cout << "SK" << '\n';
        else if(N%3==1)
            cout << "CY" << '\n';
        else
            cout << "SK" << '\n';
    }
    else
    {
        if(N%3==0)
            cout << "CY" << '\n';
        else if(N%3==1)
            cout << "SK" << '\n';
        else
            cout << "CY" << '\n';
    }

}






// 답안 예시1
// 단순히 n이 홀수인지 짝수인지 확인만 했으면 됐음.
// 아래는 비트 연산자를 활용해서 해당 내용을 구현함.
//#import<ios>
//main(int n){scanf("%d",&n);puts(n&1?"SK":"CY");}

// 답안 예시2
//#include<cstdio>
//main(){int n;scanf("%d",&n);puts(n%2?"SK":"CY");}
