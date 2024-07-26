// Remove Nth Node From End of List
// 하나의 연결 리스트가 주어질 때, 뒤에서부터 n번째의 node를 제거한 연결 리스트를 구하라.


// 내 답안1
// 먼저 연결 리스트를 모두 순회하여 전체 길이를 구한 후, 전체 길이에서 n을 빼면 지워야 하는 node의 앞에서부터의 순서를 구할 수 있다. 이를 활용하여 해당 node를 제거한다.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* now = head;
        int length = 0;
        int idx = 0;

        while(now != nullptr)
        {   
            now = now->next;
            length++;
        }

        idx = length - n - 1;
        now = head;

        if(idx < 0) return head->next;
        while(idx--)
        {
            now = now->next;
        }
        now->next = (now->next)->next;

        return head;
    }
};





// 답안 예시1
// two point를 사용한다. 먼저 첫 point를 앞에서부터 n개만큼 이동시킨다. 그러면 두 포인트 사이에는 n개만큼의 격차가 생긴다. 이대로 두 포인트를 동시에 끝까지 이동시키면, 두 번째 포인트가 가리키는 곳이 제거해야 하는 곳이다.
// 추가로, 지워야하는 node는 사용 후, delete를 통해 완벽히 제거한다면 메모리 사용량도 줄일 수 있다.
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;
    }
};
*/