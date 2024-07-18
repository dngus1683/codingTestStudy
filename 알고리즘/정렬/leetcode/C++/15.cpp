// 3Sum
// n개의 정수가 주어질 때, 3개의 원소의 합이 0이 되는 집합을 모두 구하라. 이때, 중복은 허용하지 않는다.


// 내 답안1
// 모든 수를 hashtable에 개수를 세어 저장. 그리고 정수의 종류를 파악하기 위해 따로 집합에 저장.
// 집합은 자동으로 오름차순이기 때문에, 작은 수부터 3개의 합 계산. 해당하는 수가 hashtable에 존재한다면 정답 벡터에 추가. 
// 이 답안은 답안 예시1에 비해 현저히 느리다.
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
    set<int> NumSet;
    unordered_map<int, int> HashTable;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        for(auto n : nums)
        {
            if(HashTable.find(n) == HashTable.end()) HashTable[n] = 1;
            else HashTable[n]++;
            NumSet.insert(n);
        }
        set<int>::iterator iter = NumSet.begin();

        while(iter != NumSet.end())
        {
            HashTable[*iter]--;
            for(set<int>::iterator i = iter; i != NumSet.end(); i++ )
            {
                if(HashTable[*i] <= 0) continue;
                HashTable[*i]--;
                if(HashTable[0-*iter-*i] > 0 && ( *i <= (0-*iter-*i)))
                {
                    answer.push_back({*iter, *i, (0-*iter-*i)});
                }
                HashTable[*i]++;
            }
            HashTable[*iter]++;
            iter++;
        }

        return answer;
    }
};









// 답안 예시1
// 정수 배열을 우선 정렬한다. 
// 이후, 작은 수부터 시작하여, (0-원소)가 합인 나머지 두 정수를 찾기 위해 두개의 포인터를 사용한다. 이때, 중복은 허용하지 않으므로, 이전과 같은 수가 있다면 계속해서 넘어간다. 정렬을 해두었으므로 연속으로 넘길 수 있다.
/*
vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet = {num[i], num[front], num[back]};
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
*/