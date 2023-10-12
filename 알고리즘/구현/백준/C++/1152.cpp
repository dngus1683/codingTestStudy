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





// 답안 예시1
//#include <iostream>
//#include <string>
//#include <string.h>
//#include <unistd.h>
//
//using namespace std;
//
//int main() {
//    int cnt = 0;
//    char str[1000000] = {0,};
//
//    read(0, str, 1000000);
//
//    for(int i = 0; i < 1000000; i++) {
//        if(str[i] == ' ' && (i != 0)) {
//            cnt++;
//        }
//        else if(str[i] == '\0' || str[i] == '\n') {
//            if(str[i-1] == ' ')
//                cnt--;
//            break;
//        }
//    }
//    cnt++;
//    printf("%d\n", cnt);
//
//    return 0;
//}ㅁ
