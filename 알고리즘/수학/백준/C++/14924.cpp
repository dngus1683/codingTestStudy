// 폰 노이만과 파리
// 총 길이가 D 마일인 기차철로가 있다. 양쪽에서 시속 S로 기차가 마주보며 올 때, 그 사이를 시속 T로 왔다갔다하는 파리가 있을 때,
// 해당 파리는 총 몇 마일 움직일 수 있는지 구하라.
// 이때, D는 2*S의 배수


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S, T, D;
    cin >> S >> T >> D ;

    cout << (D / (2*S))*T << endl;
}
