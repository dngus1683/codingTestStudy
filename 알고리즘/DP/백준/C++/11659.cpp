// 구간 합 구하기 4
// 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <cstring>

#define MAX_NM 100001

using namespace std;

int li[MAX_NM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, m;

    cin >> N >> m;

    for(int i=0; i<N; i++)
    {
        cin >> li[i];
    }

    int ans[m], d[N+1];

    memset(&ans, 0, sizeof(int));
    memset(&d, 0, sizeof(int));

    d[1] = li[0];

    for(int i=1; i<N; i++)
        d[i+1] = d[i] + li[i];
    for(int i=0; i<m; i++)
    {
        int a, b;

        cin >> a >> b;
        ans[i] = d[b] - d[a-1];
    }
    for(int i=0; i<m; i++)
        cout << ans[i] << '\n';
}
