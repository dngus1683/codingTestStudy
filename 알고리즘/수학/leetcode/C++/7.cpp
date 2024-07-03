// Reverse Integer
// 32bit 정수 x가 주어질 때, x의 순서를 바꿔 출력하라. 이때, 32bit 이상의 수는 다룰 수 없는 환경이라 가정한다.


// 내 답안1
#define MAX_INT 0b1111111111111111111111111111111

class Solution {
public:
    int reverse(int x) {
        int answer = 0;
        bool sign = (x>=0);

        if(x == 0) return 0;

        while(x != 0)
        {
            if(sign && answer > ((MAX_INT-1) -(x%10))/10) return 0;
            else if(!sign && answer < (-MAX_INT - (x%10))/10) return 0;
            answer = answer*10 + (x%10);
            x /= 10;
        }

        return answer;
    }
};