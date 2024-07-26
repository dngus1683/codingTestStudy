// Merge Two Sorted Lists
// 두 개의 오름차순으로 정렬된 연결리스트가 주어진다. 이를 병합하라.


// 내 답안1


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* answer = new ListNode;
        ListNode* now = answer;
        while(list1 != nullptr || list2 != nullptr)
        {
            if(list1 != nullptr && list2 != nullptr)
            {
                if(list1->val >= list2->val)
                {
                    ListNode* next = new ListNode(list2->val);
                    now->next = next;
                    list2 = list2->next;
                }
                else
                {
                    ListNode* next = new ListNode(list1->val);
                    now->next = next;
                    list1 = list1->next;
                }
            }
            else if(list1 == nullptr)
            {
                ListNode* next = new ListNode(list2->val);
                now->next = next;
                list2 = list2->next;
            }
            else if(list2 == nullptr)
            {
                ListNode* next = new ListNode(list1->val);
                now->next = next;
                list1 = list1->next;
            }
            now = now->next;
        }
        return answer->next;
    }
};





// 답안 예시1
// 내 답안1과 같은 방식. 차이점이 있는데, 둘 중 한 list를 끝까지 다 썼을 때, 남은 list에 대해서 while문에서 마저 해결하는 것이 아닌, 그냥 while 을 끝내고 남은 list를 정답 list의 뒤에 그대로 붙여넣는다.
/*

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next =list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy->next;
    }
};
*/