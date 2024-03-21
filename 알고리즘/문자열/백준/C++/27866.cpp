// 문자와 문자열
// 단어 S와 정수 i가 주어졌을 때, S의 i번째 글자를 출력하라.


// 내 답안1
#include <iostream>

#define MAX_S 1001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char S[MAX_S];
    int i;

    cin >> S;
    cin >> i;
    cout << S[i-1] << '\n';

}
