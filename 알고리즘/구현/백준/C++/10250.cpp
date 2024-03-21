// ACM 호텔
// 호텔의 크기(W x H)가 주어질 때, N번째 손님이 배정받을 방을 구하라.
// (호실은 층수+호수(ex. 12층 4호 = 1204호)로 주어지고, 방배정은 입구에서 가장 가까운 곳으로 배정된다. 입구는 101호 옆 엘레베이터 쪽에 있다. 예를 들어 102호보다 1401호가 먼저 배정된다. 102호는 2칸 떨어져있지만 1401호는 엘레베이터로 인해 1번만 가면 되기 때문이다. 만약 거리가 같다면 낮은 층부터 채워진다.)


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;
    for(int TestCase=0; TestCase<T; TestCase++)
    {
        int H, W, N, ans;

        cin >> H >> W >> N;

        ans = (N%H == 0 ? H : N%H)*100 + (N%H == 0 ? N/H : N/H+1);

        cout << ans << '\n';
    }
}







// 답안 예시1
//#import<ios>
//main(){int a,x,y;scanf("%d",&a);while(a--){scanf("%d%d%d",&x,&y,&y);y--;printf("%d%02d\n",y%x+1,y/x+1);}}
