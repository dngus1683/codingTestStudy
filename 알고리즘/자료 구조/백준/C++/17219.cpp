// 비밀번호 찾기
// 사이트 주소와 그 주소의 로그인 비밀번호가 주어진다. 그 후, 사이트 주소만 주어질 때, 해당 주소에 해당하는 로그인 비밀번호를 출력하라.


// 내 답안1
#include <iostream>
#include <unordered_map>
#include <string>

#define MAX_N 100'001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;
    int M = 0;
    unordered_map<string, string> hmap;

    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        string s1 = "";
        string s2 = "";

        cin >> s1 >> s2;

        hmap[s1] = s2;
    }

    for(int i=0; i<M; i++)
    {
        string s1 = "";

        cin >> s1;
        cout << hmap[s1] << '\n';
    }
}
