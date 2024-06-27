// Add Two Numbers
// 자연수가 역순으로 연결되어 있는 연결 리스트 2개가 주어질 때, 두 자연수를 더한 값의 연결 리스트를 구하라.


// 내 답안1
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* cal(ListNode* l1, ListNode* l2, int upper)
    {
        if(l1 == nullptr && l2 == nullptr && upper == 0) return nullptr;
        else if(l1 == nullptr && l2 == nullptr && upper == 1) return new ListNode(upper);
        ListNode* node = new ListNode;
        if(l1 != nullptr && l2 != nullptr)
            node->val = ((l1->val + l2->val)+upper);
        else if(l1 == nullptr && l2 != nullptr)
            node->val = (l2->val+upper);
        else if(l1 != nullptr && l2 == nullptr )
            node->val = (l1->val+upper);    
        
        if(node->val > 9)
        {

            node->val -= 10;
            upper = 1;
        }
        else upper = 0;

        if(l1 != nullptr && l2 != nullptr)
        {
            node->next = cal(l1->next, l2->next, upper);
        }
        else if(l1 == nullptr && l2 != nullptr)
        {
            node->next = cal(nullptr, l2->next, upper);
        }
        if(l1 != nullptr && l2 == nullptr)
        {
            node->next = cal(l1->next, nullptr, upper);
        }

        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode;
        answer = cal(l1, l2, 0);
        return answer;
    }
};








// 답안 예시1 - https://leetcode.com/problems/add-two-numbers/editorial
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;  // Freeing the memory allocated for dummyHead
        return result;
    }
};
*/