// 집합
// 집합을 구현하라. 양의 정수 N이 주어질 때, N개의 집합 명령어를 수행하라.


// 내 답안1
// set 컨테이너 사용, 입력은 sstream 사용 : 시간 초과
/*
#include <iostream>
#include <string>
#include <sstream>
#include <set>

#define MAX_M 3000001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> all({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
    set<int> st;
    int m;

    cin >> m;
    cin.ignore();
    while (m--)
    {
        int num;
        string s, s1;
        stringstream ss;

        getline(cin, s);

        if (s.find(' ') != string::npos)
        {
            ss << s;
            ss >> s1 >> num;
        }
        else s1 = s;

        if (s1 == "add")
        {
            st.insert(num);
        }
        else if (s1 == "remove")
        {
            st.erase(st.find(num));
        }
        else if (s1 == "check")
        {
            cout << st.count(num) << '\n';
        }
        else if (s1 == "toggle")
        {
            if (st.count(num)) st.erase(st.find(num));
            else st.insert(num);
        }
        else if (s1 == "all")
        {
            st.swap(all);
        }
        else if (s1 == "empty")
        {
            st.clear();
        }
    }
}
*/



// 내 답안2
// 입력에서 시간이 많이 소모되었으므로 sstream을 사용하지 않고 입력을 간단하게 받음.
// set 컨테이너를 사용하지 않고 간단한 배열을 계수정렬처럼 구현.
#include <iostream>
#include <string>

#define MAX_M 3000001

using namespace std;

int set[21] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;

    cin >> m;
    cin.ignore();
    while (m--)
    {
        int num;
        string s1;

        cin >> s1;
        if(s1 != "all" && s1 != "empty" ) cin >> num;

        if (s1 == "add")
        {
            set[num] = 1;
        }
        else if (s1 == "remove")
        {
            set[num] = 0;
        }
        else if (s1 == "check")
        {
            cout << set[num] << '\n';
        }
        else if (s1 == "toggle")
        {
            if (set[num]) set[num] = 0;
            else set[num] = 1;
        }
        else if (s1 == "all")
        {
            for (int i = 1; i < 21; i++)
                set[i] = 1;
        }
        else if (s1 == "empty")
        {
            for (int i = 1; i < 21; i++)
                set[i] = 0;
        }
    }
}