// Valid parentheses
// 괄호들로만 이루어진 문자열이 주어진다. 해당 문자열이 완전히 깔끔하게 괄호가 완성되었는지 확인하라.


// 내 답안1
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> couple = {{')', '('}, {'}', '{'}, {']', '['}};

        if(s.length() % 2 == 1) return false;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] =='[' || s[i] == '(' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.empty() || stk.top() != couple[s[i]])
                {
                    return false;   
                }
                else
                {
                    stk.pop();
                }
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};