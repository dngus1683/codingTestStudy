// Two Sum
// 정수 배열과 target 값이 주어질 때, 서로 다른 두 원소의 합이 target이 되는 두 원소의 인덱스 값을 구하라.


// 내 답안1
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
        return answer;
    }
};



// 답안 예시 - https://leetcode.com/problems/two-sum/solutions/2990807/solution-c-java-python-both-brute-force-optimized-code
// 각 원소가 target이 되기 위해, 더해져야 하는 값을 hash table value로 저장하여, for문을 한 번만 사용하여 해결.
/*
#include <unordered_map>
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Declare an unordered map to store the numbers and their indices
        unordered_map<int, int> mp;
       
        // Loop through the array
        for(int i = 0; i < nums.size(); i++){
            // Check if the complement of the current number exists in the map
            if(mp.find(target - nums[i]) == mp.end())
                // If not, add the current number and its index to the map
                mp[nums[i]] = i;
            else
                // If yes, return the indices of the current number and its complement
                return {mp[target - nums[i]], i};
        }
 
        // If no pair is found, return {-1, -1} as a default value
        return {-1, -1};
    }
};

};
*/