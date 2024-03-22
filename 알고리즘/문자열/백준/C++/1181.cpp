// 단어 정렬
// 알파벳 소문자로 이루어진 단어 N개가 주어질 떄, 길이가 짧은 것부터, 길이가 같다면 사전 순으로, 중복되는 단어가 있다면 제거하여 정렬하는 프로그램을 작성하라.


// 내 답안1
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_N 20001
#define MAX_L 51
using namespace std;

vector<string> word[MAX_L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        string a;

        cin >> a;
        word[a.length()].push_back(a);
    }

    for(int i=1; i<MAX_L; i++)
    {
        if(word[i].empty()) continue;
        sort(word[i].begin(), word[i].end());
        for(int j=0; j<word[i].size(); j++)
        {
            if(j != 0 && word[i][j] == word[i][j-1]) continue;
            cout << word[i][j] << '\n';
        }
    }
}









// 답안 예시1
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//struct Word {
//    char size;
//    char str[51];
//};
//
//bool compare(const Word& w1, const Word& w2) {
//    if (w1.size == w2.size) for (int i = 0; i < w1.size; ++i) {
//        if (w1.str[i] == w2.str[i]) continue;
//        return w1.str[i] < w2.str[i];
//    }
//    return w1.size < w2.size;
//}
//
//Word word[20001];
//
//int main() {
//    ios::ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n; ++i) {
//        cin >> word[i].str;
//        word[i].size = strlen(word[i].str);
//    }
//
//    sort(word, word + n, compare);
//
//    cout << word[0].str << '\n';
//    for (int i = 1; i < n; ++i) if (strcmp(word[i].str, word[i - 1].str)) cout << word[i].str << '\n';
//
//
//    return 0;
//}
