// 분수 합
// 분수가 두개 주어질 때, 두 분수의 합을 기약분수로 출력하라.


// 내 답안1
#include <iostream>

using namespace std;

int A1 = 0;
int B1 = 0;
int A2 = 0;
int B2 = 0;
int Aans = 0;
int Bans= 0;
int GCDans = 0;

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> A1 >> B1;
    cin >> A2 >> B2;
    
    Bans = B1*B2;
    Aans = A1*B2 + A2*B1;
    
    GCDans = gcd(Aans, Bans);
    
    cout << Aans / GCDans << ' ' << Bans / GCDans << '\n';
}
