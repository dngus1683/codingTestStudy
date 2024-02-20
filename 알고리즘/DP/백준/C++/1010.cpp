// 다리 놓기
// 서쪽의 사이트 N개에서 동쪽의 사이트 M개에 다리를 놓으려 한다. (N <= M)
// 다리는 교차되면 안된다고 할 때, 다리를 놓는 경우의 수를 구하라.


// 내 답안1
//#include <iostream>
//
//#define MAX_M 30
//
//using namespace std;
//
//long long int f[MAX_M];
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int T;
//
//    cin >> T;
//
//    f[0] = 1;
//    f[1] = 1;
//    for(int i=2; i<MAX_M; i++)
//    {
//        f[i] = f[i-1]*i;
//    }
//
//    for(int TestCase=0; TestCase<T; TestCase++)
//    {
//        int N, M;
//        long long int ans;
//
//        cin >> N >> M;
//        ans = f[M]/(f[N]*f[M-N]);
//        cout << ans << '\n';
//    }
//
//}



//// 내 답안2
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int combination(int n, int r)
//{
//    if(n == r || r == 0)
//        return 1;
//    else
//        return combination(n - 1, r - 1) + combination(n - 1, r);
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int T;
//
//    cin >> T;
//
//    for(int TestCase=0; TestCase<T; TestCase++)
//    {
//        int N, M, ans;
//
//        cin >> N >> M;
//        ans = combination(M, N);
//        cout << ans << '\n';
//    }
//}


// 내 답안3
// combination 계산을 약분한 형태로 간단한 for문으로 구현.
#include <iostream>

#define MAX_M 30

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;
    for(int TestCase=0; TestCase<T; TestCase++)
    {
        int N, M;
        long long int ans = 1;

        cin >> N >> M;
        for(int i=1; i<=N; i++)
        {
            ans *= M;
            ans /= i;
            M--;
        }
        cout << ans << '\n';
    }

}
