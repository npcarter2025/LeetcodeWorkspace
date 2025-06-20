# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        
        # MEMORY EFFICIENT APPROACH
        
        if head.next is None:
            return 1   
        comps = 0
        prev = head

        oldComp = False

        while prev:
            if oldComp:   
                if nums.count(prev.val) == 0:
                    oldComp = False
                prev = prev.next

            else: # not oldComp:
                if nums.count(prev.val):
                    comps += 1
                    oldComp = True
                prev = prev.next


        return comps


        # TIME COMPLEXITY FAST APPROACH
        # only difference is that we copy nums to a set, to speed up searching

        numbers = set(nums)
        if head.next is None:
            return 1   
        comps = 0
        prev = head

        oldComp = False

        while prev:
            if oldComp:   
                if prev.val not in numbers:
                    oldComp = False
                prev = prev.next

            else: # not oldComp:
                if prev.val in numbers:
                    comps += 1
                    oldComp = True
                prev = prev.next
        return comps
