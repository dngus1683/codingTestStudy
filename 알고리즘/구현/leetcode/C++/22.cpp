// Generate Parenthese
// 자연수 n이 주어질 때, 소괄호 쌍 n개가 되는 문자열을 모두 구하라. 
// ex) n = 3 일 때) ["((()))","(()())", "(())()", "()(())", "()()()"]


// 내 답안1
// backtracking
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int cLeft, int cRight, vector<string>& pick, string s)
    {
        if(cLeft == 0 && cRight == 0)
        {
            pick.push_back(s);
            return;
        }
        else
        {
            if(cLeft > 0)
            {
                s += '(';
                dfs(cLeft-1, cRight, pick, s);
                s.pop_back();
            }
            if(cLeft < cRight)
            {
                s += ')';
                dfs(cLeft, cRight-1, pick, s);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        dfs(n-1, n, answer, "(");
        return answer;
    }
};