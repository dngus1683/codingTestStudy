// String to integer(atoi)
// 공백과 부호, 알파벳, 숫자가 포함된 문자열 s가 주어질 때, 처음 나오는 연결된 수를 출력하라. 
// 이때, 숫자가 나오기 전 공백은 무시하고, 수와 관련된 문자가 나오면 바로 끊는다.


// 내 답안1
#include <string>

#define MAX_INT 0b1111111111111111111111111111111

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int answer = 0;
        bool StartFlag = false;
        bool sign = true;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ' && !StartFlag) continue;
            if(s[i] == '-' && !StartFlag)
            {
                sign = false;
                StartFlag = true;
                continue;
            }
            if(s[i] == '+' && !StartFlag)
            {
                sign = true;
                StartFlag = true;
                continue;
            }
            if(s[i]-'0' < 0 || s[i]-'0' > 9) break;
            
            StartFlag = true;

            if(sign && (answer > (MAX_INT-1 - (s[i]-'0'))/10) )
            {
                return MAX_INT;
            }
            if(!sign && (answer > (MAX_INT - (s[i]-'0'))/10) )
            {
                return -MAX_INT-1;
            }
            answer = answer*10 + (s[i]-'0');
        }
        if(!sign) answer = -answer;
        return answer;
        
    }
};