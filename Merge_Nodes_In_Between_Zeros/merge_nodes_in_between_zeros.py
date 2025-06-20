# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
  
        root = head

        prev = head
        curr = head.next

        while curr.next:
            if curr.val == 0:
                # adjust prev node to curr
                prev = curr
                # inc curr node
                curr = curr.next

            else: #curr.val != 0:
                prev.val += curr.val
                prev.next = curr.next
                curr = curr.next
        prev.next = None
        return root


        # need to absorb values,
        # meanwhile change pointers each time, in order to delete nodes.