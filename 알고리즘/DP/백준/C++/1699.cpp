// 제곱수의 합
// 모든 수는 (11 = 3^2 + 1^2 + 1^2 + 1^2) 와 같이 어떤 수의 제곱들의 합으로 나타낼 수 있다.
// 입력이 주어질 때, 그 수를 위와 같이 표현했을 때 가장 적은 항의 개수를 구하라.


// 내 답안1
#include <iostream>
#include <cmath>
#include <vector>

#define INF 987654321
#define MAX_N 100001

using namespace std;

int d[MAX_N];
vector<int> sv;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    d[1] = 1;
    sv.push_back(1);
    for(int i=2;i<=n; i++)
    {
        if(sqrt(i) - (int)sqrt(i) == 0)
        {
            d[i] = 1;
            sv.push_back(i);
        }
        else
        {
            int m = INF;
            for(int j=sv.size() - 1; j>=0; j--)
            {
                m = min(m, d[sv[j]] + d[i-sv[j]]);
            }
            d[i] = m;
        }
    }

    cout << d[n] << '\n';
}







// 답안 예시1 - https://www.acmicpc.net/source/32062230
//#include <stdio.h>
//
//
//int det(int n, int i){
//    if(i==0) return n==0;
//
//    int max = 1;
//    while(max*max*i<n) max++;
//
//    for(; n-max*max>=0;  max++)
//        if(det(n-max*max, i-1)) return 1;
//    return 0;
//}
//
//int main(){
//    int n;
//    scanf("%d", &n);
//
//    for(int i = 1; i<=n; i++){
//        if(det(n,i)){
//            printf("%d", i);
//            return 0;
//        }
//    }
//
//
//
//    return 0;
//}