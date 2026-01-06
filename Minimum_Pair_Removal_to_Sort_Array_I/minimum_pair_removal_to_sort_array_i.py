
# COMPLETE UN-OPTIMIZED 1st Attempt Brute Force


class Solution:


    def minimumPairRemoval(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        
        #Example [5,2,3,1]
        # [5,2,4]
        # [5,6]
        #
        # [5,1,7] -> [6,7]


        # [2,-100,105]
        # [-98, 105]


        # [1,2,3,-100]
        # Steps: check if it Decreases at all
        # 
        # adjacent = []
        moves = 0
        while (self.check_order(nums) == False): # and moves < 5 ):
            # calculate adjacency list

            min_val = float('inf')
            for i in range(1, len(nums)):
                value = nums[i]+nums[i-1]

                min_val = value if value < min_val else min_val

            moves += 1

            # search for indices in nums, and combine them

            curr = 1

            while (nums[curr]+nums[curr-1]!=min_val):
                curr += 1

            nums[curr-1] = min_val
            nums.pop(curr)
        return moves



    def check_order(self, nums) -> bool:

        curr = 1
        prev = 0
        while (curr < len(nums)):
            if nums[curr] < nums[prev]:
                return False
            curr += 1
            prev += 1
        return True


