#include <stdlib.h>

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            
            if (head == NULL) {
                return NULL;
            }
            if (head->next == NULL) {
                return head;
            }
    
            ListNode* first;
            ListNode* prev; 
            ListNode* new_head;
    
    
            first = head;
            prev = NULL;
            
            new_head = head->next;
    
            while (first != NULL && first->next != NULL) {
                ListNode* second = first->next;
                ListNode* next_pair = second->next;
    
                //swap pointers
                second->next = first;
                first->next = next_pair;
    
                if (prev != NULL) {
                    prev->next = second;
                }
                // process for next cycle
                prev = first;
                first = next_pair;
    
    
            }
    
            return new_head;
    
    
    
        }
    };