class Solution:
    def fib(self, n: int) -> int:


        # SIMPLE RECURSION

        # if n == 1:
        #     return 1
        # if n < 1:
        #     return 0
        # return self.fib(n - 1) + self.fib(n - 2)


        #RECURSION WITH MEMOIZATION

        memory = {}
        def fb(num):
            if num == 1:
                return 1
            if num < 1:
                return 0
            if num in memory:
                return memory[num]
            
            memory[num] = fb(num-1) + fb(num-2)
            return memory[num]
        
        return fb(n)