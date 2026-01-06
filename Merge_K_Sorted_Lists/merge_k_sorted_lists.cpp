#include <vector>
#include <queue>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
    
            if (lists.empty() || (lists.size()==1 && lists[0] == NULL)) return NULL;
    
            std::priority_queue<int> pq;
    
            for (int i = 0; i < lists.size(); i++) {
    
                ListNode* temp;
                temp = lists[i];
                while (temp != NULL) {
                    pq.push(-(temp->val));
                    temp = temp->next;
                }
    
            }
    
            if (pq.size() == 0) return NULL;
    
            ListNode* head = new ListNode(-pq.top());
            pq.pop();
            ListNode* prev = head;
            while (!pq.empty()) {
                ListNode* new_node = new ListNode(-pq.top());
                pq.pop();
                prev->next = new_node;
                prev = new_node;
    
            }
    
            return head;
    
        }
    };