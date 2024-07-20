// 3Sum Closet
// n개의 정수와 target 정수가 주어질 때, 3개의 정수의 합이 target에 가장 가까운 수를 구하라.


// 내 답안1
// 2 pointer를 사용.
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dist = 987654321;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(dist > abs(target-sum))
                {
                    dist = abs(target - sum);
                    ans = sum;
                }
                if(sum < target)
                {
                    while((l < (nums.size()-1)) && nums[l] == nums[l+1]) l++;
                    l++;
                }
                else if(sum > target)
                {
                    while( (r > 0) && nums[r] == nums[r-1]) r--;
                    r--;
                }
                else
                {
                    return target;
                }
            }

            while(i<(nums.size()-1) && nums[i]==nums[i+1]) i++;

        }
        return ans;
    }
};