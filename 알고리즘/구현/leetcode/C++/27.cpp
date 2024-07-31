// Remove Element
// 정수 vector와 정수 val이 주어질 때, vector 내에서 val을 모두 제거하고, 남은 원소의 개수를 구하라.


// 내 답안1
// two pointer 사용.
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int answer = 0;
        int left = 0;
        int right = 1;

        if(nums.size() == 1)
        {
            if(nums[0] == val) return 0;
            else return 1;
        }
        while(left < nums.size() && right < nums.size())
        {
            if(nums[left] != val)
            {
                left++;
                right++;
                answer++;
            }
            else
            {
                if(nums[right] == val)
                {
                    right++;
                }
                else
                {
                    nums[left] = nums[right];
                    nums[right] = val;
                    left++;
                    right++;
                    answer++;
                }
            }
        }
        for(int i=left; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {
                answer ++;
            }
        }
        return answer;
    }
};






// 답안 예시1
// 더욱 간단한 two pointer
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {   
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
*/