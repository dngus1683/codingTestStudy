// 2xn 타일링 2
// 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오. 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.


// 내 답안1
#include <iostream>

#define MAX_N 1001

using namespace std;

int d[MAX_N] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    d[1] = 1;
    d[2] = 3;
    d[3] = 5;

    for(int i=4; i<= n; i++)
    {
        d[i] = (d[2]%10007)*(d[i-2]%10007)+2*(d[i-3]%10007);
    }

    cout << d[n]%10007 << '\n';
}
