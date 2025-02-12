// 영어 읽기
// 단어의 첫 글자와 끝 글자를 제외한 중간의 글자의 위치를 뒤바뀌더라도 읽는데는 지장이 없다고 한다.
// 사전에 존재하는 단어들이 주어지고, 문장이 주어질 때, 해당 문장이 해석될 수 있는 경우의 수를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#define MAX_N 10'001
#define MAX_M 10'001

using namespace std;

int N = 0;
int M = 0;
unordered_map<string, int> dict;

string norm(string s)
{
    if (s.length() <= 2)
    {
        return s;
    }
    sort(s.begin() + 1, s.end() - 1);
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s = "";

        cin >> s;

        dict[norm(s)]++;
    }

    cin >> M;
    cin.ignore(); // 버퍼 비우기
    for (int i = 0; i < M; i++) {
        string line;
        getline(cin, line); // 한 줄 입력
        string word;
        int answer = 1;
        for (char ch : line) {
            if (ch == ' ') {
                answer *= dict[norm(word)]; // 정규화된 단어 검색
                word.clear();
            }
            else {
                word += ch;
            }
        }
        if (!word.empty()) {
            answer *= dict[norm(word)]; // 마지막 단어 처리
        }
        cout << answer << '\n';
    }
}