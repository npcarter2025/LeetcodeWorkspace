# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        if not head.next:
            return head
        
        dummyodd = head
        
        odd = head
        even = head.next
        dummyeven = even
        while odd.next:
            if not odd.next.next:
                break
            odd.next = odd.next.next
            even.next = even.next.next

            odd = odd.next
            even = even.next
        print(odd)
        odd.next=dummyeven
        return dummyodd    