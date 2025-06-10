class Node:
    def __init__(self, val=None, nxt=None, prv=None):
        self.val = val
        self.nxt = nxt
        self.prv = prv

class MyCircularDeque:
    def __init__(self, k: int):
        self.Sentinel = Node()
        self.capacity = k
        self.size = 0
        self.Sentinel.nxt = self.Sentinel
        self.Sentinel.prv = self.Sentinel
        
        # I'm going to assign front as being next 
        # sounds good in my head
    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        tempNode = self.Sentinel.nxt

        #attach new Node
        newNode = Node(value)
        newNode.prv = self.Sentinel
        newNode.nxt = tempNode

        #Clean up original pointers
        self.Sentinel.nxt = newNode
        tempNode.prv = newNode
        self.size += 1
        return True


    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        
        tempNode = self.Sentinel.prv
        #create new node and attach ptrs
        newNode = Node(value)
        newNode.prv = tempNode
        newNode.nxt = self.Sentinel

        #clean up original ptrs
        self.Sentinel.prv = newNode
        tempNode.nxt = newNode

        self.size += 1
        return True


    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False

        tempNode = self.Sentinel.nxt.nxt
        deleteNode = self.Sentinel.nxt

        #attach tempNode to sentinel
        self.Sentinel.nxt = tempNode
        tempNode.prv = self.Sentinel

        #remove deleteNode's ptrs
        deleteNode.nxt = None
        deleteNode.prv = None

        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False

        tempNode = self.Sentinel.prv.prv
        deleteNode = self.Sentinel.prv

        self.Sentinel.prv = tempNode
        tempNode.nxt = self.Sentinel

        #remove deleteNode's ptrs
        deleteNode.nxt = None
        deleteNode.prv = None

        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.Sentinel.nxt.val

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.Sentinel.prv.val

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()