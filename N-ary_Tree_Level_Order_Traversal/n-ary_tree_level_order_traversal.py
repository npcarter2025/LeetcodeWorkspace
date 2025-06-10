"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""
from collections import deque
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        
        queue = deque([root])
        result = []

        while queue:
            level = []
            for elem in range(len(queue)):
                
                temp = queue.popleft()
                level.append(temp.val)               
                if temp.children:
                    queue.extend(temp.children) 
            result.append(level)
        return result


        