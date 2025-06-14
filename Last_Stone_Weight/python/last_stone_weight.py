from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        #stones = sorted(stones)
        while len(stones) >= 2:
            stones = sorted(stones)
            print(stones)
            length = len(stones)
            x = stones[length-1]
            y = stones[length-2]
            print(x)
            print(y)
            if stones[length-1] == stones[length-2]:
                #stones = stones[:2]
                stones.pop()
                stones.pop()
            else:
                stones[length-1] = stones[length-1] - stones[length-2]
                stones.pop((length-2))
            

        if len(stones) == 0:
            return 0
        
        return stones[0]