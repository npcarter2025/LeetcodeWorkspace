class Solution:
    def climbStairs(self, n: int) -> int:
        # if n == 0:
        #     return 1
        # if n < 0:
        #     return 0
        # return self.climbStairs(n-1) + self.climbStairs(n-2)
        # Time Limit Exceed. Need to try a different method :/ 
        

        # We can optimize by abstracting away the blind recursive calls
        # We can add a hashmap to "memoize" the process, thereby saving
        # the amount of computation time
        memo = {}

        def dp(k):
            if k == 0:
                return 1
            if k < 0:
                return 0
            if k in memo:
                return memo[k]

            memo[k] = dp(k - 1) + dp(k - 2)
            return memo[k]

        return dp(n)