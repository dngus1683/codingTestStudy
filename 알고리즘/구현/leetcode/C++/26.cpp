// Remove Duplicates from Sorted Array
// 하나의 오름차순으로 정렬된 배열이 주어진다. 이 배열에서 중복된 원소들을 제거하고 최종 배열의 길이를 반환하라.


// 내 답안1
// 중복의 첫 숫자를 num에 저장하고, 이 후, 해당 수와 같은 원소들은 erase() 매서드를 사용하여 nums에서 제거한다.
// Runtime: 49ms 너무 느림. memory: 21.4 MB
// #include <vector>

// using namespace std;

// class Solution 
// {
// public:
//     int removeDuplicates(vector<int>& nums) 
//     {
//         int answer = 1;
//         int num = nums[0];

//         for(int i=1; i<nums.size();)
//         {
//             if(num == nums[i])
//             {
//                 nums.erase(nums.begin()+i);
//                 continue;
//             }
//             else
//             {
//                 num = nums[i];
//                 answer += 1;
//                 i++;
//             } 
//         }

//         return answer;
//     }

// };



// 내 답안2
// erase()는 시간 복잡도가 O(n)이므로, 이를 사용하지 않고 문제를 해결하려 함.
// set은 중복을 허용하지 않기 때문에, nums vector에 있는 모든 원소를 set에 넣고, 다시 set의 원소들을 nums에 넣음
// runtime: 14ms but memory: 22.08 MB
// #include <vector>
// #include <set>
// 
// using namespace std;
// 
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> s;
//         int answer = 0;

//         for(int i=0; i<nums.size(); i++)
//         {
//             s.insert(nums[i]);
//         }

//         nums.clear();
//         for(int num : s)
//         {
//             nums.push_back(num);
//             answer++;
//         }
        

//         return answer;
//     }
// };


// 내 답안3
// set을 사용하면 메모리를 더 사용하게 됨. 또한, nums의 clear()또한 시간을 잡아먹기 때문에, 더욱 간단한 방식을 고안.
// two pointers를 사용하여, left와 right의 원소 값이 같다면 right가 계속 넘어가고, 원소값이 다를 때, left+1에 right 원소로 교체. 이를 반복
// runtime: 8 ms, memory: 21.4 MB
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;

        while(right < nums.size())
        {
            if(nums[left] == nums[right]) right++;
            else nums[++left] = nums[right++];
        }

        return left+1;
    }
};