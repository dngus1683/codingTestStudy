// Integer to Roman
// 1~3999 내의 정수가 주어질 때, 이를 로마표기법으로 나타내라.


// 내 답안1
#include <string>
#include <map>

using namespace std;

class Solution {
private: 
    map<int, char> Roman;
public:
    void RomanInit()
    {
        Roman[1] = 'I';
        Roman[5] = 'V';
        Roman[10] = 'X';
        Roman[50] = 'L';
        Roman[100] = 'C';
        Roman[500] = 'D';
        Roman[1000] = 'M';
    } 
    string intToRoman(int num) {
        RomanInit();
        string answer = "";
        int ten = 10000;
        while(num != 0)
        {
            ten /= 10;
            int tmp = num / ten;
            if(tmp == 0)
            {
                continue;
            }
            else if(tmp < 4)
            {
                for(int i=0; i<tmp; i++)
                    answer += Roman[ten];
            }
            else if(tmp == 4)
            {
                answer += Roman[ten];
                answer += Roman[ten*5]; 
            }
            else if(tmp >= 5 && tmp < 9)
            {
                answer += Roman[ten*5];
                for(int i=0; i<tmp-5; i++)
                    answer += Roman[ten];
            }
            else if (tmp == 9)
            {
                answer += Roman[ten];
                answer += Roman[ten*10];
            }
            num = num - tmp*ten;
        }

        return answer;
    }
};







// 답안 예시1
// 주어진 조건을 활용하여 최대한 간단하게 구현.
/*
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
*/


// 답안 예시2
// 4, 9인 경우도 hash에 저장. 입력으로 주어진 num을 하나씩 빼면서 계산.
/*
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result;
        for (const auto& pair : romanMap) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        return result;
    }
};
*/