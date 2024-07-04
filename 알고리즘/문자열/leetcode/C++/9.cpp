// Palindrome Number
// 정수가 주어질 때, 팰린드롬인지 확인하라.


// 내 답안1
// 문자열로 변환 후 두 포인터를 사용하여 양 끝단부터 비교
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool answer = 1;
        string s = to_string(x);

        int start = 0;
        int end = s.length()-1;

        while(start < end)
        {
            if(s[start++] != s[end--]) 
            {
                answer = false;
                break;
            }
        }
        return answer;
    }
};






// 답안 예시1
// 음수라면 바로 false 출력.
// 양수라면, 해당 정수의 역수를 계산한 후, 역수와 원래의 정수가 같은지 확인
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long int reverse = 0;
        int tmp = x;
        
        while (tmp != 0) {
            int digit = tmp % 10;
            tmp /= 10;
            
            reverse = (reverse * 10) + digit;
        }
        
        if (reverse > INT_MAX) return false;
        
        return x == reverse;
    }
};
*/
