// 검증수
// KOI 전자에서는 제조하는 컴퓨터마다 6자리의 고유번호를 매긴다. 첫 5자는 00000~99999 중 하나이며, 마지막 6번째 자리는, 앞의 5가지 숫자를 각 제곱하여 합한 수를 10으로 나눴을 때의 나머지이며 이 수를 검증수라 한다. 앞 5자의 고유번호가 주어질 떄, 검증수를 구하라.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num[5], ans = 0;

    for(int i=0; i<5; i++)
    {
        cin >> num[i];
        ans += num[i] * num[i];
    }
    cout << (ans%10) << '\n';
}
