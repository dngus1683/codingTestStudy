// 동물원
// 2 x N 크기의 동물원이 있다. 여기에 사자를 넣으려고 하는데 사자끼리 맞닿아 있으면 안된다. 사자를 배치하는 경우의 수를 구하여라


// 내 답안1
#include <iostream>

#define MAX_N 100001

using namespace std;

int d[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    d[0] = 1;
    d[1] = 3;
    for(int i=2; i<=N; i++)
    {
        d[i] = (2 * d[i-1] + d[i-2]) % 9901;
    }

    cout << d[N] << '\n';
}
