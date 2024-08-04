// Find the Index of the First Occurrence in a String
// A, B 문자열이 주어진다. A에 B가 포함되면 가장 첫 index값을, 포함되지 않으면 -1을 출력하라.


// 내 답안1
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int answer = -1;

        if(haystack.length() < needle.length()) return answer;
        for(int i=0; i<=(haystack.length() - needle.length()); i++)
        {
            {
                if(haystack.substr(i, needle.length()) == needle)
                return i;
            }
        }
        return answer;
    }
};