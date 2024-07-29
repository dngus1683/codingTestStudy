// Swap Nodes in Pairs
// 한 개의 연결 리스트가 주어진다. 인접한 두 노드를 바꾼 결과를 반환하라.


// 내 답안1
// node안의 val값만 교환
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* now = head;
        ListNode* pair = now ? now->next : nullptr;
        while(now != nullptr && pair != nullptr)
        {
            int tmp = now->val;
            now->val = pair->val;
            pair->val = tmp;

            now = pair->next;
            pair = now ? now->next : nullptr;
        }
        return head;
    }
};







// 답안 예시1 - https://leetcode.com/problems/swap-nodes-in-pairs/solutions/3528791/python-java-c-simple-solution-easy-to-understand/
// node를 통째로 교환
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            curr->next = second;
            first->next = second->next;
            second->next = first;
            curr = curr->next->next;
        }
        
        return dummy->next;
    }
};
*/