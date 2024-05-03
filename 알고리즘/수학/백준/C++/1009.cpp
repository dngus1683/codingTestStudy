// 분산처리
// 컴퓨터가 10대가 있다. a^b개의 데이터를 10대에 나눠 처리한다.
// 1~10번 까지 순차적으로 데이터를 처리할 때, 마지막 데이터를 처리하는 컴퓨터를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int start=0; start < T; start++){
        int arr[4];
        int a, b, tmp, isZero = 0;

        cin >> a >> b;
        tmp = a;
        for(int i=0; i<4; i++){
            arr[i] = a % 10;
            a = (a%10)*tmp;
            if(arr[i]==0) isZero = 1;
        }
        cout << ((isZero) ? 10 : arr[(b%4==0) ? 3 : b%4-1]) << '\n';
    }
}





// 답안 예시1 - https://www.acmicpc.net/source/31295770
// 내 답안1과 풀이 방식은 똑같지만 세세한 구현법이 다르다.
// 굳이 arr[4]를 4원소 모두 저장하면서 메모리를 사용할 핖요가 없다.
//#include <cstdio>
//int n, a, b, t;
//int main() {
//    scanf("%d", &n);
//    while (n--) {
//        scanf("%d %d", &a, &b);
//        b %= 4;
//        b = b == 0 ? 4 : b;
//        t = a % 10;
//        while (--b) t = t * a % 10;
//        printf("%d\n", t == 0 ? 10 : t);
//    }
