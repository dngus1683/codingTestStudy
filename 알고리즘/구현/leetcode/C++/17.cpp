// Letter Combinations of a Phone Number
// 옛 전화기 버튼에 있는 알파벳을 생각해보자. 2~9로 이루어진 번호가 주어질 때, 해당 버튼을 순서대로 눌렀을 때 만들 수 있는 모든 문자열을 구하라.


// 내 답안1
// backtracking을 통해 모든 조합을 구한다.
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<char>> telephone = {{},{},{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
public:
    void backtracking(int start, string& s, string& ans, vector<string>& answer)
    {
        if(start == s.length())
        {
            answer.push_back(ans);
            return;
        }
        for(char c : telephone[s[start] - '0'])
        {
            ans += c;
            backtracking(start+1, s, ans, answer);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string ans = "";
        backtracking(0, digits, ans, answer);
        if(digits.length() == 0) return {};
        return answer;
    }
};