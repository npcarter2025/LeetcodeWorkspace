from queue import PriorityQueue

# I just did this with a Max Heap because I'm practice DSA's

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        pq = PriorityQueue()
        for i in nums:
            pq.put(-i)


        return (-pq.get()-1) * (-pq.get()-1)   