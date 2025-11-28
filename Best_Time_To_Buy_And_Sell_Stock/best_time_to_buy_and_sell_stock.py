class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        fast = 1
        minPrice = prices[0]
        profit = 0
        while (fast < n):
            if prices[fast] < minPrice:
                minPrice = prices[fast]

            elif prices[fast] - minPrice > profit:
                profit = prices[fast] - minPrice
        
            fast += 1
        return profit

