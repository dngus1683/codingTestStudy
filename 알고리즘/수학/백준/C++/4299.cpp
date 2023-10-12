// AFC 웜블던
// 두 축구팀의 점수를 확인하고 싶은데 두 팀의 골 합과 차만 제공될 때, 두 팀의 점수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int sum, sub , a, b;
    
    cin >> sum >> sub;
    a = (sum + sub)/2;
    b = sum - a;
    
    if((sum + sub) % 2 == 1 || (sum < sub)){
        cout << -1 << endl;
    }
    else if(a >= b){
        cout << a << ' ' << b << endl;
    }
    else{
        cout << b << ' ' << a <<endl;
    }
    
}
