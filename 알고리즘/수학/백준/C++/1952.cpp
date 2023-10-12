// 달팽이2
// (M, N)크기의 좌표가 있다. 좌상단부터 오른쪽으로 출발하여 벽이나 이미 지나온 곳을 마주하면 시계방향으로 튼다.
// 이때, 방향을 몇 번 바꾸는지 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    if(m>n){
        cout << (n/2)*4-1 + ((n%2) ? 2: 0 ) << '\n';
    }
    else{
        n = (n<m) ? n : m;
        cout << (n/2)*4 + ((n%2) ? 0:-2 ) << '\n';
    }
}





// 답안 예시1
// 더 간단한 수식이 있다.
//#include<stdio.h>
//int N, M;
//int main()
//{
//    scanf("%d %d", &N, &M);
//    if(N <= M) printf("%d", N*2-2);
//    else printf("%d", 2*M-1);
//}
