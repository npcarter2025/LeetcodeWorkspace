# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:     
        if not root:
            return []
        queue = deque([root])
        result = []
        while queue:
            level = []
            for elem in range(len(queue)):

                temp = queue.popleft()
                level.append(temp.val)
                if temp.left:
                    queue.append(temp.left)
                if temp.right:
                    queue.append(temp.right)

            result.append(level)
        print(result)
        return result