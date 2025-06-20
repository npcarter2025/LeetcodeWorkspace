# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import math
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            return head

        root = head
        prev = head
        curr = head.next

        while curr:
            # declare new node
            # declare new value
            newNode = ListNode(math.gcd(prev.val, curr.val), curr)
            prev.next = newNode

            prev = curr
            curr = curr.next

        return root

        # I'm not sure why this is rated medium 