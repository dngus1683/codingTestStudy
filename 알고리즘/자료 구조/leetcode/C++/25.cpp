// Reverse Nodes in k-Group
// 한 개의 연결 리스트가 주어진다. 인접한 k개의 노드 순서를 뒤집은 결과를 반환하라.


// 내 답안1
// stack 활용. k개 만큼의 node를 stack에 넣고, 다시 차례대로 빼면서 재연결.
#include <stack>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> stk;

        ListNode* front = new ListNode();
        ListNode* now = head;
        ListNode* answer = front;
        front->next = now;

        while(now != nullptr)
        {
            int cnt = 0;
            while(cnt < k)
            {
                if(now == nullptr)
                {
                    return answer->next;
                }
                stk.push(now);
                now = now->next;
                cnt++;
            }
            while(!stk.empty())
            {
                ListNode* node = stk.top();
                stk.pop();
                front->next = node;
                front = front->next;
            }
            front->next = now;
        }
        return answer->next;
    }
};






// 답안 예시1
// 반복문.
// 인접한 두 노드의 자리를 바꿈. 이를 k번 반복
/*
	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
*/





// 답안 예시2
// 답안 예시1의 재귀 표현
/*
	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
*/