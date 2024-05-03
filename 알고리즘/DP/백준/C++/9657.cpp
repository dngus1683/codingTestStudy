// 돌 게임 3
// 탁자 위에 돌이 N개 있다. 상근이와 창영이가 한 번에 1 or 3 or 4개의 돌을 번갈아 가져갈 때, 마지막 돌을 가져가는 사람이 이기는 게임을 한다.
// 상근이가 게임을 먼저 시작할 때, 승자를 출력하라.


// 내 답안1
#include <iostream>
#include <cstring>

#define MAX_N 1001

using namespace std;

string d[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    d[1] = "SK";
    d[2] = "CY";
    d[3] = "SK";
    d[4] = "SK";
    for(int i=5; i<=N; i++)
    {
        if(d[i-1] == "CY" || d[i-3] == "CY" || d[i-4] == "CY")
            d[i] = "SK";
        else
            d[i] = "CY";
    }

    cout << d[N] << '\n';
}








// 답안 예시1 - https://www.acmicpc.net/source/47450432
// #include <stdio.h>

// int main(){
// 	int N = 0;
// 	scanf("%d",&N);
// 	if(N%7==0||N%7==2){
// 		printf("CY");
// 	}
// 	else{
// 		printf("SK");
// 	}
// }