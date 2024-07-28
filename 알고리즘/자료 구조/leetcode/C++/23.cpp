// Merge K Sorted Lists
// k개의 오름차순으로 정렬된 연결 리스트가 주어진다. 모든 연결 리스트를 오름차순으로 하나의 연결 리스트로 병합하라.


// 내 답안1
// 연결 리스트들의 모든 원소를 하나의 우선순위 큐에 넣어 보관. ==> 자동으로 정렬됨.
// 우선순위 큐의 원소들을 하나씩 새 연결 리스트에 담는다.
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private: 
    priority_queue<int> pq;
public:
    void InsertInPQ(ListNode* a)
    {
        while(a != nullptr)
        {
            pq.push(-(a->val));
            a = a->next;
        }
    }
    ListNode* PQ2ListNode()
    {
        ListNode* head = new ListNode();
        ListNode* now = head;
        while(!pq.empty())
        {
            int num = -pq.top();
            pq.pop();

            ListNode* next = new ListNode(num);
            now->next = next;
            now = next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return  {};
        else if(lists.size() == 1) return lists[0];

        for(int i=0; i<lists.size(); i++)
        {
            InsertInPQ(lists[i]);
        }

        return PQ2ListNode()->next;
    }
};