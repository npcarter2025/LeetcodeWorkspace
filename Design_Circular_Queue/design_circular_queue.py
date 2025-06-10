class Node:
    def __init__(self, val=None, prv=None, nxt=None):
        self.val = val
        self.prv = prv
        self.nxt = nxt

class MyCircularQueue:

    def __init__(self, k: int):
        
        self.capacity = k
        self.size = 0
        self.Sentinel = Node(None)
        self.Sentinel.nxt = self.Sentinel
        self.Sentinel.prv = self.Sentinel
        
    # we put new values at the rear. aka sentinel.prv
    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
            
        helperNode = self.Sentinel.prv


        newNode = Node(value)
        newNode.prv = helperNode
        newNode.nxt = self.Sentinel

        helperNode.nxt = newNode
        self.Sentinel.prv = newNode

        self.size += 1
        return True

    # we remove nodes from the front
    def deQueue(self) -> bool:
        if self.isEmpty():
            return False

        # helper node
        removeNode = self.Sentinel.nxt
        
        # assign sentinel to by pass this 

        self.Sentinel.nxt = removeNode.nxt
        removeNode.nxt.prv = self.Sentinel

        #Remove helper node's pointers
        removeNode.nxt = None
        removeNode.prv = None
        del(removeNode)
        
        self.size -= 1

        return True

    # front is the oldest
    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.Sentinel.nxt.val

    # rear is the newest
    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.Sentinel.prv.val

    def isEmpty(self) -> bool:
        
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()