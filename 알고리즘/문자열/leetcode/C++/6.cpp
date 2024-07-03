// Zigzag Conversion
// 문자열 S와 정수 N이 주어질 때, N 깊이로 문자열 S를 지그제그로 나열한다. 이때, 가장 위에 나열된 문자부터 순차적으로 읽었을 때 문자열을 출력하라.
// 예시) s = "PAYPALISHIRING", numRows = 4
//       P     I    N
//       A   L S  I G
//       Y A   H R
//       P     I
//       => PINALSIGYAHRPI


// 내 답안1
#include <string>

using namespace std;

class Solution {
private:
    string zigzag[1000];
public:
    string convert(string s, int numRows) {
        int idx = 0;
        int direction = 1;
        string answer = "";

        if(numRows == 1)
            return s;
        for(int i=0; i<s.length(); i++)
        {
            zigzag[idx] += s[i];
            if(idx == 0)
            {
                direction = 1;
            }
            else if(idx == numRows-1)
            {
                direction = -1;
            }
            idx += direction;
        }
        for(int i=0; i<numRows; i++)
        {
            answer += zigzag[i];
        }
        return answer;
    }
};