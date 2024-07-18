// Longest Common Prefix
// n개의 문자열이 주어질 때, 가장 긴 공통의 접두사를 구하라.


// 내 답안1
// 모든 문자열의 공통이므로 하나라도 달라서는 안된다. 때문에 아무 문자열을 기준으로 잡아도 되며, 본인은 vector의 첫 문자열을 기준으로 잡았다.
// 이후, 해당 문자열의 한 자씩 모든 문자열과 비교하였다.
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";

        for(int i=0; i<strs[0].length(); i++)
        {
            bool flag = 1;
            for(int j=1; j<strs.size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
            else s += strs[0][i];
        }
        if(strs.size() == 1) s = strs[0];
        return s;
    }
};





// 답안 예시1
// 문자열이 담긴 벡터를 오름차순으로 정렬한다. 문자열을 정렬하면, 알파벳 순으로 정렬된다. 때문에, 정렬된 벡터의 첫 원소와 마지막 원소만 비교하면 중간의 문자열들은 자동으로 계산에 포함된다.
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
*/