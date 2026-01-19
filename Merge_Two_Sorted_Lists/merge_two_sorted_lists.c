#include <stdlib.h>
#include <stdio.h>



struct ListNode {
    int val;
    struct ListNode* next;
    
};

// Destructive, Faster way to merge
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {



    struct ListNode dummy1;

    dummy1.next = NULL;

    struct ListNode* head1 = list1;
    struct ListNode* head2 = list2;
    struct ListNode* curr;
    curr = &dummy1;

    while (head1 && head2) {
        if (head1->val <= head2->val) {
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }

    }

    if (head1) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }

    return dummy1.next;
    
}

// Makes a new list Non-destructively
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode* head1 = list1;
    struct ListNode* head2 = list2;
    struct ListNode* prev = dummy;

    while (head1 != NULL && head2 != NULL) {

        if (head1->val <= head2->val) {
            struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = head1->val;
            temp->next = NULL;

            prev->next = temp;
            prev = prev->next;

            head1 = head1->next;
        } else {
            struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = head2->val;
            temp->next = NULL;

            prev->next = temp;
            prev = prev->next;

            head2 = head2->next;

        }


    }

    while (head1) {
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = head1->val;
        temp->next = NULL;

        prev->next = temp;
        prev = prev->next;

        head1 = head1->next;

    }

    while (head2) {
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = head2->val;
        temp->next = NULL;

        prev->next = temp;
        prev = prev->next;

        head2 = head2->next;        
    }

    


    return dummy->next;
    
}