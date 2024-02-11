// 문자열
// 문자열 A, B가 주어진다. A의 길이는 B보다 작거나 같다. A의 앞과 뒤에 아무 문자를 추가하여 B와의 차이를 가장 최소로 했을 때 차이 수를 구하라.

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int mn = 987654321;
    string a, b;

    cin >> a >> b;

    for(int i=0; i<=b.size()-a.size(); i++)
    {
        int cnt = 0;
        for(int j=i; j<a.size()+i; j++)
        {
            if(a[j-i] != b[j]) cnt++;
        }
        mn = min(mn, cnt);
    }

    cout << mn << '\n';
}