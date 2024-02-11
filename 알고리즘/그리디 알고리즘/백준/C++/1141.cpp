// 접두사
// 접두사X 집합이란 집합의 어떤 한 단어가, 다른 단어의 접두어가 되지 않는 집합이다. 예를 들어, {hello}, {hello, goodbye, giant, hi}, 비어있는 집합은 모두 접두사X 집합이다. 하지만, {hello, hell}, {giant, gig, g}는 접두사X 집합이 아니다.
// 단어 N개로 이루어진 집합이 주어질 때, 접두사X 집합인 부분집합의 최대 크기를 출력하시오.


// 내 답안1
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool comp(string &s1, string &s2)
{
    return s1.size() > s2.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<string> sv;
    set<string> ans;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        sv.push_back(a);
    }

    sort(sv.begin(), sv.end(), comp);
    ans.insert(sv[0]);

    for(int i=1; i<sv.size(); i++)
    {
        int flag = 0;
        for(string j: ans)
        {
            if(j.substr(0, sv[i].size()) == sv[i]) flag = 1;
        }
        if(!flag) ans.insert(sv[i]);
    }

    cout << ans.size() << '\n';
}
