// Longest Palindromic Substring
// 가장 긴 팰린드롬을 출력하라.


// 내 답안1
#include <string>

using namespace std;

class Solution {
private:
    bool dp[1001][1001] { 0, };

public:
    void cache(string& s, int N)
    {
        for(int i=0; i<N; i++)
        {
            dp[i][i] = true;
            if(i<N-1 && s[i] == s[i+1]) dp[i][i+1] = true;

        }
        for(int k=3; k <= N; k++)
        {
            for(int i=0; i<=N-k; i++)
            {
                if(dp[i+1][i+k-2] && s[i] == s[i+k-1])
                {
                    dp[i][i+k-1] = true;
                }
            }
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        cache(s, n);

        for(int k=n; k >= 1; k--)
        {
            for(int i=0; i < n-k+1; i++)
            {
                if(dp[i][i+k-1])
                    return s.substr(i, k);
            }
        }
        return 0;
    }
};