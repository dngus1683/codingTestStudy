// 음계
// 1~8까지 음계가 주아진다. 1부터 8까지 오름차순이면 ascending, 내림차순이면 descending, 나머지는 mixed를 출력하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int note, ans, as = 1, ds = 1;

    cin >> ans;
    for(int i=1; i<8; i++)
    {
        cin >> note;
        if(note != ans+1) as = 0;
        if(note != ans-1) ds = 0;
        ans = note;
    }

    if(as) cout << "ascending" << '\n';
    else if(ds) cout << "descending" << '\n';
    else cout << "mixed" << '\n';
}




// 답안 예시1
//#include <stdio.h>
//int main(){
//    int a,b,x=0;
//    scanf("%d",&a);
//    for(int i=0; i<7; i++){
//        scanf("%d",&b);
//        if(a<b)x++;
//        else x--;
//        a=b;
//    }
//    printf(x==7?"ascending":x==-7?"descending":"mixed");
//}
