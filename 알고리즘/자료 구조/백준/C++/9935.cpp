// 문자열 폭발
// 문자열과 폭탄 문자열이 주어진다. 해당 문자열에 폭탄 문자열이 포함되어 있다면 해당 부분을 지운다. 지운 뒤의 문자열에도 폭탄 문자열에 해당하는 부분이 존재한다면 해당 행동을 반복한다. 문자열 폭발 후 남은 문자열을 구하라.


// 내 답안1
// stack을 두 개 사용. 1개는 문자열 S를 문자 하나씩 넣으면서 검사. 나머지 하나는 폭탄 계산을 하다가 폭탄 문자열을 다시 세어야 할 때, 이전 폭탄 문자열의 검사 상태를 저장하기 위한 역할(마치 운영체제 시분할 느낌).
// 9번 틀림 - 큰 알고리즘은 틀리지 않음. 구현 중 디테일하지 않았음.
// 첫 번째 반례
/*
 C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4
 C4C

 ans: 44444444444444444444444444444444444444444444444444C4
 wrong: C444444444444444444444444444444444444444444444444444

 => 처음 접근은 문자열 S에 대해, 뒤에서부터 출발하여 뒤의 문자열 폭탄들부터 터뜨렸다. 이로 인해 위와 같이 터뜨릴 대상이 애매하게 남는 상황이면 정답은 뒤에서 남지만 오답의 경우 앞에서 남아 틀리게 된다.
 */
// 두 번째 반례
/*
 abacabcc
 abc

 ans: abacc
 wrong: ab

 => 문자열 스택에 문자를 하나씩 넣을 때, 해당 문자가 폭탄 계산에 해당되지 않는, 코드 상으로는 BoomIdx가 0이 아닌데 해당 차례의 문자가 처리대상이 아닌 경우, 기존에는 BoomIdx만 0으로 초기화 해줬지만, 이렇게 한다면 이후로 폭탄이 발견되고, 다음 BoomIdx를 지정해줘야 하는 상황에서, Boom의 스택에 Idx값이 여전히 남아있기 때문에 이상한 값으로 시작을 하게 되어 오답을 출력한다. 이를 해결하기 위해서는 폭탄의 조건에서 벗어났을 때, Boom의 스택에 있는 모든 Idx 값은 의미가 없어지므로 모두 지운다.
 */
#include <iostream>
#include <stack>
#include <cstring>

#define MAX_L 1'000'010
#define MAX_B 40

using namespace std;

char s1[MAX_L];
char a[MAX_L];
char boom[MAX_B];
stack<char> ans;
stack<int> SIdx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s1;
    cin >> boom;

    int cnt = 0;
    int N = 0;
    int SLength = strlen(s1);
    int BoomLength = strlen(boom);
    int BoomIdx = 0;

    while(N < SLength)
    {
        ans.push(s1[N++]);
        if(ans.top() == boom[BoomIdx])
        {
            if(BoomIdx == (BoomLength-1))
            {
                for(int i=0; i<BoomLength; i++)
                    ans.pop();
                if(!SIdx.empty())
                {
                    BoomIdx = SIdx.top();
                    SIdx.pop();
                }
                else
                {
                    BoomIdx = 0;
                }
            }
            else
            {
                BoomIdx++;
            }
        }
        else if(ans.top() == boom[0])
        {
            SIdx.push(BoomIdx);
            cnt ++;
            BoomIdx = 1;
        }
        else if(BoomIdx != 0)
        {
            BoomIdx = 0;
            while(!SIdx.empty())
                SIdx.pop();
        }
    }
    if(ans.empty())
        cout << "FRULA" << '\n';
    else
    {
        int i = ans.size()-1;
        while(!ans.empty())
        {
            a[i--] = ans.top();
            ans.pop();
        }
        cout << a << '\n';
    }

}





// 답안 예시1 - https://www.acmicpc.net/source/24870813
// stack을 사용하지 않음
// 문자열 S를 window slicing 하며 검사.
/*
 #define _CRT_SECURE_NO_WARNINGS

 #include <iostream>
 #include <utility>
 #include <algorithm>
 #include <string.h>
 #include <math.h>

 using namespace std;

 char str[1000001];
 char delim[37];

 int rIndex = 0;
 int mIndex = 0;

 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     cin >> str;
     cin >> delim;

     int len_str = strlen(str);
     int len_delim = strlen(delim);
     int matches;

     while(mIndex < len_str) {
         str[rIndex] = str[mIndex];

         matches = 0;
         for (int i = 0; i < len_delim; i++) {
             if (rIndex - i < 0) break;

             if (str[rIndex - i] != delim[len_delim - i - 1]) break;

             matches++;
         }

         if (matches == len_delim) {
             rIndex -= len_delim;
         }

         rIndex++;
         mIndex++;
     }
     str[rIndex] = '\0';

     cout << (str[0] ? str : "FRULA");
 }
 */
