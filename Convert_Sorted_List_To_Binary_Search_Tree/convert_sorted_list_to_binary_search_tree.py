# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if not head:
            return None
        flattened = []
        curr = head
        while curr:
            flattened.append(curr.val)
            curr = curr.next
        print(flattened)
        #return None


        def listToBST(lt: List[int]):
            if not lt:
                return None
            mid = len(lt)//2

            root = TreeNode(val=lt[mid])

            root.left = listToBST(lt[:mid])
            root.right = listToBST(lt[mid+1:])
            return root
        
        result = listToBST(flattened)

        return result