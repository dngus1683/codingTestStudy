// 쉬운 계단 수
// 45656이란 수를 보자.
// 이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
// N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.
// 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.


// 내 답안1
// 계속 풀이를 실행했더니 오답이 떴다.
// 이유를 알아보니, n=65부터 overflow가 발생하였다.
// 때문에 1,000,000,000을 나눠 몫을 구하는 것을 마지막 결과에만 적용하는 것이 아닌 매 계산마다 적용하는 것으로 변경하였더니 정답처리가 되었다.
#include <iostream>

#define MAX_N 101

using namespace std;

long long int d[MAX_N][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long int N, sum = 0;
    long long int di = 1000000000;

    cin >> N;

    fill(d[1], d[1]+10, 1);
    d[1][0] = 0;
    for(int i=2; i<=N; i++)
    {
        d[i][0] = d[i-1][1]%di;
        d[i][9] = d[i-1][8]%di;
        for(int j=1; j<=8; j++)
        {
            d[i][j] = d[i-1][j-1]%di + d[i-1][j+1]%di;
        }
    }

    for(int i=0; i<10; i++)
        sum = (sum + d[N][i])%di;
    cout << sum << '\n';
}