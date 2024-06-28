// Longest Substring Without Repeating Characters
// 문자열 s가 주어질 때, 중복되는 문자가 존재하지 않는 부분 문자열 중 최대 길이를 구하라.


// 내 답안1
// 해시 테이블과 2개의 포인터를 활용.
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<char, bool> HashMap;
public:
    inline int max(const int& a, const int& b)
    {
        return (a>b?a:b);
    }
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int answer = 0;
        int cnt = 0;

        for(int end=0; end<s.length(); end++)
        {
            if(HashMap.find(s[end]) == HashMap.end()) 
            {
                HashMap[s[end]] = true;
                cnt++;
            }
            else
            {
                while(HashMap[s[end]])
                {
                    HashMap[s[start++]] = false;
                    cnt--;
                }
                HashMap[s[end]] = true;
                cnt++;
            }
            answer = max(answer, cnt);
        }
        return answer;
    }
};