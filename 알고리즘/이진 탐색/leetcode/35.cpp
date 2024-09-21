// Search Insert Position
// 오름차순으로 정렬된 배열과 목표 숫자가 주어질 때, 해당 숫자가 위치한 인덱스, 만약 배열에 존재하지 않다면 위치할만한 곳의 인덱스를 구하라.


// 내 답안1
// 일반적으로 앞에서부터 탐색
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int answer = 0;
        for(; answer<nums.size(); answer++)
        {
            if(nums[answer] >= target)
            {
                break;
            }
        }

        return answer;
    }
};
