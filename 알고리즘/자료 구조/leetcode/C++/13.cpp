// Roman to Integer
// 로마숫자가 주어질 때, 이를 10진수로 나타내라.


// 내 답안1
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
public:
    int romanToInt(string s) {
        int answer = 0;
        char before = ' ';
        for(auto c : s)
        {
            if(before == 'I' && (c == 'V' || c == 'X') ||
            before == 'X' && (c == 'L' || c == 'C') || 
            before == 'C' && (c == 'D' || c == 'M'))
            {
                answer -= roman[before] * 2;
            }
            answer += roman[c];
            before = c;
        }
        return answer;
    }
};



// 답안 예시1
// 로마표기법은 보통 큰 수부터 나열되는데, 만약 오름차순이 존재한다면, 그 구간은 IV = 4, IX = 9와 같이 뒷 숫자에 앞 숫자를 뺴는 특이 케이스이므로 해당 상황에만 뺀다.
/*
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
};
*/