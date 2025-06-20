# """
# This is the ImmutableListNode's API interface.
# You should not implement it, or speculate about its implementation.
# """
# class ImmutableListNode:
#     def printValue(self) -> None: # print the value of this node.
#     def getNext(self) -> 'ImmutableListNode': # return the next node.

class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        
        if not head:
            return None

        stack = []

        def recurse(head: 'ImmutableListNode'):
            if not head:
                return None

            stack.append(head)
            recurse(head.getNext())

            return None

        recurse(head)

        while len(stack) > 0:
            if stack is None:
                break
            tempNode = stack.pop()
            tempNode.printValue()
        
        return None