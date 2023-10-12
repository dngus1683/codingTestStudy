// 사파리 월드
// 사파리 월드는 인터넷에 존재하는 나라들. 두 사파리 월드가 하나로 통합이 될 수 있는데 두 월드 간의 유명도 차이에 따라 통합 유무가 결정됨.
// 각 월드의 유명도가 주어질 때, 유명도 차이를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long a, b;
    unsigned long long result;
    
    cin >> a >> b;
    result = abs(a-b);
    cout << result << endl;
}
