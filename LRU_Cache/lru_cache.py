class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}

        # head = LRU, tail = MRU
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        

    def get(self, key: int) -> int:
        # if self.cache is empty, return -1
        if self.cache == {}:
            return -1

        if key in self.cache:
            # REMEMBER TO UPDATE POINTERS
            # remove it and insert at end of DLL
            node = self.cache[key]
            self.remove(node)
            self.insert(node)
            return node.value
  
        return -1


        #imagine we're changing the Node that is in the middle of a list.
        # Don't worry about head or that stuff. That's taken care of in the constructor
    def remove(self, node):
        prv = node.prev #identifying the Nodes' whose pointers we want to update
        nxt = node.next 
        prv.next = nxt
        nxt.prev = prv

    def insert(self, node):
        prv = self.tail.prev # identify the Nodes whose pointers we want to update
        nxt = self.tail
        
        prv.next = node
        nxt.prev = node
        
        node.prev = prv               
        node.next = nxt


    def put(self, key: int, value: int) -> None:
        
        if key in self.cache:
            self.remove(self.cache[key])
        
        new_node = Node(key, value)
        self.cache[key] = new_node
        self.insert(new_node)


        if len(self.cache) > self.capacity:
            lru = self.head.next
            self.remove(lru)
            del self.cache[lru.key]
            

 


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)