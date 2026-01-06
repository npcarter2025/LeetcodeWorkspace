from queue import PriorityQueue
#Non-optimized approach. I'm just doing problems that allow me to use Priority Queues to practice DSA's
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        pq = PriorityQueue()
        res = []
        for i in nums:
            pq.put(i)

        while not pq.empty():
            temp = pq.get()
            res.append(pq.get())
            res.append(temp)

        return res