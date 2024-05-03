// 단어의 개수
// 영어 대소문자와 공백으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.
// 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다


// 내 답안1
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int flag = 0;
    int cnt = 0;
    char s[1000001];
    cin.getline(s, 1000001);

    for(int i=0; i<strlen(s); i++){
        if(s[i] == ' '){
            flag = 0;
        }
        else{
            flag ++;
        }
        if(flag == 1){
            cnt ++;
        }
    }
    cout << cnt << '\n';
}





// 답안 예시1 - https://www.acmicpc.net/source/30116689
// #include <cstdio>
// #include <unistd.h>

// constexpr int SZ = 1 << 16;

// int main() {
//     char r[SZ], *p = r; read(0, r, SZ);    
//     int cnt = 1;
//     for (; *p == ' '; p++);
//     for (; ; p++) {
//         if (p == r + (SZ)) syscall(0, 0, p = r, SZ);
//         if (*p == '\n') { if (*--p == ' ') cnt--; break; }
//         if (*p == ' ') cnt++;
//     }
//     printf("%d\n", cnt);
// }